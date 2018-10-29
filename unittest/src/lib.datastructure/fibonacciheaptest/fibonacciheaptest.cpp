
#include "fibonacciheaptest.hpp"


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(FibonacciHeapTest, "Fibonacci Heap");


static long long IntCmpFunc(const void * pCmpVal1, const void * pCmpVal2)
{
	__int64 *val1 = (__int64 *)pCmpVal1;
	__int64 *val2 = (__int64 *)pCmpVal2;

	if (*val1 > *val2)
		return 1;

	if (*val1 < *val2)
		return -1;

	return 0;
}

static long long StrCmpFunc(const void * pCmpVal1, const void * pCmpVal2)
{
	wchar_t * val1 = *(wchar_t **)pCmpVal1;
	wchar_t * val2 = *(wchar_t **)pCmpVal2;
	while (*val1 == *val2)
	{
		if (val1 == EOS)
			return 0;

		val1++;
		val2++;
	}

	return *val1 - *val2;
}

class FiboHeapTestIntNode : public FiboHeapNode {
	friend class FibonacciHeapTest;
	__int64		uKey;
};

class FiboHeapTestStrNode : public FiboHeapNode {
	friend class FibonacciHeapTest;
	wchar_t *		uKey;
};



void FibonacciHeapTest::setUp()
{
	testheapintmin = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, true);
	testheapstrmin = new FibonacciHeap(offsetof(FiboHeapTestStrNode, uKey), StrCmpFunc, true);
	testheapintmax = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, false);
	testheapstrmax = new FibonacciHeap(offsetof(FiboHeapTestStrNode, uKey), StrCmpFunc, false);
}

void FibonacciHeapTest::tearDown()
{
	delete testheapintmin;
	delete testheapstrmin;
	delete testheapintmax;
	delete testheapstrmax;
}

void FibonacciHeapTest::InsertTest()
{
	FiboHeapTestIntNode *  node1, * node2, *node3;
	FiboHeapTestStrNode *  node_a, *node_b;

	// strict increasing insertion test 100 200 300 on max heap

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 100;

	testheapintmax->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 200;

	testheapintmax->Insert(node2);

	CPPUNIT_ASSERT(node2 == testheapintmax->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 300;

	testheapintmax->Insert(node3);

	CPPUNIT_ASSERT(node3 == testheapintmax->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmax;

	testheapintmax = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, false);

	// strict decreasing insertion test 300 200 100 on max heap
	node1 = new FiboHeapTestIntNode();

	node1->uKey = 300;

	testheapintmax->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 200;

	testheapintmax->Insert(node2);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 100;

	testheapintmax->Insert(node3);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmax;

	// increasing decreasing insertion test 100 300 200 on max heap
	testheapintmax = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, false);

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 100;

	testheapintmax->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 300;

	testheapintmax->Insert(node2);

	CPPUNIT_ASSERT(node2 == testheapintmax->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 200;

	testheapintmax->Insert(node3);

	CPPUNIT_ASSERT(node2 == testheapintmax->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmax;

	testheapintmax = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, false);

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 100;

	testheapintmax->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 300;

	testheapintmax->Insert(node2);

	CPPUNIT_ASSERT(node2 == testheapintmax->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 50;

	testheapintmax->Insert(node3);

	CPPUNIT_ASSERT(node2 == testheapintmax->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmax;

	testheapintmax = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, false);

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 300;

	testheapintmax->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 100;

	testheapintmax->Insert(node2);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 200;

	testheapintmax->Insert(node3);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmax;

	testheapintmax = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, false);

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 200;

	testheapintmax->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 100;

	testheapintmax->Insert(node2);

	CPPUNIT_ASSERT(node1 == testheapintmax->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 300;

	testheapintmax->Insert(node3);

	CPPUNIT_ASSERT(node3 == testheapintmax->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmax;

	testheapintmax = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, false);

	// repeating the same for min heap

	// strict increasing insertion test 100 200 300 on max heap

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 100;

	testheapintmin->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 200;

	testheapintmin->Insert(node2);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 300;

	testheapintmin->Insert(node3);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmin;

	testheapintmin = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, true);

	// strict decreasing insertion test 300 200 100 on max heap
	node1 = new FiboHeapTestIntNode();

	node1->uKey = 300;

	testheapintmin->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 200;

	testheapintmin->Insert(node2);

	CPPUNIT_ASSERT(node2 == testheapintmin->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 100;

	testheapintmin->Insert(node3);

	CPPUNIT_ASSERT(node3 == testheapintmin->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmin;

	// increasing decreasing insertion test 100 300 200 on max heap
	testheapintmin = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, true);

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 100;

	testheapintmin->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 300;

	testheapintmin->Insert(node2);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 200;

	testheapintmin->Insert(node3);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmin;

	testheapintmin = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, true);

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 100;

	testheapintmin->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 300;

	testheapintmin->Insert(node2);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 50;

	testheapintmin->Insert(node3);

	CPPUNIT_ASSERT(node3 == testheapintmin->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmin;

	testheapintmin = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, true);

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 300;

	testheapintmin->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 100;

	testheapintmin->Insert(node2);

	CPPUNIT_ASSERT(node2 == testheapintmin->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 200;

	testheapintmin->Insert(node3);

	CPPUNIT_ASSERT(node2 == testheapintmin->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmin;

	testheapintmin = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, true);

	node1 = new FiboHeapTestIntNode();

	node1->uKey = 200;

	testheapintmin->Insert(node1);

	CPPUNIT_ASSERT(node1 == testheapintmin->PeekMinMax());

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 100;

	testheapintmin->Insert(node2);

	CPPUNIT_ASSERT(node2 == testheapintmin->PeekMinMax());

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 300;

	testheapintmin->Insert(node3);

	CPPUNIT_ASSERT(node2 == testheapintmin->PeekMinMax());

	delete node1;
	delete node2;
	delete node3;
	delete testheapintmin;

	testheapintmin = new FibonacciHeap(offsetof(FiboHeapTestIntNode, uKey), IntCmpFunc, true);

	//testing insert for other data type in our case char array

	node_a = new FiboHeapTestStrNode ();

	node_a->uKey = L"a";

	testheapstrmax->Insert(node_a);

	CPPUNIT_ASSERT(node_a == testheapstrmax->PeekMinMax());

	node_b = new FiboHeapTestStrNode();

	node_b->uKey = L"b";

	testheapstrmax->Insert(node_b);

	CPPUNIT_ASSERT(node_b == testheapstrmax->PeekMinMax());

	delete node_a;
	delete node_b;
	delete testheapstrmax;

	testheapstrmax = new FibonacciHeap(offsetof(FiboHeapTestStrNode, uKey), StrCmpFunc, false);

	node_a = new FiboHeapTestStrNode();

	node_a->uKey = L"ab";

	CPPUNIT_ASSERT(testheapstrmax->Insert(node_a) == node_a);

	CPPUNIT_ASSERT(node_a == testheapstrmax->PeekMinMax());

	node_b = new FiboHeapTestStrNode();

	node_b->uKey = L"aa";

	CPPUNIT_ASSERT(testheapstrmax->Insert(node_b) == node_b);

	CPPUNIT_ASSERT(node_a == testheapstrmax->PeekMinMax());

	CPPUNIT_ASSERT(testheapstrmax->Insert(node_a) == nullptr);

	delete node_a;
	delete node_b;

	CPPUNIT_ASSERT(testheapstrmax->Insert(nullptr) == nullptr);
}

void FibonacciHeapTest::ConstructDistructTest()
{
	CPPUNIT_ASSERT(nullptr == testheapintmax->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapintmin->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapstrmin->PeekMinMax());
	CPPUNIT_ASSERT(nullptr == testheapstrmax->PeekMinMax());
	
	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(nullptr == testheapstrmin->RemoveMinMax());
	CPPUNIT_ASSERT(nullptr == testheapstrmax->RemoveMinMax());

	CPPUNIT_ASSERT(false == testheapintmax->IsMinHeap());
	CPPUNIT_ASSERT(true  == testheapintmin->IsMinHeap());
	CPPUNIT_ASSERT(true  == testheapstrmin->IsMinHeap());
	CPPUNIT_ASSERT(false == testheapstrmax->IsMinHeap());
}

void FibonacciHeapTest::RemoveMinMaxSingleElementTest()
{
	FiboHeapTestIntNode  *node;

	node = new FiboHeapTestIntNode();

	node->uKey = 1000;

	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax ());

	CPPUNIT_ASSERT (node == testheapintmin->Insert(node));

	CPPUNIT_ASSERT(node == testheapintmin->RemoveMinMax ());
	
	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(node == testheapintmax->Insert(node));

	CPPUNIT_ASSERT(node == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	delete node;
}


void FibonacciHeapTest::RemoveMinMaxTwoElementTest()
{
	FiboHeapTestIntNode  *node, *node2;

	node = new FiboHeapTestIntNode();

	node->uKey = 100;

	node2 = new FiboHeapTestIntNode();

	node2->uKey = -100;

	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(node == testheapintmin->Insert(node));

	CPPUNIT_ASSERT(node2 == testheapintmin->Insert(node2));

	CPPUNIT_ASSERT(node2 == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(node == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	// testing max heap
	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(node == testheapintmax->Insert(node));
	CPPUNIT_ASSERT(node2 == testheapintmax->Insert(node2));

	CPPUNIT_ASSERT(node == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	delete node;
	delete node2;
}

void FibonacciHeapTest::RemoveMinMaxThreeElementTest()
{
	FiboHeapTestIntNode  *node, *node2, * node3;

	node = new FiboHeapTestIntNode();

	node->uKey = -100;

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 0;

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 100;

	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(node == testheapintmin->Insert(node));
	CPPUNIT_ASSERT(node2 == testheapintmin->Insert(node2));
	CPPUNIT_ASSERT(node3 == testheapintmin->Insert(node3));

	CPPUNIT_ASSERT(node == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(node3 == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	// testing max heap
	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(node == testheapintmax->Insert(node));
	CPPUNIT_ASSERT(node2 == testheapintmax->Insert(node2));
	CPPUNIT_ASSERT(node3 == testheapintmax->Insert(node3));

	CPPUNIT_ASSERT(node3 == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	/// testing for reverse order insertion

	CPPUNIT_ASSERT(node3 == testheapintmin->Insert(node3));
	CPPUNIT_ASSERT(node2 == testheapintmin->Insert(node2));
	CPPUNIT_ASSERT(node == testheapintmin->Insert(node));

	CPPUNIT_ASSERT(node == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(node3 == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	// testing max heap
	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(node3 == testheapintmax->Insert(node3));
	CPPUNIT_ASSERT(node2 == testheapintmax->Insert(node2));
	CPPUNIT_ASSERT(node == testheapintmax->Insert(node));

	CPPUNIT_ASSERT(node3 == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	//mixed order insertion with larger first

	CPPUNIT_ASSERT(node3 == testheapintmin->Insert(node3));
	CPPUNIT_ASSERT(node == testheapintmin->Insert(node));
	CPPUNIT_ASSERT(node2 == testheapintmin->Insert(node2));

	CPPUNIT_ASSERT(node == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(node3 == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	// testing max heap
	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(node3 == testheapintmax->Insert(node3));
	CPPUNIT_ASSERT(node == testheapintmax->Insert(node));
	CPPUNIT_ASSERT(node2 == testheapintmax->Insert(node2));

	CPPUNIT_ASSERT(node3 == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	// mixed order insertion with smaller first

	CPPUNIT_ASSERT(node2 == testheapintmin->Insert(node2));
	CPPUNIT_ASSERT(node == testheapintmin->Insert(node));
	CPPUNIT_ASSERT(node3 == testheapintmin->Insert(node3));

	CPPUNIT_ASSERT(node == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmin->RemoveMinMax());
	CPPUNIT_ASSERT(node3 == testheapintmin->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmin->RemoveMinMax());

	// testing max heap
	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(node2 == testheapintmax->Insert(node2));
	CPPUNIT_ASSERT(node == testheapintmax->Insert(node));
	CPPUNIT_ASSERT(node3 == testheapintmax->Insert(node3));

	CPPUNIT_ASSERT(node3 == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node2 == testheapintmax->RemoveMinMax());
	CPPUNIT_ASSERT(node == testheapintmax->RemoveMinMax());

	CPPUNIT_ASSERT(nullptr == testheapintmax->RemoveMinMax());

	delete node;
	delete node2;
	delete node3;
}

void FibonacciHeapTest::RemoveMinMaxMultiInsertMultiDelTest()
{
	FiboHeapTestIntNode *node;
	long long			 val;
	int					 iter;

	for (iter = 0; iter < 500; iter++)
	{
		node = new FiboHeapTestIntNode();
		node->uKey = std::rand() * 10000000000;
		node->uKey *= (node->uKey % 8) ? 1 : -1;
		testheapintmax->Insert(node);
	}

	val = LLONG_MAX;

	while (testheapintmax->PeekMinMax()) {
		iter--;
		node = (FiboHeapTestIntNode*)testheapintmax->RemoveMinMax();
		CPPUNIT_ASSERT(node->uKey <= val);
		val = node->uKey;
		delete node;
	}

	CPPUNIT_ASSERT(iter == 0);

	for (iter = 0; iter < 500; iter++)
	{
		node = new FiboHeapTestIntNode();
		node->uKey = std::rand() * 10000000000;
		node->uKey *= (node->uKey % 8) ? 1 : -1;
		testheapintmin->Insert(node);
	}

	val = LLONG_MIN;

	while (testheapintmin->PeekMinMax()) {
		iter--;
		node = (FiboHeapTestIntNode*)testheapintmin->RemoveMinMax();
		CPPUNIT_ASSERT(node->uKey >= val);
		val = node->uKey;
		delete node;
	}

	CPPUNIT_ASSERT(iter == 0);
}

void FibonacciHeapTest::RandomInsertDelete()
{

	FiboHeapTestIntNode *node;
	long long			 val;
	int					 iter;

	for (iter = 0; iter < 50; iter++)
	{
		node = new FiboHeapTestIntNode();
		node->uKey = std::rand() * 10000000000;
		node->uKey *= (node->uKey % 8) ? 1 : -1;
		testheapintmax->Insert(node);
	}

	val = LLONG_MAX;

	for (iter = 0; iter < 500; iter++)
	{
		for (int i = 0; i < iter % 5; i++)
		{
			node = (FiboHeapTestIntNode*)testheapintmax->RemoveMinMax();
			if (node) {
				CPPUNIT_ASSERT(node->uKey <= val);
				val = node->uKey;
				delete node;
			}
		}

		for (int i = 0; i < iter % 10; i++) {
			__int64 temp;
			node = new FiboHeapTestIntNode();
			node->uKey = std::rand() * 2;
			node->uKey *= (node->uKey % 8) ? 1 : -1;
			CPPUNIT_ASSERT(node == testheapintmax->Insert(node));
			temp = node->uKey;
			node = new FiboHeapTestIntNode();
			node->uKey = temp;
			CPPUNIT_ASSERT(node == testheapintmax->Insert(node));

			if (temp > val)
				val = temp;
		}
	}
}

void FibonacciHeapTest::RemoveTest()
{
	FiboHeapTestIntNode        *node, *node2, *node3;

	node = new FiboHeapTestIntNode();

	node->uKey = 100;

	CPPUNIT_ASSERT(node == testheapintmin->Insert(node));

	CPPUNIT_ASSERT(node == testheapintmin->Remove(node));

	CPPUNIT_ASSERT(nullptr == testheapintmin->PeekMinMax());

	//next test

	CPPUNIT_ASSERT(node == testheapintmin->Insert(node));

	node2 = new FiboHeapTestIntNode();

	node2->uKey = 200;

	CPPUNIT_ASSERT(node2 == testheapintmin->Insert(node2));

	CPPUNIT_ASSERT(node2 == testheapintmin->Remove(node2));

	CPPUNIT_ASSERT(node == testheapintmin->PeekMinMax());

	//next test

	CPPUNIT_ASSERT(node2 == testheapintmin->Insert(node2));

	CPPUNIT_ASSERT(node == testheapintmin->Remove(node));

	CPPUNIT_ASSERT(node2 == testheapintmin->PeekMinMax());

	//next test

	CPPUNIT_ASSERT(node == testheapintmin->Insert(node));

	node3 = new FiboHeapTestIntNode();

	node3->uKey = 300;

	CPPUNIT_ASSERT(node3 == testheapintmin->Insert(node3));

	CPPUNIT_ASSERT(node3 == testheapintmin->Remove(node3));

	CPPUNIT_ASSERT(node == testheapintmin->PeekMinMax());
}

void FibonacciHeapTest::RemoveNonRootTest()
{
	FiboHeapTestIntNode        *node[20];
	FiboHeapTestIntNode        *temp;
	int							count;
	__int64						val;

	for (int iter = 0; iter < 20; iter++)
	{
		node[iter] = new FiboHeapTestIntNode();
		node[iter]->uKey = iter * 100;
	}

	for (int x = 0; x < 19; x++) {

		count = 0;
		val = 2000;

		for (int iter = 0; iter < 20; iter++)
			CPPUNIT_ASSERT(testheapintmax->Insert(node[iter]) == node[iter]);

		CPPUNIT_ASSERT(node[19] == testheapintmax->RemoveMinMax());

		CPPUNIT_ASSERT(node[x] == testheapintmax->Remove(node[x]));

		if (x != 18)
			CPPUNIT_ASSERT(node[18] == testheapintmax->PeekMinMax());
		else
			CPPUNIT_ASSERT(node[17] == testheapintmax->PeekMinMax());

		while (testheapintmax->PeekMinMax())
		{
			count++;
			temp = (FiboHeapTestIntNode*)testheapintmax->RemoveMinMax();

			CPPUNIT_ASSERT(node[x] != temp);
			CPPUNIT_ASSERT(temp->uKey < val);
			val = temp->uKey;
		}

		CPPUNIT_ASSERT(count == 18);
	}

	for (int iter = 0; iter < 20; iter++)
		delete node[iter];
}

void FibonacciHeapTest::RemoveTwoNonRootTest()
{
	FiboHeapTestIntNode        *node[20];
	FiboHeapTestIntNode        *temp;
	int							count;
	__int64						val;

	for (int iter = 0; iter < 20; iter++)
	{
		node[iter] = new FiboHeapTestIntNode();
		node[iter]->uKey = iter * 100;
	}

	for (int x = 0; x < 19; x++) {

		for (int y = 0; x < 19; x++) {

			if (x == y)
				continue;

			count = 0;
			val = 2000;

			for (int iter = 0; iter < 20; iter++)
				testheapintmax->Insert(node[iter]);

			CPPUNIT_ASSERT(node[19] == testheapintmax->RemoveMinMax());
			CPPUNIT_ASSERT(node[x] == testheapintmax->Remove(node[x]));
			CPPUNIT_ASSERT(node[y] == testheapintmax->Remove(node[y]));

			if (x != 18 && y != 18)
				CPPUNIT_ASSERT(node[18] == testheapintmax->PeekMinMax());
			else if (x == 18 || y == 18)
				CPPUNIT_ASSERT(node[17] == testheapintmax->PeekMinMax());
			else if ((x == 17 && y == 18)||(x == 18 && y == 17))
				CPPUNIT_ASSERT(node[16] == testheapintmax->PeekMinMax());

			while (testheapintmax->PeekMinMax())
			{
				count++;
				temp = (FiboHeapTestIntNode*)testheapintmax->RemoveMinMax();

				CPPUNIT_ASSERT(node[x] != temp);
				CPPUNIT_ASSERT(node[y] != temp);
				CPPUNIT_ASSERT(temp->uKey < val);
				val = temp->uKey;
			}
			CPPUNIT_ASSERT(count == 17);
		}
	}

	for (int iter = 0; iter < 20; iter++)
		delete node[iter];
}

void FibonacciHeapTest::IncreaseKeyTest()
{
	FiboHeapTestIntNode  *	node[20];
	__int64					newkey;

	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(nullptr, nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(nullptr, nullptr, 0));

	for (int iter = 0; iter < 20; iter++)
	{
		node[iter] = new FiboHeapTestIntNode();
		node[iter]->uKey = iter * 100;
	}

	// increase key must fail on min heap in all scenario
	CPPUNIT_ASSERT(node[0] == testheapintmin->Insert(node[0]));
	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(nullptr, nullptr, 0));
	newkey = 10000;
	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(node[1], nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(node[1], &newkey, 0));
	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(node[1], &newkey, sizeof (__int64)));
	newkey = -10000;
	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(node[1], &newkey, 0));
	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(node[1], &newkey, sizeof(__int64)));
	CPPUNIT_ASSERT(node[0] == testheapintmin->Remove(node[0]));

	// max heap test invalid value
	CPPUNIT_ASSERT(node[19] == testheapintmax->Insert(node[19]));
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(nullptr, nullptr, 0));
	newkey = 100;
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(node[19], nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(node[19], &newkey, 0));
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(node[19], &newkey, sizeof(__int64)));
	newkey = node[19]->uKey;
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(node[19], &newkey, 0));
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(node[19], &newkey, sizeof(__int64)));
	newkey = node[19]->uKey+1;
	CPPUNIT_ASSERT(true == testheapintmax->IncreaseKey(node[19], &newkey, sizeof(__int64)));
	CPPUNIT_ASSERT(node[19] == testheapintmax->Remove(node[19]));

	for (int iter = 0; iter < 20; iter++)
		delete node[iter];	
}

void FibonacciHeapTest::DecreaseKeyTest()
{
	FiboHeapTestIntNode  *	node[20];
	__int64					newkey;

	CPPUNIT_ASSERT(false == testheapintmin->DecreaseKey(nullptr, nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmax->DecreaseKey(nullptr, nullptr, 0));

	for (int iter = 0; iter < 20; iter++)
	{
		node[iter] = new FiboHeapTestIntNode();
		node[iter]->uKey = iter * 100;
	}

	// increase key must fail on max heap in all scenario
	CPPUNIT_ASSERT(node[0] == testheapintmax->Insert(node[0]));
	CPPUNIT_ASSERT(false == testheapintmax->DecreaseKey(nullptr, nullptr, 0));
	newkey = 10000;
	CPPUNIT_ASSERT(false == testheapintmax->DecreaseKey(node[1], nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmax->DecreaseKey(node[1], &newkey, 0));
	CPPUNIT_ASSERT(false == testheapintmax->DecreaseKey(node[1], &newkey, sizeof(__int64)));
	newkey = -10000;
	CPPUNIT_ASSERT(false == testheapintmax->DecreaseKey(node[1], &newkey, 0));
	CPPUNIT_ASSERT(false == testheapintmax->DecreaseKey(node[1], &newkey, sizeof(__int64)));
	CPPUNIT_ASSERT(node[0] == testheapintmax->Remove(node[0]));

	// max heap test invalid value
	CPPUNIT_ASSERT(node[19] == testheapintmin->Insert(node[19]));
	CPPUNIT_ASSERT(false == testheapintmin->DecreaseKey(nullptr, nullptr, 0));
	newkey = 1901;
	CPPUNIT_ASSERT(false == testheapintmin->DecreaseKey(node[19], nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmin->DecreaseKey(node[19], &newkey, 0));
	CPPUNIT_ASSERT(false == testheapintmin->DecreaseKey(node[19], &newkey, sizeof(__int64)));
	newkey = node[19]->uKey;
	CPPUNIT_ASSERT(false == testheapintmin->DecreaseKey(node[19], &newkey, 0));
	CPPUNIT_ASSERT(false == testheapintmin->DecreaseKey(node[19], &newkey, sizeof(__int64)));
	newkey = node[19]->uKey - 1;
	CPPUNIT_ASSERT(true == testheapintmin->DecreaseKey(node[19], &newkey, sizeof(__int64)));
	CPPUNIT_ASSERT(node[19] == testheapintmin->Remove(node[19]));

	for (int iter = 0; iter < 20; iter++)
		delete node[iter];
}

void FibonacciHeapTest::IncreaseKeyNonRootLessThanParentAndRootTest()
{
	FiboHeapTestIntNode  *	node[20];
	FiboHeapTestIntNode *	temp;
	__int64					newkey;
	__int64					val;
	int						count = 0;

	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(nullptr, nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(nullptr, nullptr, 0));

	for (int iter = 0; iter < 20; iter++)
	{
		node[iter] = new FiboHeapTestIntNode();
		node[iter]->uKey = iter * 100;
	}

	for (int x = 0; x < 19; x++) {

		count = 0;
		val = 2000;

		for (int iter = 0; iter < 20; iter++)
			CPPUNIT_ASSERT(testheapintmax->Insert(node[iter]) == node[iter]);

		CPPUNIT_ASSERT(node[19] == testheapintmax->RemoveMinMax());

		newkey = node[x]->uKey + 50;

		CPPUNIT_ASSERT(true == testheapintmax->IncreaseKey(node[x], &newkey, sizeof (__int64)));

		CPPUNIT_ASSERT(node[18] == testheapintmax->PeekMinMax());

		while (testheapintmax->PeekMinMax())
		{
			count++;
			temp = (FiboHeapTestIntNode*)testheapintmax->RemoveMinMax();

			CPPUNIT_ASSERT(temp->uKey < val);
			val = temp->uKey;
		}

		CPPUNIT_ASSERT(count == 19);
	}

	for (int iter = 0; iter < 20; iter++)
		delete node[iter];
}

void FibonacciHeapTest::IncreaseKeyNonRootMoreThanRootTest()
{
	FiboHeapTestIntNode  *	node[20];
	FiboHeapTestIntNode *	temp;
	__int64					newkey;
	__int64					val;
	int						count = 0;

	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(nullptr, nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(nullptr, nullptr, 0));


	for (int x = 0; x < 19; x++) {

		count = 0;
		val = 2000;

		for (int iter = 0; iter < 20; iter++)
		{
			node[iter] = new FiboHeapTestIntNode();
			node[iter]->uKey = iter * 100;
			CPPUNIT_ASSERT(testheapintmax->Insert(node[iter]) == node[iter]);
		}

		CPPUNIT_ASSERT(node[19] == testheapintmax->RemoveMinMax());

		newkey = ((FiboHeapTestIntNode*)testheapintmax->PeekMinMax())->uKey + 50;

		CPPUNIT_ASSERT(true == testheapintmax->IncreaseKey(node[x], &newkey, sizeof(__int64)));

		CPPUNIT_ASSERT(node[x] == testheapintmax->PeekMinMax());

		while (testheapintmax->PeekMinMax())
		{
			count++;
			temp = (FiboHeapTestIntNode*)testheapintmax->RemoveMinMax();

			CPPUNIT_ASSERT(temp->uKey < val);
			val = temp->uKey;
		}

		CPPUNIT_ASSERT(count == 19);

		for (int iter = 0; iter < 20; iter++)
			delete node[iter];
	}
}


void FibonacciHeapTest::DecreaseKeyNonRootMoreThanRootTest()
{
	FiboHeapTestIntNode  *	node[20];
	FiboHeapTestIntNode *	temp;
	__int64					newkey;
	__int64					val;
	int						count = 0;

	for (int x = 1; x <= 19; x++) {

		count = 0;
		val = -2000;

		for (int iter = 0; iter < 20; iter++)
		{
			node[iter] = new FiboHeapTestIntNode();
			node[iter]->uKey = iter * 100;
			CPPUNIT_ASSERT(testheapintmin->Insert(node[iter]) == node[iter]);
		}

		CPPUNIT_ASSERT(node[0] == testheapintmin->RemoveMinMax());

		newkey = ((FiboHeapTestIntNode*)testheapintmin->PeekMinMax())->uKey - 50;

		CPPUNIT_ASSERT(true == testheapintmin->DecreaseKey(node[x], &newkey, sizeof(__int64)));

		CPPUNIT_ASSERT(node[x] == testheapintmin->PeekMinMax());

		while (testheapintmin->PeekMinMax())
		{
			count++;
			temp = (FiboHeapTestIntNode*)testheapintmin->RemoveMinMax();

			CPPUNIT_ASSERT(temp->uKey > val);
			val = temp->uKey;
		}

		CPPUNIT_ASSERT(count == 19);

		for (int iter = 0; iter < 20; iter++)
			delete node[iter];
	}
}

void FibonacciHeapTest::IncreaseKeyTwoNonRootMoreThanRootTest()
{
	FiboHeapTestIntNode  *	node[20];
	FiboHeapTestIntNode *	temp;
	__int64					newkey;
	__int64					val;
	int						count = 0;

	CPPUNIT_ASSERT(false == testheapintmin->IncreaseKey(nullptr, nullptr, 0));
	CPPUNIT_ASSERT(false == testheapintmax->IncreaseKey(nullptr, nullptr, 0));


	for (int x = 0; x < 19; x++) {

		for (int y = 0; y < 19; y++) {

			if (x == y)
				continue;

			for (int iter = 0; iter < 20; iter++)
			{
				node[iter] = new FiboHeapTestIntNode();
				node[iter]->uKey = iter * 100;
				CPPUNIT_ASSERT(testheapintmax->Insert(node[iter]) == node[iter]);
			}

			CPPUNIT_ASSERT(node[19] == testheapintmax->RemoveMinMax());

			count = 0;
			val = 2000;

			newkey = ((FiboHeapTestIntNode*)testheapintmax->PeekMinMax())->uKey + 50;

			CPPUNIT_ASSERT(true == testheapintmax->IncreaseKey(node[x], &newkey, sizeof(__int64)));

			CPPUNIT_ASSERT(node[x] == testheapintmax->PeekMinMax());

			newkey = ((FiboHeapTestIntNode*)testheapintmax->PeekMinMax())->uKey + 50;

			CPPUNIT_ASSERT(true == testheapintmax->IncreaseKey(node[y], &newkey, sizeof(__int64)));

			CPPUNIT_ASSERT(node[y] == testheapintmax->PeekMinMax());

			while (testheapintmax->PeekMinMax())
			{
				count++;
				temp = (FiboHeapTestIntNode*)testheapintmax->RemoveMinMax();

				CPPUNIT_ASSERT(temp->uKey < val);
				val = temp->uKey;
			}

			CPPUNIT_ASSERT(count == 19);

			for (int iter = 0; iter < 20; iter++)
				delete node[iter];
		}
	}
}

void FibonacciHeapTest::DecreaseKeyTwoNonRootMoreThanRootTest()
{
	FiboHeapTestIntNode  *	node[20];
	FiboHeapTestIntNode *	temp;
	__int64					newkey;
	__int64					val;
	int						count = 0;

	for (int x = 1; x < 20; x++) {

		for (int y = 1; y < 20; y++) {

			if (x == y)
				continue;

			for (int iter = 0; iter < 20; iter++)
			{
				node[iter] = new FiboHeapTestIntNode();
				node[iter]->uKey = iter * 100;
				CPPUNIT_ASSERT(testheapintmin->Insert(node[iter]) == node[iter]);
			}

			CPPUNIT_ASSERT(node[0] == testheapintmin->RemoveMinMax());

			count = 0;
			val = -1000000;

			newkey = ((FiboHeapTestIntNode*)testheapintmin->PeekMinMax())->uKey - 50;

			CPPUNIT_ASSERT(true == testheapintmin->DecreaseKey(node[x], &newkey, sizeof(__int64)));

			CPPUNIT_ASSERT(node[x] == testheapintmin->PeekMinMax());

			newkey = ((FiboHeapTestIntNode*)testheapintmin->PeekMinMax())->uKey - 50;

			CPPUNIT_ASSERT(true == testheapintmin->DecreaseKey(node[y], &newkey, sizeof(__int64)));

			CPPUNIT_ASSERT(node[y] == testheapintmin->PeekMinMax());

			while (testheapintmin->PeekMinMax())
			{
				count++;
				temp = (FiboHeapTestIntNode*)testheapintmin->RemoveMinMax();

				CPPUNIT_ASSERT(temp->uKey > val);
				val = temp->uKey;
			}

			CPPUNIT_ASSERT(count == 19);

			for (int iter = 0; iter < 20; iter++)
				delete node[iter];
		}
	}
}

void FibonacciHeapTest::DecreaseKeyNonRootLessThanParentAndRootTest()
{
	FiboHeapTestIntNode  *	node[20];
	FiboHeapTestIntNode *	temp;
	__int64					newkey;
	__int64					val;
	int						count = 0;

	for (int iter = 0; iter < 20; iter++)
	{
		node[iter] = new FiboHeapTestIntNode();
		node[iter]->uKey = iter * 100;
	}

	for (int x = 1; x < 20; x++) {

		count = 0;
		val = -2000;

		for (int iter = 0; iter < 20; iter++)
			CPPUNIT_ASSERT(testheapintmin->Insert(node[iter]) == node[iter]);

		CPPUNIT_ASSERT(node[0] == testheapintmin->RemoveMinMax());

		newkey = node[x]->uKey - 50;

		CPPUNIT_ASSERT(true == testheapintmin->DecreaseKey(node[x], &newkey, sizeof(__int64)));

		CPPUNIT_ASSERT(node[1] == testheapintmin->PeekMinMax());

		while (testheapintmin->PeekMinMax())
		{
			count++;
			temp = (FiboHeapTestIntNode*)testheapintmin->RemoveMinMax();

			CPPUNIT_ASSERT(temp->uKey > val);
			val = temp->uKey;
		}

		CPPUNIT_ASSERT(count == 19);
	}

	for (int iter = 0; iter < 20; iter++)
		delete node[iter];
}