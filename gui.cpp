#include "gui.moc"

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
}

void gui::CreateActions() {
        aboutDeveloper = new QAction("aboutDeveloper", widget);
}

void gui::CreateMenus() {
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
    std::string message("103598012\n");
    message += std::string("author:steven\n");
    QString qstr = QString::fromStdString(message);
    msgbox.setText(qstr);
    msgbox.exec();
}




