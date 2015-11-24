#ifndef GUI_H
#define GUI_H
#include <QtWidgets/QMainWindow>
#include <Qt>
#include <QGraphicsView>
#include <QtWidgets/QToolBar>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <QFileDialog>
#include <QTextStream>

#include "Painter.h"

#include <iostream>
#include <string>
#include <sstream>

#include "GraphicsFactory.h"
#include "Graphics.h"
#include "DescriptionVisitor.h"

using namespace std;


class gui: public QMainWindow
{
    Q_OBJECT
    public:
        gui();
        virtual ~gui();
        QGraphicsView *graphicsView;
        QGraphicsScene *scene;
        QWidget *widget;

        void Display();
        void CreateView();
        void MessageBox(const QString _message);
        void CreateActions();
        void CreateMenus();
        void CreateToolbar();
        void SetActionConnection();


    protected:
    private:
        QAction *aboutDeveloper;
        QAction *openFile;
        QAction *saveFile;
        QAction *openFileBar;
        QAction *saveFileBar;
        QMenu *about;
        QMenu *file;
        QToolBar *toolbar;



    private slots:
        void MessageDialog();
        void FileOpenDialog();
        void FileSaveDialog();

    private:
        DescriptionVisitor descriptionVisitor;
        DrawVisitor drawVisitor;
        string fileContent;
        void drawGraphics(Graphics *graphics);
};

#endif // GUI_H
