#include <QFile>
#include <QSettings>

#include "serverinterface.h"

#define config "cfg.ini"






ServerInterface* ServerInterface::server = nullptr;

ServerInterface::ServerInterface(QObject *parent)
    : QObject{parent}
{

    QSettings settings(config, QSettings::IniFormat);

    int serverPort = settings.value("ServerPort").toInt();
    QString serverIP = settings.value("ServerIP").toString();

    http_url.setScheme("http");
    http_url.setHost(serverIP);
    http_url.setPort(serverPort);

    MAP_url.setUrl(http_url.url() + "/map");

    m_webSocket = new QWebSocket;



}


QUrl ServerInterface::httpUrl()
{
    return http_url;
}

ServerInterface* ServerInterface::instance()
{
    if (!server) {
        server = new ServerInterface();
    }
    return server ;
}

ServerInterface::~ServerInterface()
{
    m_webSocket->deleteLater();
}
