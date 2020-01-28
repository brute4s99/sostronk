#ifndef COMPARE_TEAMS_TEST_H
#define COMPARE_TEAMS_TEST_H

#include <QTest>
#include <src/compare_teams.h>

class CompareTeamsTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase();

    void TheTest();
    
    void cleanupTestCase();

    void init();
    void cleanup();
};

#endif 