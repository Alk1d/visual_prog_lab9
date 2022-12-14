#include <QtTest>
#include "../objects/objects.h"
#include "qtestcase.h"
// add necessary includes here

class test_case : public QObject
{
    Q_OBJECT

public:
    test_case();
    ~test_case();

private slots:
    void test_sedan();
    void test_suv();
    void test_bus();
    void test_bicycle();
    void test_route();

};

test_case::test_case()
{

}

test_case::~test_case()
{

}

void test_case::test_sedan()
{
    Sedan sedan;
        QVERIFY(!sedan.drive(100));
        QCOMPARE(sedan.getFuelLevel(), 0.0);
        sedan.refuel();
        QCOMPARE(sedan.getFuelLevel(),40.0);
        QVERIFY(sedan.drive(100));
        QCOMPARE(sedan.getMileage(),100);
        QCOMPARE(sedan.getFuelLevel(),30.0);
        QVERIFY(!sedan.drive(500));
        QCOMPARE(sedan.getMileage(), 100);
        QCOMPARE(sedan.getFuelLevel(),30.0);
        sedan.refuel();
        QCOMPARE(sedan.getFuelLevel(),40);
        sedan.refuel();
        QVERIFY(sedan.drive(400));
}

void test_case::test_suv()
{
    Suv suv;
    suv.refuel();
    QVERIFY(suv.drive(100));
    QCOMPARE(suv.getFuelLevel(), 35);
    QCOMPARE(suv.getMileage(),100);
}

void test_case::test_bus()
{
    Bus bus;
    QVERIFY(!bus.drive(20));
    QCOMPARE(bus.getMileage(),0);
    bus.refuel();
    QVERIFY(bus.drive(100));
    QCOMPARE(bus.getFuelLevel(), 30);
}

void test_case::test_bicycle()
{
    Bicycle bicycle;
    QCOMPARE(bicycle.getFuelLevel(), 0);
    QCOMPARE(bicycle.getMileage(), 0);
    QVERIFY(bicycle.drive(30));
    bicycle.refuel();
    QCOMPARE(bicycle.getFuelLevel(), 0);
}

void test_case::test_route()
{
    Route route;
    RoutePoint point;
}
QTEST_APPLESS_MAIN(test_case)

#include "tst_test_case.moc"
