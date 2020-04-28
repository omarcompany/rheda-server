#ifndef USER_H
#define USER_H

#include <QString>

struct User
{
    User() {}

	User(const QString &name, const QString &login, const QString &password, const QString &email)
	{
		this->name =name;
		this->login = login;
		this->password = password;
		this->email = email;
	}

	QString name;
	QString login;
	QString password;
	QString email;
};

#endif // USER_H
