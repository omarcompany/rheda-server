#include "servercore.h"
#include <QString>
#include <QDebug>


#define PORTNUM 1272

ServerCore::ServerCore() {
// m_database = &DatabaseEngine::instance();
}

void ServerCore::startServer()
{
    if (this->listen(QHostAddress::Any, PORTNUM)) {
        qDebug() << "Listening in  process...";
    }
    else
        qDebug() << "Error listening!";
}

void ServerCore::incomingConnection(qintptr socketDescriptor) {
    //При подключение к серверу создаем сокет
    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::readyRead, this, &ServerCore::socketReady);
    connect(m_socket, &QTcpSocket::disconnected, this, &ServerCore::socketDisconnect);

    //Информация о клиенте
    addPendingConnection(m_socket);
    m_socket->setSocketDescriptor(socketDescriptor);
    qDebug() << "Socket number " << socketDescriptor << endl
             << "Client connectrd.";
    qDebug() << "Send client status CONNECTED.";

    // Сообщаем клиенту что он подключился
    m_socket->write("You are connected.");
}

void ServerCore::socketReady()
{
    if(m_socket->waitForConnected(1000)) {
        m_socket->waitForReadyRead(1000);

        // Читаем сообщение от клиента здесь
        QString m_data;
        m_data = m_socket->readAll ();

        qDebug() <<m_data;

        //        data.append(login);
        //        data.append(hashed);
        //        data.append(email);
        //        data.append(1);

    }
}

void ServerCore::socketDisconnect()
{
    qDebug() << "disconnected";
}
