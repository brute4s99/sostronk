#ifndef TRIMMERTEST_H
#define TRIMMERTEST_H

#include <QTest>
#include <src/trimmer.h>

class TrimmerTest : public QObject
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