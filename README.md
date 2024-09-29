# unit_test

Tämä on esimerkki yksikkötestauksesta käyttäen <b>QTest</b>-frameworkkiä.

## Sovellusprojekti

Varsinainen sovellus on nimeltään **MyApplication** ja siinä on luokka nimeltään **MyMath**, jossa funktio **calcSum**, joka palauttaa sille annetun kahden kokonaisluvun summan.

## Testiprojekti

Testiprojekti on nimeltään **TestMyApplication** ja siinä oleva luokka **Test_MyMath** testaa että, toimiiko funktio **calcSum** oikein.

### Testiprojektin luonti

<ol>
<li>Luo Qt-konsolisovellus</li>
<li>Lisää .pro tiedostoon rivi 
<pre>
QT += testlib
</pre></li>
<li>Muokkaa .pro-tiedoston SOURCES osio seuraavaksi
<pre>
SOURCES += \
    ../MyApplication/MyMath.cpp \
    test_mymath.cpp
</pre>
</li>
<li>Lisää projektin Source osioon tiedosto test_mymath.cpp ja siihen koodi:
<pre>
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

</pre>
</li>
<li>Poista main.cpp (tai kommentoi sen main funktio)</li>
<li>Suorita projekti</li>
<li>Kokeile muokata calcSum-funktiota, niin että se palauttaa virheellisen summan ja suorita projekti.</li>
</ol>