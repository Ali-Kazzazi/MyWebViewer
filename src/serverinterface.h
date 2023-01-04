#ifndef SERVERINTERFACE_H
#define SERVERINTERFACE_H

#include <QObject>
#include <QUrl>
#include <QWebSocket>

class ServerInterface : public QObject
{
    Q_OBJECT
public:
    ServerInterface(ServerInterface &other) = delete;
    void operator=(const ServerInterface &) = delete;

    static ServerInterface* instance();

    ~ServerInterface() override;

    QUrl httpUrl();


    QUrl http_url;
    QUrl MAP_url;



protected:
    explicit ServerInterface(QObject *parent = nullptr);

    // singleton instance of server interface
    static ServerInterface* server;

private:
    QWebSocket *m_webSocket;


signals:

};

#endif // SERVERINTERFACE_H
