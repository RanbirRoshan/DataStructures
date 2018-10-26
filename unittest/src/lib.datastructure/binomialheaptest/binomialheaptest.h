#ifndef BINOMIAL_HEAP_TEST_HPP

#define BINOMIAL_HEAP_TEST_HPP

#include <cppunit/TestCase.h>
#include "../datastructuretestsuite.h"
#include <cppunit/extensions/HelperMacros.h>
#include "libdatastruct.h"

class BinomialHeapTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(BinomialHeapTest);
	CPPUNIT_TEST(ConstructDistructTest);
	CPPUNIT_TEST(InsertTest);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void ConstructDistructTest();
	void InsertTest();

private:
	BinomialHeap *		testheapintmin;
	BinomialHeap *		testheapstrmin;
	BinomialHeap *		testheapintmax;
	BinomialHeap *		testheapstrmax;
};

#endif
