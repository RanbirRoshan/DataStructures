#ifndef FIBONACCI_HEAP_TEST_HPP

#define FIBONACCI_HEAP_TEST_HPP

#include <cppunit/TestCase.h>
#include "../datastructuretestsuite.h"
#include <cppunit/extensions/HelperMacros.h>
#include "libdatastruct.h"

class FibonacciHeapTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(FibonacciHeapTest);
	CPPUNIT_TEST(ConstructDistructTest);
	CPPUNIT_TEST(InsertTest);
	CPPUNIT_TEST(RemoveMinMaxSingleElementTest);
	CPPUNIT_TEST(RemoveMinMaxTwoElementTest);
	CPPUNIT_TEST(RemoveMinMaxThreeElementTest);
	CPPUNIT_TEST(RemoveMinMaxMultiInsertMultiDelTest);
	CPPUNIT_TEST(RandomInsertDelete);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void ConstructDistructTest ();
	void InsertTest ();
	void RemoveMinMaxSingleElementTest();
	void RemoveMinMaxTwoElementTest();
	void RemoveMinMaxThreeElementTest();
	void RemoveMinMaxMultiInsertMultiDelTest();
	void RandomInsertDelete();

private:
	FibonacciHeap *		testheapintmin;
	FibonacciHeap *		testheapstrmin;
	FibonacciHeap *		testheapintmax;
	FibonacciHeap *		testheapstrmax;
};

#endif //FIBONACCI_HEAP_TEST_HPP
