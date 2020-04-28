#include <QtTest>
#include <QDebug>
#include <QTest>

#include "testcase.h"
#include "databaseengine.h"
#include "user.h"

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
    User ivan("Ivan", "Ivano", "qwerty", "ivan@email.com");
    User nikita("Nikita", "Nikito", "qwerty", "nikita@email.com");
    User alexey("Alexey", "Alexo", "qwerty", "alexey@email.com");
    User vova("Vova", "Vovo", "qwerty", "vova@email.com");

    qDebug() << "Starting test of DatabaseEngine class's methods";
    qDebug() << QString("Add new users: %1, %2, %3, %4")
                .arg(ivan.name).arg(nikita.name).arg(alexey.name).arg(vova.name);

    m_database->registerUser(ivan);
    m_database->registerUser(nikita);
    m_database->registerUser(alexey);
    m_database->registerUser(vova);

    qDebug() << QString("All users have been registered. "
                        "After %1 seconds every user will be removed!").arg(CHECK_TIME);
    qDebug() << "Please, check database!";
    QTest::qSleep(1000 * CHECK_TIME);

    m_database->removeUser(ivan);
    m_database->removeUser(nikita);
    m_database->removeUser(alexey);
    m_database->removeUser(vova);

    qDebug() << "All users have been removed.";
    qDebug() << "Please, check database again!";
    qDebug() << "End of DatabaseEngine class's methods test";
}
QTEST_APPLESS_MAIN(TestCase)
