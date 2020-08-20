#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "Biblioteca.h"

//-----------------------------------------------------------------------------

class TestGen : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestGen);
	CPPUNIT_TEST(testA);
	CPPUNIT_TEST(testB);
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp(void);
		void tearDown(void);

	protected:
		void testA(void);
		void testB(void);

	private:
		Biblioteca *mTestObj;
};

//-----------------------------------------------------------------------------

void TestGen::testA(void)
{
    CPPUNIT_ASSERT(5 == mTestObj->A(2,3));
}

void TestGen::testB(void)
{
    CPPUNIT_ASSERT(6 == mTestObj->B(2,3));
}

void TestGen::setUp(void)
{
    mTestObj = new Biblioteca();
}

void TestGen::tearDown(void)
{
    delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION(TestGen);

int main(int argc, char* argv[])
{
    CPPUNIT_NS::TestResult testresult;

    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);

    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
