#include <QtTest>
#include "D:/Qt source/visual_prog_lab9_V3/objects/objects.h"
// add necessary includes here

class test_case : public QObject
{
    Q_OBJECT

public:
    test_case();
    ~test_case();

private slots:
    void test_case1();

};

test_case::test_case()
{

}

test_case::~test_case()
{

}

void test_case::test_case1()
{
    Sedan sedan;
        QVERIFY(!sedan.drive(100));
        QCOMPARE(sedan.getFuelLevel(), 0.0);
        sedan.refuel();
        QCOMPARE(sedan.getFuelLevel(),50.0);
        QVERIFY(sedan.drive(100));
        QCOMPARE(sedan.getMilage(),100);
        QCOMPARE(sedan.getFuelLevel(),43.0);
        QVERIFY(!sedan.drive(500));
        QCOMPARE(sedan.getMilage(), 250);
        QCOMPARE(sedan.getFuelLevel(),32.5);
        sedan.refuel();
        QCOMPARE(sedan.getFuelLevel(),50);
        QVERIFY(sedan.drive(500));
        QCOMPARE(sedan.getFuelLevel(),15.0);
}

QTEST_APPLESS_MAIN(test_case)

#include "tst_test_case.moc"
