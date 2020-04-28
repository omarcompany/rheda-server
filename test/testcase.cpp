#include <QtTest>
#include <QDebug>
#include <QTest>

#include "testcase.h"
#include "databaseengine.h"

static const int CHECK_TIME = 30;

TestCase::TestCase()
{
    m_database = &DatabaseEngine::instance();
}

TestCase::~TestCase()
{

}

void TestCase::addNewUser_test()
{
    qDebug() << "Starting test of DatabaseEngine class's methods";
    qDebug() << "Add new users: Ivan, Nikita, Alexey, Vova";

    m_database->addNewUser("Ivan", "Ivano", "qwerty", "ivan@email.com");
    m_database->addNewUser("Nikita", "Nikito", "qwerty", "nikita@email.com");
    m_database->addNewUser("Alexey", "Alexo", "qwerty", "alexey@email.com");
    m_database->addNewUser("Vova", "Vovo", "qwerty", "vova@email.com");

    qDebug() << "All users have been registered. After 30 seconds every user will be removed!";
    qDebug() << "Please, check database!";
    QTest::qSleep(1000 * CHECK_TIME);

    m_database->removeUser("Ivano", "ivan@email.com");
    m_database->removeUser("Nikito", "nikita@email.com");
    m_database->removeUser("Alexo", "alexey@email.com");
    m_database->removeUser("Vovo", "vova@email.com");

    qDebug() << "All users have been removed.";
    qDebug() << "Please, chek database again!";
    qDebug() << "End of DatabaseEngine class's methods test";
}
QTEST_APPLESS_MAIN(TestCase)
