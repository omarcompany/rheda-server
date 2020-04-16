#ifndef DATABASEENGINE_H
#define DATABASEENGINE_H

#include <QObject>
#include <QSqlDatabase>

struct User;

class DatabaseEngine: public QObject
{
    Q_OBJECT

	DatabaseEngine();

public:
    void registerUser(const User &newUser);
    void removeUser(const User &user);

    static DatabaseEngine &instance();

private:
	void openDatabase();
	void closeDatabase();
	bool userExists(const User &user);
    void connectToDatabase();

    QSqlDatabase m_database;
};

#endif // DATABASEENGINE_H
