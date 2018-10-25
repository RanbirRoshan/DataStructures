#include <iostream>
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
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/XmlOutputter.h>
#include <fstream>
//#include <cppunit/TestCase.h>

#include "lib.datastructure\datastructuretestsuite.h"

using namespace std;
using namespace CppUnit;

int main(int argc, char **argv)
{
	/*// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;

	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);

	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);


	CppUnit::TestSuite *rootSuite = new CppUnit::TestSuite("All tests");
	rootSuite->addTest(CppUnit::TestFactoryRegistry::getRegistry("Data Structure").makeTest());
	CppUnit::TestFactoryRegistry::getRegistry().addTestToSuite(rootSuite);

	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TextUi::TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);

	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cout);
	compileroutputter.write();

	// Output XML for Jenkins CPPunit plugin
	ofstream xmlFileOut("cppTestResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;

	CppUnit::TestSuite *rootSuite = new CppUnit::TestSuite("All tests");
	rootSuite->addTest(CppUnit::TestFactoryRegistry::getRegistry("Data Structure").makeTest());
	CppUnit::TestFactoryRegistry::getRegistry().addTestToSuite(rootSuite);
	*/

	CppUnit::TextUi::TestRunner runner;
	//runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry("Binomial Heap").makeTest());
	runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry("Fibonacci Heap").makeTest());
	runner.run();
	return 0;
}