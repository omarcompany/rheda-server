#include <QCoreApplication>
#include "servercore.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	ServerCore server;
	server.startServer();
	return a.exec();
}
