#include "gui.moc"
#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
using namespace std;
gui::gui()
{
//    ctor
    CreateView();
    CreateActions();
    CreateMenus();
    CreateToolbar();
    SetActionConnection();
    QString title = "Sample";
    setWindowTitle(title);
    setMinimumSize(800, 600);
    //Display();
    //FileSaveDialog();
    //drawGraphics();

}

gui::~gui()
{
    delete widget;
    delete scene;
    //dtor
}

void gui::CreateView(){
    widget = new QWidget();//繪製painter item的物件
    setCentralWidget(widget);
    graphicsView = new QGraphicsView(widget);//要調整生成的位置
    QString gView = "graphicView";
    graphicsView->setObjectName(gView);

    scene = new QGraphicsScene();//管理painter item的物件
    graphicsView->setScene(scene);
    QVBoxLayout *layout = new QVBoxLayout;//呈現畫面
    layout->setMargin(0);
    layout->addWidget(graphicsView);
    widget->setLayout(layout);
}

void gui::SetActionConnection() {
    connect(aboutDeveloper, SIGNAL(triggered()), this, SLOT(MessageDialog()));
    connect(openFile, SIGNAL(triggered()), this, SLOT(FileOpenDialog()));
    connect(saveFile, SIGNAL(triggered()), this, SLOT(FileSaveDialog()));
    connect(openFileBar, SIGNAL(triggered()), this, SLOT(FileOpenDialog()));
    connect(saveFileBar, SIGNAL(triggered()), this, SLOT(FileSaveDialog()));
}

void gui::CreateActions() {
    aboutDeveloper = new QAction("aboutDeveloper", widget);
    openFile = new QAction("openFile", widget);
    saveFile = new QAction("saveFile", widget);
}

void gui::CreateMenus() {
     QPixmap openpix("img/openFile.png");
     QPixmap savepix("img/saveFile.png");

     file = menuBar()->addMenu("File");
     openFile = file->addAction(openpix,"openFile");
     saveFile = file->addAction(savepix,"saveFile");

     about = menuBar()->addMenu("About");
     about->addAction(aboutDeveloper);
}

void gui::CreateToolbar(){
    QPixmap openpix("img/openFile.png");
    QPixmap savepix("img/saveFile.png");

    toolbar = addToolBar("toolbar");
    openFileBar = toolbar->addAction(openpix,"openFile");
    saveFileBar = toolbar->addAction(savepix,"saveFile");
}
void gui::Display() {
    Painter *item = new Painter(100,100, 200, 100, widget);
    scene->addItem(item);
    scene->update();
}

void gui::MessageDialog() {
    QMessageBox msgbox;
    std::string message("102318120\n");
    message += std::string("author:Chang Ting-Jhih\n");
    QString qstr = QString::fromStdString(message);
    msgbox.setText(qstr);
    msgbox.exec();
}


void gui::FileOpenDialog(){
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                QDir::currentPath(),
                                                tr("Text files (*.txt);;All files (*.*)"));

    string filePath = fileName.toStdString();


    if(fileName.length()>4){
        std::replace( filePath.begin(), filePath.end(), '/', '\\');
        int found=filePath.find_first_of("\\");
        filePath.insert(found,"\\");

        scene->clear();//清除原有的場景

        GraphicsFactory graphicsFactory;
        Graphics *graphics=graphicsFactory.buildGraphicsFromFile(filePath.c_str());

        graphics->accept(descriptionVisitor);
        fileContent = descriptionVisitor.getDescription();
        drawGraphics(graphics);
    }
}

void gui::FileSaveDialog(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                           QDir::currentPath(),
                           tr("Text files (*.txt);;All files (*.*)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << fileContent.c_str();
}

void gui::drawGraphics(Graphics *graphics){
    //graphics->accept(descriptionVisitor);
    drawVisitor.setScene(scene);
    graphics->accept(drawVisitor);

    //delete graphicsFactory;
}

