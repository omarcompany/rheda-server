#include <QtTest>
#include <QDebug>
#include <QTest>

#include "testcase.h"
#include "databaseengine.h"

const int CHECK_TIME = 30;

TestCase::TestCase()
{
	m_database = &DatabaseEngine::instance();
}

TestCase::~TestCase()
{

}

void TestCase::addNewUser_test()
{
	QWARN("Starting test of DatabaseEngine class's methods");
	QWARN("Add new users: Ivan, Nikita, Alexey, Vova");

	m_database->addNewUser("Ivan", "Ivano", "qwerty", "ivan@email.com");
	m_database->addNewUser("Nikita", "Nikito", "qwerty", "nikita@email.com");
	m_database->addNewUser("Alexey", "Alexo", "qwerty", "alexey@email.com");
	m_database->addNewUser("Vova", "Vovo", "qwerty", "vova@email.com");

	QWARN("All users have been registered. After 30 seconds every user will be removed!");
	QWARN("Please, chek database!");
	QTest::qWait(1000 * CHECK_TIME);

	m_database->removeUser("Ivano", "ivan@email.com");
	m_database->removeUser("Nikito", "nikita@email.com");
	m_database->removeUser("Alexo", "alexey@email.com");
	m_database->removeUser("Vovo", "vova@email.com");

	QWARN("All users have been removed.");
	QWARN("Please, chek database again!");
	QWARN("End of DatabaseEngine class's methods test");
}
QTEST_APPLESS_MAIN(TestCase)
