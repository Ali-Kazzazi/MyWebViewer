#include <QtWidgets>
#include <QLabel>
#include <QWebEngineView>
#include <QDebug>
#include <QSettings>


#include "mainwindow.h"
#include "serverinterface.h"

#define config "cfg.ini"

MainWindow::MainWindow()
{

    createActions();
    createMenus();
    createToolbars();
    createStatusBar();
    createMdiArea();
    initialServerInterface();


    setWindowTitle(tr("Viewer"));
    setMinimumSize(160, 160);
    resize(1200, 720);

    loadSettings();
    initPages();




}

void MainWindow::loadSettings(){
    // check for settings file and create a default one if not exist
    QFile settingsFile(config);
    if (!settingsFile.exists()) {
        QMessageBox::StandardButton result = QMessageBox::question(this, tr("No Configuration file"),
                              tr("No configuration file %1 found, do you want to create a default one?").arg(config));
        if (result == QMessageBox::Yes) {
            QFile::copy(":/res/cfg.ini", config);
            QFile configFile(config);
            configFile.setPermissions(QFileDevice::ReadOther | QFileDevice::WriteOther);
        }
    }


}


void MainWindow::createMdiArea()
{
    m_mdiArea = new QMdiArea(this);
    setCentralWidget(m_mdiArea);

}

void MainWindow::homeClicked()
{

    QUrl pageUrl = m_serverInterface->MAP_url;

    emit sendUrlToOpenPage(pageUrl);



updateConnectionStatus(true, "Client is connected to the Server!");


}

void MainWindow::openPage(QUrl url)
{

    view = new QWebEngineView();
    view->load(url);
    QMdiSubWindow *subWindow = new QMdiSubWindow;
     subWindow->setWidget(view);
     subWindow->setAttribute(Qt::WA_DeleteOnClose);
     m_mdiArea->addSubWindow(subWindow);
     subWindow->show();
     view->showMaximized();

}


void MainWindow::createActions()
{

    homeAct = new QAction(QIcon(":/res/home96.svg"), tr("&Home"), this);
    homeAct->setShortcuts(QKeySequence::New);
    connect(homeAct, &QAction::triggered, this, &MainWindow::homeClicked);

}

void MainWindow::createMenus()
{

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(homeAct);


}

void MainWindow::createToolbars(){


    // creating main toolbar items
    const QSize toolbarIconSize(48, 48);
    const int toolbarFixedHeight = 75;

    m_mainToolBar = addToolBar(tr("Main ToolBar"));
    m_mainToolBar->addAction(homeAct);
    m_mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_mainToolBar->setIconSize(toolbarIconSize);
    m_mainToolBar->setFixedHeight(toolbarFixedHeight);

}

void MainWindow::createStatusBar()
{
    m_statusBarMsg = new QLabel(tr("Ready"), this);
    statusBar()->addWidget(m_statusBarMsg, 1);

    m_userStatus = new QLabel(this);
    m_userStatus->setFrameStyle(QFrame::Sunken | QFrame::Panel);
    m_userStatus->setMinimumWidth(100);
    statusBar()->addPermanentWidget(m_userStatus);

    m_connectionStatus = new QLabel(this);
    m_connectionStatus->setStatusTip(tr("Connectivity Status"));
    m_connectionStatus->setMaximumSize(16, 16);
    m_connectionStatus->setScaledContents(true);
    m_connectedPix.load(":/res/wifion.svg");
    m_disconnectedPix.load(":/res/wifioff.svg");
    updateConnectionStatus(false, "Client is not connected to the Server!");
    statusBar()->addPermanentWidget(m_connectionStatus);
}

void MainWindow::updateConnectionStatus(bool isConnected, const QString &statusText)
{
    m_connectionStatus->setPixmap(isConnected ? m_connectedPix : m_disconnectedPix);
    m_connectionStatus->setToolTip(isConnected ? tr("Client is Connected to the Server")
                                               : statusText);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F5)
        if(!m_mdiArea->subWindowList().empty()){
            auto* activeView= dynamic_cast<QWebEngineView*>(m_mdiArea->activeSubWindow()->widget());
            if(activeView)
                activeView->reload();
        }

    QMainWindow::keyPressEvent(event);


}

void MainWindow::initialServerInterface()
{
    m_serverInterface = ServerInterface::instance();
}

void MainWindow::initPages()
{
    connect(this, &MainWindow::sendUrlToOpenPage, this, &MainWindow::openPage);

}


