#ifndef SERVERCORE_H
#define SERVERCORE_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include "databaseengine.h"

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
//    DatabaseEngine *m_database;
};

#endif // SERVERCORE_H
