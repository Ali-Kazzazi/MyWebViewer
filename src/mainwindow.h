#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <QWebEngineView>



class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QMdiArea;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:

private slots:
    void homeClicked();

private:
    void createActions();
    void createMenus();
    void createToolbars();
    void createStatusBar();
    void updateConnectionStatus(bool isConnected, const QString &statusText);
    void createMdiArea();
    void subWindowChanged();


    QMenu *fileMenu;
    QActionGroup *alignmentGroup;
    QAction *homeAct;
    QToolBar *m_mainToolBar;

    QLabel *m_statusBarMsg;
    QLabel *m_userStatus;
    QLabel *m_connectionStatus;
    QPixmap m_connectedPix;
    QPixmap m_disconnectedPix;

    QMdiArea *m_mdiArea;
    QWebEngineView *m_currentView;
    QWebEngineView *view ;

};


#endif
