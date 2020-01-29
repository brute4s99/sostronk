#include "matchmake_test.h"
#include <QtDebug>

void MatchmakeTest::initTestCase()
{
    player1.first  = string("Pablo Diablo");
    player1.second = 200;
    player2.first  = string("Nicobar Escobar");
    player2.second = 150;
    player3.first  = string("brute4s99");
    player3.second = 400;
    player4.first  = string("orepoala");
    player4.second = 500;
    player5.first  = string("ryuzaki3");
    player5.second = 100;
    player6.first  = string("n00bmaster69");
    player6.second = 69;
    team1 = {   player1,
                player2
                };
    team2 = {   player3,
                player4
                };
    team3 = {   player5
                };
    team4 = {   player6
                };

    teamSize = 3;
    match1 = {pair<TEAM, int>({player1, player2, player5},0), pair<TEAM, int>({player3, player4, player6}, 0)};
    match2 = {pair<TEAM, int>({player1, player2, player6},0), pair<TEAM, int>({player3, player4, player5}, 0)};
    matches = {match1, match2};

    // Called before the first testfunction is executed
}


void MatchmakeTest::parseScoreTest()
{
    string test = "502";
    int score = parseScore(test);
    QCOMPARE(score, 502);
}

void MatchmakeTest::makeTeamsTest()
{
    vector< TEAM> teams, finalTeams;
    teams.push_back(team1);
    teams.push_back(team2);
    teams.push_back(team3);
    teams.push_back(team4);
    makeTeams(teams, finalTeams, teamSize);
    vector < PLAYER> team;
    team = {player1, player2, player5};
    QVERIFY(std::find(finalTeams.begin(), finalTeams.end(), team) != finalTeams.end());
    team = {player3, player4, player6};
    QVERIFY(std::find(finalTeams.begin(), finalTeams.end(), team) != finalTeams.end());
}


void MatchmakeTest::totalScoreTest()
{
    calculateTotalScore(matches);
    QCOMPARE((matches[0])[0].second, 450);
    QCOMPARE((matches[0])[1].second, 969);
    QCOMPARE((matches[1])[0].second, 419);
    QCOMPARE((matches[1])[1].second, 1000);
}


void MatchmakeTest::compareMatchesTest()
{
    QCOMPARE(compareMatches(matches[0], matches[1]), true);
    QCOMPARE(compareMatches(matches[1], matches[0]), false);
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
