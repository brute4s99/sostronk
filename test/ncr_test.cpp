#include "ncr_test.h"
#include <QtDebug>
void CombinationTest::initTestCase()
{
    // Called before the first testfunction is executed
}

void CombinationTest::TheTest()
{
    QCOMPARE(nCr(10, 5), 252);
    QCOMPARE(nCr(0, 0), 1);
    QCOMPARE(nCr(1, 1), 1);
    QCOMPARE(nCr(5, 10), 0);
    QCOMPARE(nCr(-1, -1), 0);
    // QCOMPARE(nCr(-5, -10), 0);
    
}

void CombinationTest::cleanupTestCase()
{
    // Called after the last testfunction was executed
}

void CombinationTest::init()
{
    // Called before each testfunction is executed
}

void CombinationTest::cleanup()
{
    // Called after every testfunction
}

QTEST_MAIN(CombinationTest)
#include "ncr_test.moc"