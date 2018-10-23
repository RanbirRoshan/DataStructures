
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>



class DiskDataTestCase : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(DiskDataTestCase);
	CPPUNIT_TEST(loadTest);
	CPPUNIT_TEST(storeTest);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void loadTest();
	void storeTest();

private:
};
