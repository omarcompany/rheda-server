#ifndef SERVERCORE_H
#define SERVERCORE_H

#include <QTcpServer>
#include <QTcpSocket>

class ServerCore : public QTcpServer
{
	Q_OBJECT

public:
	ServerCore();

public slots:
	void startServer();
	void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void socketReady();
    void socketDisconnect();

private:
	QTcpSocket *m_socket;

};

#endif // SERVERCORE_H
