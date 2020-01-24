#ifndef BOUNDARYTESTS_H
#define BOUNDARYTESTS_H

#include <QTest>

class BoundaryValueTest : public QObject
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
