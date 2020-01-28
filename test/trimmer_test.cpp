#include "trimmer_test.h"
#include <QtDebug>

void TrimmerTest::initTestCase()
{
    // Called before the first testfunction is executed
}

void TrimmerTest::TheTest()
{
    std::string str1("  HELLO  ");
    QVERIFY(str1.compare("  HELLO  ") == 0);
    QCOMPARE(ltrim(str1), "HELLO  ");
    QCOMPARE(rtrim(str1), "  HELLO");
    QCOMPARE(trim(str1), "HELLO");   
}

void TrimmerTest::cleanupTestCase()
{
    // Called after the last testfunction was executed
}

void TrimmerTest::init()
{
    // Called before each testfunction is executed
}

void TrimmerTest::cleanup()
{
    // Called after every testfunction
}

QTEST_MAIN(TrimmerTest)

#include "trimmer_test.moc"
