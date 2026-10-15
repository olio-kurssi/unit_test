# unit_test

Tämä on esimerkki yksikkötestauksesta käyttäen <b>QTest</b>-frameworkkiä.

## Sovellusprojekti
Tee kansio unit_test ja sinne varsinainen sovellus nimeltään **MyApplication** ja siihen  luokka nimeltään **MyMath**, jossa funktio **calcSum**, joka palauttaa sille annetun kahden kokonaisluvun summan.

## Testiprojekti

Testiprojekti on nimeltään **TestMyApplication** ja sillä voi testata, että MyApplication projektin **calcSum** toimii oikein.

### Testiprojektin luonti

<ol>
<li>Luo C++ konsolisovellus nimeltään TestMyApplication kansioon unit_test</li>
<li>Muokkaa CMakeLists.txt tiedosto seuraavan laiseksi:
<pre>
cmake_minimum_required(VERSION 3.16)

project(TestMyApplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(main
    main.cpp
    ../MyApplication/MyMath.cpp
)

target_link_libraries(main PRIVATE Qt6::Test)

include(GNUInstallDirs)
install(TARGETS main
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

</pre></li>
<li>Muokkaa main.cpp seuraavanlaiseksi
<pre>
#include &lt;QtTest/QtTest&gt;
#include &lt;qcompare.h&gt;
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


#include "main.moc"
</pre>
</li>

</li>
<li>Suorita projekti</li>
<li>Kokeile muokata calcSum-funktiota, niin että se palauttaa virheellisen summan ja suorita projekti.</li>
</ol>