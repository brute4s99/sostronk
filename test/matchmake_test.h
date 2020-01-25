#ifndef MATCHMAKE_TEST_H
#define MATCHMAKE_TEST_H

#include <QTest>
#include <core/matchmake.h>

class MatchmakeTest : public QObject
{
    PLAYER player1, player2, player3, player4, player5;
    TEAM team1, team2, team3;
    MATCH match1, match2, match3;
    vector< MATCH> matches;
    Q_OBJECT

private Q_SLOTS:
    void initTestCase();

    void totalScoreTest();
    void compareMatchesTest();
    void makeTeamsTest();
    void convertToStringTest();
    void parseScoreTest();
    void parseNameTest();

    void cleanupTestCase();

    void init();
    void cleanup();
};

#endif