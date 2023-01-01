#include <QtWidgets>
#include <QLabel>
#include <QWebEngineView>
#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow()
{

    createActions();
    createMenus();
    createToolbars();
    createStatusBar();
    createMdiArea();


    setWindowTitle(tr("Viewer"));
    setMinimumSize(160, 160);
    resize(852, 480);

//    connect(m_mdiArea, &QMdiArea::subWindowActivated, this, &MainWindow::subWindowChanged);

}

void MainWindow::subWindowChanged() {
    // prevent zoom in and zoom out actions from being active when no subwindow is active
//    bool isWindowActive = !m_mdiArea->subWindowList().isEmpty();

//    if (isWindowActive && m_mdiArea->activeSubWindow()) {
//        m_currentView = dynamic_cast<QWebEngineView *>(m_mdiArea->activeSubWindow()->widget());
//    }
}

void MainWindow::createMdiArea()
{
    m_mdiArea = new QMdiArea(this);
    setCentralWidget(m_mdiArea);

}

void MainWindow::homeClicked()
{
    view = new QWebEngineView();
    QUrl url;
    url.setUrl(QString("https://www.google.com"));
    view->load(url);


    QMdiSubWindow *subWindow = new QMdiSubWindow(m_mdiArea);
    subWindow->setWidget(view);
    subWindow->show();


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



