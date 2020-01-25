#ifndef MATCHMAKE_TEST_H
#define MATCHMAKE_TEST_H

#include <QTest>
#include <core/matchmake.h>

class MatchmakeTest : public QObject
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