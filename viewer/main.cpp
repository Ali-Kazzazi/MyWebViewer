#include "mainwindow.h"
#include "DarkStyle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // sets the dark style theme for default OS
    QApplication::setStyle(new DarkStyle);
    // sets the theme name for X11 environment
    QIcon::setThemeName("breeze-dark");
    // sets the fallback icon repository to the internal icons if OS didn't have theming
    QIcon::setFallbackSearchPaths(QIcon::fallbackSearchPaths() << ":res");
    MainWindow w;
    w.show();
    return a.exec();
}
