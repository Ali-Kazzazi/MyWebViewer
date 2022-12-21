#include "mainwindow.h"

#include <QDesktopServices>
#include <QMenuBar>
#include <QMenu>
#include <QUrl>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMdiArea();
    createActions();



}

MainWindow::~MainWindow()
{

}

void MainWindow::createMdiArea()
{
    m_mdiArea = new QMdiArea(this);
    //m_mdiArea->setViewMode(QMdiArea::TabbedView);
    setCentralWidget(m_mdiArea);

}


void MainWindow::createActions()
{

}

void MainWindow::createMenus()
{


}


