#include "Header.h"
#include <cppunit/ui/text/TestRunner.h>
//#include <cppunit/TestCase.h>
int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(DiskDataTestCase::suite());
	runner.run();
	return 0;
}