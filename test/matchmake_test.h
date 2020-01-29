#ifndef MATCHMAKE_TEST_H
#define MATCHMAKE_TEST_H

#include <QTest>
#include <src/matchmake.h>

class MatchmakeTest : public QObject
{
    PLAYER player1, player2, player3, player4, player5, player6;
    TEAM team1, team2, team3, team4;
    MATCH match1, match2;
    vector< MATCH> matches;
    int teamSize;
    Q_OBJECT

private Q_SLOTS:
    void initTestCase();

    void parseScoreTest();
    void makeTeamsTest();
    void totalScoreTest();
    void compareMatchesTest();

    void cleanupTestCase();
    void init();
    void cleanup();
};

#endif