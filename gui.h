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
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <QFileDialog>

#include "Painter.h"

#include <iostream>
#include <string>
#include <sstream>

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
        void SetActionConnection();
        

    protected:
    private:
        QAction *aboutDeveloper;
        QAction *loadFile;
        QAction *saveFile;
        QMenu *about;
        QMenu *file;
    private slots:
        void MessageDialog();
        void FileOpenDialog();
};

#endif // GUI_H
