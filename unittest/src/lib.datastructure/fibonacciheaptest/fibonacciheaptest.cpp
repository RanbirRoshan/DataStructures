
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