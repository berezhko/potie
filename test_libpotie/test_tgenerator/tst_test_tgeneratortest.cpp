#include <QString>
#include <QtTest>
#include "tgenerator.h"


class Test_tgeneratorTest : public QObject
{
    Q_OBJECT

public:
    Test_tgeneratorTest();
    ~Test_tgeneratorTest();

private Q_SLOTS:
    void test_calc_iu();
    void test_calc_xad();
private:
    TGenerator *gen;
};

Test_tgeneratorTest::Test_tgeneratorTest()
{
    gen = new TGenerator(0.8, 0.18);
    gen->addPointToXXX(0, 0);
    gen->addPointToXXX(0.220, 0.8);
    gen->addPointToXXX(0.260, 0.9);
    gen->addPointToXXX(0.310, 1.0);
    gen->addPointToXXX(0.395, 1.1);
    gen->addPointToXXX(0.525, 1.2);
    gen->addPointToXXX(0.809, 1.3);
    gen->addPointToXXX(1.500, 1.5);
}

Test_tgeneratorTest::~Test_tgeneratorTest()
{
    delete gen;
}

void Test_tgeneratorTest::test_calc_iu()
{
    double epotie = 1.0;
    double iu = gen->getIu(epotie);
    QVERIFY2(qFuzzyCompare(iu, 0.15), "Failure Iu not equal 0.15");
}

void Test_tgeneratorTest::test_calc_xad()
{
    double xad = gen->getXad();
    QVERIFY2(qFuzzyCompare(xad, 0.6628046), "Failure Xd not equal 0.6");
}

QTEST_APPLESS_MAIN(Test_tgeneratorTest)

#include "tst_test_tgeneratortest.moc"
