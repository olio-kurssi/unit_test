// test_mymath.cpp
#include <QtTest/QtTest>
#include <qcompare.h>
#include "../MyApplication/MyMath.h"

class TestMyMath : public QObject
{
    Q_OBJECT

private slots:
    void testPositiveNumbers();
    void testNegativeNumbers();
    void testMixedNumbers();
    void testWithZero();
    void testLargeNumbers();
};

// Testitapaus positiivisille luvuille
void TestMyMath::testPositiveNumbers()
{
    MyMath myMath;
    QCOMPARE(myMath.calcSum(5, 7), 12);
}

// Testitapaus negatiivisille luvuille
void TestMyMath::testNegativeNumbers()
{
    MyMath myMath;
    QCOMPARE(myMath.calcSum(-5, -7), -12);
}

// Testitapaus positiiviselle ja negatiiviselle luvulle
void TestMyMath::testMixedNumbers()
{
    MyMath myMath;
    QCOMPARE(myMath.calcSum(5, -7), -2);
}

// Testitapaukset nollalle
void TestMyMath::testWithZero()
{
    MyMath myMath;
    QCOMPARE(myMath.calcSum(0, 0), 0);
    QCOMPARE(myMath.calcSum(0, 5), 5);
    QCOMPARE(myMath.calcSum(7, 0), 7);
}

// Testitapaus suurille luvuille
void TestMyMath::testLargeNumbers()
{
    MyMath myMath;
    QCOMPARE(myMath.calcSum(1000000, 2000000), 3000000);
}

// Suoritetaan testit
QTEST_MAIN(TestMyMath)

#include "test_mymath.moc"
