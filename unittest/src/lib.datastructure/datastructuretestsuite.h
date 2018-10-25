


#ifndef LIB_DATASTRUCTURE_TEST_SUITE

#define LIB_DATASTRUCTURE_TEST_SUITE

#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "binomialheaptest\binomialheaptest.h"
#include "fibonacciheaptest\fibonacciheaptest.hpp"

class DataStructureTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(DataStructureTest);
	//CPPUNIT_TEST_SUITE_ADD_TEST(CppUnit::TestFactoryRegistry::getRegistry("Binomial Heap").makeTest());
	CPPUNIT_TEST_SUITE_END();
public:
};

//CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(DataStructureTest, "Data Structure");

#endif // !LIB_DATASTRUCTURE_TEST_SUITE
