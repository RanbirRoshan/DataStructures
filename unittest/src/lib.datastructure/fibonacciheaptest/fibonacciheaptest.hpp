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
	//CPPUNIT_TEST(InsertTest);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void ConstructDistructTest();
	//void InsertTest();

private:
	FibonacciHeap *		testheapintmin;
	FibonacciHeap *		testheapstrmin;
	FibonacciHeap *		testheapintmax;
	FibonacciHeap *		testheapstrmax;
};

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(FibonacciHeapTest, "Fibonacci Heap");

#endif //FIBONACCI_HEAP_TEST_HPP
