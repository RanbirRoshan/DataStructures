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
	CPPUNIT_TEST(RemoveTest);
	CPPUNIT_TEST(RemoveNonRootTest);
	CPPUNIT_TEST(RemoveTwoNonRootTest);
	CPPUNIT_TEST(IncreaseKeyTest);
	CPPUNIT_TEST(IncreaseKeyNonRootLessThanParentAndRootTest);
	CPPUNIT_TEST(IncreaseKeyNonRootMoreThanRootTest);
	CPPUNIT_TEST(IncreaseKeyTwoNonRootMoreThanRootTest);
	CPPUNIT_TEST(DecreaseKeyTest);
	CPPUNIT_TEST(DecreaseKeyNonRootMoreThanRootTest);
	CPPUNIT_TEST(DecreaseKeyTwoNonRootMoreThanRootTest);
	CPPUNIT_TEST(DecreaseKeyNonRootLessThanParentAndRootTest);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void ConstructDistructTest ();
	void RemoveTest();
	void DecreaseKeyTest();
	void DecreaseKeyNonRootMoreThanRootTest();
	void DecreaseKeyTwoNonRootMoreThanRootTest();
	void DecreaseKeyNonRootLessThanParentAndRootTest();
	void IncreaseKeyTest();
	void IncreaseKeyNonRootMoreThanRootTest();
	void IncreaseKeyTwoNonRootMoreThanRootTest();
	void IncreaseKeyNonRootLessThanParentAndRootTest();
	void RemoveNonRootTest();
	void RemoveTwoNonRootTest();
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
