#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <QAction>



class QMdiArea;
class QMenuBar;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void createMdiArea();
    void createActions();
    void createMenus();





    QMdiArea *m_mdiArea;


};
#endif // MAINWINDOW_H
