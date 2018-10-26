#include "binomialheaptest.h"
#include <cstdlib>
#include <climits>

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(BinomialHeapTest, "Binomial Heap");

static long long IntCmpFunc(const void * pCmpVal1, const void * pCmpVal2)
{
	__int64 *val1 = (__int64 *) pCmpVal1;
	__int64 *val2 = (__int64 *) pCmpVal2;

	if (*val1 > *val2)
		return 1;

	if (*val1 < *val2)
		return -1;

	return 0;
}

static long long StrCmpFunc(const void * pCmpVal1, const void * pCmpVal2)
{
	wchar_t * val1 = (wchar_t *) pCmpVal1;
	wchar_t * val2 = (wchar_t *)pCmpVal2;
	while (*val1 != *val2)
	{
		if (val1 == EOS)
			return 0;

		val1++;
		val2++;
	}

	return val1 - val2;
}


class BinomialHeapTestIntNode : public BinomialHeapNode {
	friend class BinomialHeapTest;
	__int64		uKey;
};

class BinomialHeapTestStrNode : public BinomialHeapNode {
	friend class BinomialHeapTest;
	wchar_t *		uKey;
};

void BinomialHeapTest::setUp()
{
	testheapintmin = new BinomialHeap(offsetof (BinomialHeapTestIntNode, uKey), IntCmpFunc, true);
	testheapstrmin = new BinomialHeap(offsetof (BinomialHeapTestStrNode, uKey), StrCmpFunc, true);
	testheapintmax = new BinomialHeap(offsetof(BinomialHeapTestIntNode, uKey), IntCmpFunc, false);
	testheapstrmax = new BinomialHeap(offsetof(BinomialHeapTestStrNode, uKey), StrCmpFunc, false);
}


void BinomialHeapTest::tearDown()
{
	//delete testheapintmin;
	//delete testheapstrmin;
	//delete testheapintmax;
	//delete testheapstrmax;
}


void BinomialHeapTest::InsertTest()
{
	BinomialHeapTestIntNode * intnodemin;
	BinomialHeapTestStrNode * strnodemin;
	BinomialHeapTestIntNode * intnodemax;
	BinomialHeapTestStrNode * strnodemax;
	BinomialHeapTestIntNode * intnodemin2;
	BinomialHeapTestIntNode * intnodemax2;
	BinomialHeapTestIntNode * tempint;
	BinomialHeapTestStrNode * tempstr;
	
	// insert one elemet and find it
	intnodemin = new BinomialHeapTestIntNode ();
	intnodemin->uKey = 100;
	testheapintmin->Insert(intnodemin);

	// insert one elemet and find it
	intnodemax = new BinomialHeapTestIntNode ();
	intnodemax->uKey = 100;
	testheapintmax->Insert(intnodemax);


	// testing insert single node in both min and max configuration
	CPPUNIT_ASSERT(intnodemin == testheapintmin->PeekMinMax());
	tempint = (BinomialHeapTestIntNode*) testheapintmin->RemoveMinMax();
	CPPUNIT_ASSERT(intnodemin == tempint);
	CPPUNIT_ASSERT(tempint->uKey == intnodemin->uKey);
	CPPUNIT_ASSERT(nullptr == testheapintmin->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	delete tempint;

	CPPUNIT_ASSERT(intnodemax == testheapintmax->PeekMinMax());
	tempint = (BinomialHeapTestIntNode*)testheapintmax->RemoveMinMax();
	CPPUNIT_ASSERT(intnodemax == tempint);
	CPPUNIT_ASSERT(tempint->uKey == intnodemax->uKey);
	CPPUNIT_ASSERT(nullptr == testheapintmax->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	delete tempint;

	strnodemin = (BinomialHeapTestStrNode*) new BinomialHeapTestIntNode();
	strnodemax = (BinomialHeapTestStrNode*) new BinomialHeapTestIntNode();

	strnodemin->uKey = L"abcd";
	testheapstrmin->Insert(strnodemin);
	strnodemax->uKey = L"aabc";
	testheapstrmax->Insert(strnodemax);

	CPPUNIT_ASSERT(strnodemin == testheapstrmin->PeekMinMax());
	tempstr = (BinomialHeapTestStrNode*)testheapstrmin->RemoveMinMax();
	CPPUNIT_ASSERT(_tcscmp (tempstr->uKey, strnodemin->uKey) == 0);
	CPPUNIT_ASSERT(tempstr->uKey == strnodemin->uKey);
	CPPUNIT_ASSERT(nullptr == testheapstrmin->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapstrmin->RemoveMinMax());

	delete tempstr;

	CPPUNIT_ASSERT(strnodemax == testheapstrmax->PeekMinMax());
	tempstr = (BinomialHeapTestStrNode*)testheapstrmax->RemoveMinMax();
	CPPUNIT_ASSERT(strnodemax == tempstr);
	CPPUNIT_ASSERT(tempstr->uKey == strnodemax->uKey);
	CPPUNIT_ASSERT(nullptr == testheapstrmax->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapstrmax->RemoveMinMax());
	
	delete tempstr;
	
	// running the same test with 2 inserts
	// insert one elemet and find it
	intnodemin = new BinomialHeapTestIntNode ();
	intnodemin->uKey = 100;
	testheapintmin->Insert(intnodemin);
	intnodemin2 = new BinomialHeapTestIntNode ();
	intnodemin2->uKey = 200;
	testheapintmin->Insert(intnodemin2);

	// insert one elemet and find it
	intnodemax = new BinomialHeapTestIntNode ();
	intnodemax->uKey = 100;
	testheapintmax->Insert(intnodemax);
	intnodemax2 = new BinomialHeapTestIntNode ();
	intnodemax2->uKey = 200;
	testheapintmax->Insert(intnodemax2);

	
	// testing insert single node in both min and max configuration
	CPPUNIT_ASSERT(intnodemin == testheapintmin->PeekMinMax());
	tempint = (BinomialHeapTestIntNode*)testheapintmin->RemoveMinMax();
	CPPUNIT_ASSERT(intnodemin == tempint);
	CPPUNIT_ASSERT(tempint->uKey == intnodemin->uKey);
	delete tempint;

	CPPUNIT_ASSERT(intnodemin2 == testheapintmin->PeekMinMax());
	
	tempint = (BinomialHeapTestIntNode*)testheapintmin->RemoveMinMax();
	CPPUNIT_ASSERT(intnodemin2 == tempint);
	CPPUNIT_ASSERT(tempint->uKey == intnodemin2->uKey);
	CPPUNIT_ASSERT(nullptr == testheapintmin->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	delete tempint;

	CPPUNIT_ASSERT(intnodemax2 == testheapintmax->PeekMinMax());
	tempint = (BinomialHeapTestIntNode*)testheapintmax->RemoveMinMax();
	CPPUNIT_ASSERT(intnodemax2 == tempint);
	CPPUNIT_ASSERT(tempint->uKey == intnodemax2->uKey);

	delete tempint;

	CPPUNIT_ASSERT(intnodemax == testheapintmax->PeekMinMax());
	tempint = (BinomialHeapTestIntNode*)testheapintmax->RemoveMinMax();
	CPPUNIT_ASSERT(intnodemax == tempint);
	CPPUNIT_ASSERT(tempint->uKey == intnodemax->uKey);
	CPPUNIT_ASSERT(nullptr == testheapintmax->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	delete tempint;

	int iter;
	long long val = LLONG_MIN;

	// multi insert test
	for ( iter = 0; iter < 500; iter++){

		// insert one elemet and find it
		intnodemin = new BinomialHeapTestIntNode ();
		intnodemin->uKey = std::rand() * 10000000000;
		intnodemin->uKey *= (intnodemin->uKey & 1)?1:-1;
		testheapintmin->Insert(intnodemin);
	}

	while (testheapintmin->PeekMinMax ()) {
		iter--;
		tempint = (BinomialHeapTestIntNode*) testheapintmin->RemoveMinMax();

		if (tempint->uKey < val) {
			iter--;
		}

		CPPUNIT_ASSERT(tempint->uKey >= val);
		val = tempint->uKey;
		delete tempint;
	}

	CPPUNIT_ASSERT(iter == 0);
	// multi insert test
	for (iter = 0; iter < 500; iter++) {

		// insert one elemet and find it
		intnodemax = new BinomialHeapTestIntNode ();
		intnodemax->uKey = intnodemax->uKey;
		testheapintmax->Insert(intnodemax);
	}

	val = LLONG_MAX;

	while (testheapintmax->PeekMinMax()) {
		iter--;
		tempint = (BinomialHeapTestIntNode*)testheapintmax->RemoveMinMax();
		CPPUNIT_ASSERT(tempint->uKey <= val);
		val = tempint->uKey;
		delete tempint;
	}

	CPPUNIT_ASSERT(iter == 0);

	CPPUNIT_ASSERT(iter == 0);

}

void BinomialHeapTest::ConstructDistructTest()
{
	CPPUNIT_ASSERT(testheapintmin->RemoveMinMax() == nullptr);

	CPPUNIT_ASSERT(testheapintmin->PeekMinMax() == nullptr);

	testheapintmin->Destroy();

	CPPUNIT_ASSERT(testheapstrmax->RemoveMinMax() == nullptr);

	CPPUNIT_ASSERT(testheapstrmax->PeekMinMax() == nullptr);

	testheapstrmax->Destroy();
}