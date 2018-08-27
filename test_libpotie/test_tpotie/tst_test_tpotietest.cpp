#include <QString>
#include <QtTest>

class Test_tpotieTest : public QObject
{
    Q_OBJECT

public:
    Test_tpotieTest();

private Q_SLOTS:
    void test_calc_ipotie_data();
    void test_calc_ipotie();
};

Test_tpotieTest::Test_tpotieTest()
{
}

void Test_tpotieTest::test_calc_ipotie_data()
{
    QTest::addColumn<QString>("data");
    QTest::newRow("0") << QString();
}

void Test_tpotieTest::test_calc_ipotie()
{
    QFETCH(QString, data);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Test_tpotieTest)

#include "tst_test_tpotietest.moc"
