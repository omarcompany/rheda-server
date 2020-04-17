#include "databaseengine.h"

#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QDir>

static const QString DATABASE_HOSTNAME = "localhost";
static const QString DATABASE_NAME = "database";
static const QString TABLE_NAME = "users_table";
static const QString DATABASE_PATH = QDir::homePath() + "//Database//" + DATABASE_NAME;

DatabaseEngine::DatabaseEngine() {
    connectToDatabase();
}

void DatabaseEngine::connectToDatabase() {
    if (QFile::exists(DATABASE_PATH))
        openDatabase();
    else
        qDebug() << "Database not found";
}

void DatabaseEngine::addNewUser(const QString &userName, const QString &login,
                                const QString &password, const QString &email) {
    if (!userExists(login, email)) {
        QSqlQuery query;
        query.prepare(QString("INSERT INTO %1 (user_name, login, password, email) "
                              "VALUES (?, ?, ?, ?)").arg(TABLE_NAME));

        query.addBindValue(userName);
        query.addBindValue(login);
        query.addBindValue(password);
        query.addBindValue(email);


        if (!query.exec()) {
            qDebug() << "Error insert into " << TABLE_NAME;
            qDebug() << query.lastError().text();
        } else {
            createTableUser(login);
            qDebug() << "User has been registered.";
        }

    } else {
        qDebug() << "User already exists!";
    }
}

void DatabaseEngine::removeUser(const QString &login, const QString &email) {
    if (userExists(login, email)) {
        QSqlQuery query;
        if (query.exec(QString("DELETE FROM %1 WHERE login == '%2';").arg(TABLE_NAME).arg(login)) &&
            query.exec(QString("DROP TABLE "+login+";")))
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

void DatabaseEngine::closeDatabase() {
    if (m_database.isOpen())
        m_database.close();
}

bool DatabaseEngine::userExists(const QString &login, const QString &email) {
    QSqlQuery query;

    if (!query.exec(QString("SELECT * FROM %1;").arg(TABLE_NAME)))
        qDebug() << "Could not find table";

    while (query.next()) {
        QString currentLogin = query.value(1).toString();
        QString currentEmail = query.value(3).toString();

        if ((email == currentEmail) || (login == currentLogin))
            return true;
    }
    return false;
}

DatabaseEngine &DatabaseEngine::instance() {
    static DatabaseEngine database;
    return database;
}


void DatabaseEngine::addFriend(const QString &nameRoot, const QString &nameFriend) {
    QString status = QString("INSERT INTO %1  (information, contacts, messages) "
                                             "VALUES (:information, :contacts, :messages);").arg(nameRoot);
   QSqlQuery query;

    query.prepare(status);
    query.bindValue(":contacts",nameFriend);

    if (!query.exec()) {
        qDebug() << "contact not founde";
    } else {
        qDebug() << "Add "<<nameFriend;
    }
}

bool DatabaseEngine::verification(const QString &email, const QString &password) {
    QString status = "Select * From "+TABLE_NAME+" ;";
    QSqlQuery query;

    if (!query.exec(status)) {
        qDebug() << "Could not find table";
    }

    while (query.next()) {
        QString passwordTable = query.value(3).toString();
        QString emailTable = query.value(4).toString();

        if ((passwordTable == password) && (emailTable == email))  {
            qDebug() << "Conect";
            return true;
        }
    }
    qDebug() << "Could not find email and password";
    return false;
}

void DatabaseEngine::createTableUser(const  QString &login) {
    QString column1 = "information";
    QString column2 = "contacts";
    QString column3 = "messages";


    QString str = "CREATE TABLE " + login + " ( "
            + column1 +     " VARCHAR(15), "
            + column2 +     " VARCHAR(12), "
            + column3 +     " VARCHAR(12) "
                            ");";

    QSqlQuery query;

    if (!query.exec(str)) {
        qDebug() << "DataBase: error of create " << login;
        qDebug() << query.lastError().text();
    } else {
        qDebug() << "TableUser "<<login<<" Create";
    }
}


