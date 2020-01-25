#include "matchmake_test.h"
#include <QtDebug>

void MatchmakeTest::initTestCase()
{
    player1.first = string("Pablo Diablo");
    player1.second = 200;
    player2.first =string("Nicobar Escobar");
    player2.second = 150;
    player3.first = string("brute4s99");
    player3.second = 400;
    player4.first =string("orepoala");
    player4.second = 500;
    player5.first =string("ryuzaki3");
    player5.second = 100;
    team1={player1, player2};
    team2={player3, player4};
    team3={player2, player5};
    match1={pair<TEAM, int>(team1,0), pair<TEAM, int>(team2, 0)};
    match2={pair<TEAM, int>(team2,0), pair<TEAM, int>(team3, 0)};
    match3={pair<TEAM, int>(team3,0), pair<TEAM, int>(team1, 0)};
    matches={match1, match2, match3};

    // Called before the first testfunction is executed
}

void MatchmakeTest::totalScoreTest()
{
    calculateTotalScore(matches);
    QCOMPARE((matches[0])[0].second, 350);
    QCOMPARE((matches[0])[1].second, 900);
    QCOMPARE((matches[1])[0].second, 900);
    QCOMPARE((matches[1])[1].second, 250);
    QCOMPARE((matches[2])[0].second, 250);
    QCOMPARE((matches[2])[1].second, 350);
}

void MatchmakeTest::compareMatchesTest()
{
    QCOMPARE(compareMatches(matches[0], matches[1]), true);
    QCOMPARE(compareMatches(matches[0], matches[2]), false);
}

void MatchmakeTest::makeTeamsTest()
{
    vector< TEAM> teams;
    makeTeams(vector< PLAYER> {player1, player2, player3, player4, player5}, teams, 4);
    vector < PLAYER> team;
    team = {player2, player3, player4, player5};
    QVERIFY(std::find(teams.begin(), teams.end(), team) != teams.end());
    team = {player1, player2, player4, player5};
    QVERIFY(std::find(teams.begin(), teams.end(), team) != teams.end());
    team = {player1, player3, player4, player5};
    QVERIFY(std::find(teams.begin(), teams.end(), team) != teams.end());
}

void MatchmakeTest::convertToStringTest()
{
    char arr[] = "Hello There";
    QCOMPARE(typeid(convertToString(arr)) , typeid(string));
    QVERIFY(convertToString(arr).compare(string("Hello There")) == 0);
}

void MatchmakeTest::parseScoreTest()
{
    string test = "Alpha Charlie 502";
    int score = parseScore(test);
    QCOMPARE(score, 502);
}

void MatchmakeTest::parseNameTest()
{
    string test = "Alpha Charlie 502";
    string name = parseName(test);
    QCOMPARE(name, "Alpha Charlie");
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
