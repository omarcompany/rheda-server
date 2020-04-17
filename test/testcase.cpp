#include <QtTest>
#include <QDebug>
#include <QTest>

#include "testcase.h"
#include "databaseengine.h"

const int CHECK_TIME = 30;

TestCase::TestCase()
{
    qDebug() << "TestCase()";
    m_database = &DatabaseEngine::instance();
}

TestCase::~TestCase()
{

}

void TestCase::addNewUser_test()
{
    qDebug()<<"Starting test of DatabaseEngine class's methods";
    qDebug()<<"Add new users: Ivan, Nikita, Alexey, Vova";

    m_database->addNewUser("Ivan", "Ivano", "679090", "ivan@email.com");
    m_database->addNewUser("Nikita", "Nikito", "2323sdf", "nikita@email.com");
    m_database->addNewUser("Alexey", "Alexo", "qwsfty", "alexey@email.com");
    m_database->addNewUser("Vova", "Vovo", "qwerty", "vova@email.com");
}

void TestCase::verification_test() {
    qDebug()<<"connection attempt";
    QCOMPARE(m_database->verification("ivan@email.com","679090"),true);
    QCOMPARE(m_database->verification("nikita@email.com","2323sdf"),true);
    QCOMPARE(m_database->verification("alexey@email.com","qwsfty"),true);
    QCOMPARE(m_database->verification("vova@email.com","qwerty"),true);
}

void TestCase::addFriend_test() {
    qDebug()<<"add Friend";
    m_database->addFriend("Vovo","Alexo");
    m_database->addFriend("Vovo","Nikito");
    m_database->addFriend("Vovo","Ivano");
}

void TestCase::removeUser_test() {
    qDebug()<<"All users have been registered. After 30 seconds every user will be removed!";
    qDebug()<<"Please, chek database!";

    QTest::qSleep(1000 * CHECK_TIME);

    m_database->removeUser("Ivano", "ivan@email.com");
    m_database->removeUser("Nikito", "nikita@email.com");
    m_database->removeUser("Alexo", "alexey@email.com");
    m_database->removeUser("Vovo", "vova@email.com");

    qDebug()<<"All users have been removed.";
    qDebug()<<"Please, chek database again!";
    qDebug()<<"End of DatabaseEngine class's methods test";
}

QTEST_APPLESS_MAIN(TestCase);
