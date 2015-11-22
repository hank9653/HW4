#include "gui.moc"
#include <iostream>
#include <string>
using namespace std;
gui::gui()
{
//    ctor
    CreateView();
    CreateActions();
    CreateMenus();
    SetActionConnection();
    QString title = "Sample";
    setWindowTitle(title);
    setMinimumSize(800, 600);
    Display();

}

gui::~gui()
{
    delete widget;
    delete scene;
    //dtor
}

void gui::CreateView(){
    widget = new QWidget();//ø�spainter item������
    setCentralWidget(widget);
    graphicsView = new QGraphicsView(widget);//�n�վ�ͦ�����m
    QString gView = "graphicView";
    graphicsView->setObjectName(gView);

    scene = new QGraphicsScene();//�޲zpainter item������
    graphicsView->setScene(scene);
    QVBoxLayout *layout = new QVBoxLayout;//�e�{�e��
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
    QString filters("Text files (*.txt);;All files (*.*)");
    QString defaultFilter("Text files (*.txt)");

    /* Static method approach */
    /*QFileDialog::getSaveFileName(0, "Save file", QDir::currentPath(),
        filters, &defaultFilter);*/

    /* Direct object construction approach */
    /*QFileDialog fileDialog(0, "open file", QDir::currentPath(), filters);
    fileDialog.selectNameFilter(defaultFilter);
    if (fileDialog.exec()){
        string filename=fileDialog.selectedFiles();
                cout<<filename<<endl;

    }*/

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                QDir::currentPath(),
                                                tr("All files (*.*)"));


   /* QFile file( fileName);
    if ( file.open( QIODevice::ReadOnly ) ) {
        QTextStream stream( &file );
        QString line;
        int i = 1;
        while ( !stream.atEnd() ) {
            line = stream.readLine(); // line of text excluding '\n'
            printf( "%3d: %s\n", i++, line.latin1() );
            lines += line;
        }
        file.close();
    } }*/


}

