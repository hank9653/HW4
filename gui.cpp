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
    connect(loadFile, SIGNAL(triggered()), this, SLOT(FileOpenDialog()));
    connect(saveFile, SIGNAL(triggered()), this, SLOT(MessageDialog()));
}

void gui::CreateActions() {
        aboutDeveloper = new QAction("aboutDeveloper", widget);
        loadFile = new QAction("loadFile", widget);
        saveFile = new QAction("saveFile", widget);
}

void gui::CreateMenus() {

     file = menuBar()->addMenu("File");
     file->addAction(loadFile);
     file->addAction(saveFile);
     about = menuBar()->addMenu("About");
     about->addAction(aboutDeveloper);
}

void gui::CreateToolbar(){
    QPixmap newpix("img/openFile.jpg");
    QPixmap openpix("img/saveFile.jpg");

    toolbar = addToolBar("toolbar");
    //toolbar->addAction(loadFile);
    toolbar->addAction(QIcon(newpix), "loadFile");
    toolbar->addAction(QIcon(openpix), "loadFile");

    QAction *quit2 = toolbar->addAction(QIcon(newpix),
      "loadFile");
    connect(quit2, SIGNAL(triggered()), SLOT(FileOpenDialog()));
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
                                                tr("All files (*.*)"));

    string filePath = fileName.toStdString();


    if(fileName.length()>4){
        std::replace( filePath.begin(), filePath.end(), '/', '\\');
        int found=filePath.find_first_of("\\");
        filePath.insert(found,"\\");

        graphics=graphicsFactory.buildGraphicsFromFile(filePath.c_str());

        //fileContent
        drawGraphics();
       // GrawGraphics(dv.getDescription());
    }
}

void gui::FileSaveDialog(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                           QDir::currentPath(),
                           tr("All files (*.*)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "The magic number is: " << 49 << "\n";
}

void gui::drawGraphics(){
    //graphics->accept(descriptionVisitor);
    drawVisitor.setScene(scene);
    graphics->accept(drawVisitor);
}

