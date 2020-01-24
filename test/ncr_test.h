#ifndef NCRTEST_H
#define NCRTEST_H

#include <QTest>
#include <core/matchmake.h>

class CombinationTest : public QObject
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
