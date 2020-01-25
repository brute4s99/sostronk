#include "matchmake_test.h"
#include <QtDebug>
void MatchmakeTest::initTestCase()
{
    // Called before the first testfunction is executed
}

void MatchmakeTest::TheTest()
{
    PLAYER player1(std::string("Pablo Diablo"), 200);
    PLAYER player2(std::string("Nicobar Escobar"), 150);
    PLAYER player3(std::string("brute4s99"), 400);
    PLAYER player4(std::string("orepoala"), 500);
    PLAYER player5(std::string("ryuzaki3"), 100);
    TEAM team1{player1, player2};
    TEAM team2{player3, player4};
    TEAM team3{player2, player5};
    MATCH match1{pair<TEAM, int>(team1,0), pair<TEAM, int>(team2, 0)};
    MATCH match2{pair<TEAM, int>(team2,0), pair<TEAM, int>(team3, 0)};
    MATCH match3{pair<TEAM, int>(team3,0), pair<TEAM, int>(team1, 0)};
    vector< MATCH> matches{match1, match2, match3};

    calculateTotalScore(matches);
    QCOMPARE((matches[0])[0].second, 350);
    QCOMPARE((matches[0])[1].second, 900);
    QCOMPARE((matches[1])[0].second, 900);
    QCOMPARE((matches[1])[1].second, 250);
    QCOMPARE((matches[2])[0].second, 250);
    QCOMPARE((matches[2])[1].second, 350);
    QCOMPARE(compareMatches(matches[0], matches[1]), true);
    QCOMPARE(compareMatches(matches[0], matches[2]), false);

    vector< TEAM> teams;
    makeTeams(vector< PLAYER> {player1, player2, player3, player4, player5}, teams, 4);
    vector < PLAYER> team;
    team={player2, player3, player4, player5};
    QVERIFY(std::find(teams.begin(), teams.end(), team) != teams.end());
    team={player1, player2, player4, player5};
    QVERIFY(std::find(teams.begin(), teams.end(), team) != teams.end());
    team={player1, player3, player4, player5};
    QVERIFY(std::find(teams.begin(), teams.end(), team) != teams.end());

}

void MatchmakeTest::cleanupTestCase()
{
    // Called after the last testfunction was executed
}

void MatchmakeTest::init()
{
    // Called before each testfunction is executed
}

void MatchmakeTest::cleanup()
{
    // Called after every testfunction
}

QTEST_MAIN(MatchmakeTest)
#include "matchmake_test.moc"
