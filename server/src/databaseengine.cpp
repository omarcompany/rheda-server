#include "databaseengine.h"

#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QDir>

#include "user.h"

static const QString DATABASE_HOSTNAME = "localhost";
static const QString DATABASE_NAME = "database";
static const QString TABLE_NAME = "users_table";
static const QString DATABASE_PATH = QDir::homePath() + "/Database/" + DATABASE_NAME;

DatabaseEngine::DatabaseEngine()
{
    connectToDatabase();
}

void DatabaseEngine::connectToDatabase()
{
    if (QFile::exists(DATABASE_PATH))
        openDatabase();
    else
        qDebug() << "Database not found";
}

void DatabaseEngine::registerUser(const User &User)
{
    if (!userExists(User)) {
		QSqlQuery query;
		query.prepare(QString("INSERT INTO %1 (user_name, login, password, email) "
							  "VALUES (?, ?, ?, ?)").arg(TABLE_NAME));

        query.addBindValue(User.name);
        query.addBindValue(User.login);
        query.addBindValue(User.password);
        query.addBindValue(User.email);

		if (!query.exec()) {
			qDebug() << "Error insert into " << TABLE_NAME;
			qDebug() << query.lastError().text();
		}

		qDebug() << "User has been registered.";
	} else {
		qDebug() << "User already exists!";
    }
}

void DatabaseEngine::removeUser(const User &user)
{
	if (userExists(user)) {
		QSqlQuery query;
		if (query.exec(QString("DELETE FROM %1 WHERE login == '%2';").arg(TABLE_NAME).arg(user.login)))
			qDebug() << "User has been removed.";
		else
			qDebug() << query.lastError().text();
	} else {
		qDebug() << "User not found!";
    }
}

void DatabaseEngine::openDatabase() {
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setHostName(DATABASE_HOSTNAME);
    m_database.setDatabaseName(DATABASE_PATH);

    if (m_database.open())
        qDebug() << "Database has been opened.";
    else
        qDebug() << "Database open ERROR!";
}

void DatabaseEngine::closeDatabase()
{
    if (m_database.isOpen())
        m_database.close();
}

bool DatabaseEngine::userExists(const User &user)
{
    QSqlQuery query;

    if (!query.exec(QString("SELECT * FROM %1;").arg(TABLE_NAME)))
        qDebug() << "Could not find table";

    while (query.next()) {
        QString currentLogin = query.value(1).toString();
        QString currentEmail = query.value(3).toString();

		if ((user.email == currentEmail) || (user.login == currentLogin))
			return true;
	}
    return false;
}

DatabaseEngine &DatabaseEngine::instance()
{
    static DatabaseEngine database;
    return database;
}
