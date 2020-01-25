#include "compare_teams_test.h"
#include <QtDebug>
void CompareTeamsTest::initTestCase()
{
    // Called before the first testfunction is executed
}

void CompareTeamsTest::TheTest()
{
        PLAYER player1(std::string("Pablo Diablo"), 100);
        PLAYER player2(std::string("Nicobar Escobar"), 150);
        PLAYER player3(std::string("brute4s99"), 500);
        QVERIFY(compare(player1, player2) != 0);
        QVERIFY(compare(player2, player1) == 0);
        QVERIFY(compare(player3, player1) == 0);

        TEAM team1{player1, player2};
        TEAM team2{player1, player3};
        QCOMPARE(areDisjoint(team1, team2), false);
        TEAM team3{player2};
        QCOMPARE(areDisjoint(team3, team2), true);

        QVERIFY(player1 < player2);
        QVERIFY(player2 < player3);
}

void CompareTeamsTest::cleanupTestCase()
{
    // Called after the last testfunction was executed
}

void CompareTeamsTest::init()
{
    // Called before each testfunction is executed
}

void CompareTeamsTest::cleanup()
{
    // Called after every testfunction
}

QTEST_MAIN(CompareTeamsTest)
#include "compare_teams_test.moc"
