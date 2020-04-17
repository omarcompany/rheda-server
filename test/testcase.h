#ifndef TESTCASE_H
#define TESTCASE_H

#include <QObject>

class DatabaseEngine;

class TestCase : public QObject
{
    Q_OBJECT
public:
    TestCase();
    ~TestCase();

private slots:
    void addNewUser_test();
    void verification_test();
    void addFriend_test();
    void removeUser_test();
private:
    DatabaseEngine *m_database;
};

#endif // TESTCASE_H
