#ifndef DATABASEENGINE_H
#define DATABASEENGINE_H

#include <QObject>
#include <QSqlDatabase>


class DatabaseEngine: public QObject {
	Q_OBJECT

	DatabaseEngine();
	DatabaseEngine(const DatabaseEngine &database);
	DatabaseEngine &operator= (const DatabaseEngine &database);

public:
	void addNewUser(const QString &userName, const QString &login, const QString &password, const QString &email);
	void removeUser(const QString &login, const QString &email);
    void addFriend(const QString &nameRoot, const QString &nameFriend);
    bool verification(const QString &email, const QString &password);
	static DatabaseEngine &instance();

private:
	void openDatabase();
	void closeDatabase();
	bool userExists(const QString &login, const QString &email);
	void connectToDatabase();
    void createTableUser(const QString &name);         // Создание таблицы пользователя в базе данных
	QSqlDatabase m_database;
};

#endif // DATABASEENGINE_H
