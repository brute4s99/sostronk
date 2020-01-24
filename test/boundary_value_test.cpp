#include "boundary_value_test.h"
#include <core/main.h>

QTEST_GUILESS_MAIN(BoundaryValueTest);

void BoundaryValueTest::initTestCase()
{
    // Called before the first testfunction is executed
}

void BoundaryValueTest::TheTest()
{
    QCOMPARE( false & true, true );

}

void BoundaryValueTest::cleanupTestCase()
{
    // Called after the last testfunction was executed
}

void BoundaryValueTest::init()
{
    // Called before each testfunction is executed
}

void BoundaryValueTest::cleanup()
{
    // Called after every testfunction
}