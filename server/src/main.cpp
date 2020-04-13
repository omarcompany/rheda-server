#include <QCoreApplication>

#include "servercore.h"
#include "databaseengine.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	ServerCore server;
	server.startServer();
	return a.exec();
}
