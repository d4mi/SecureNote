#include "SecurityTest.h"

SecurityTest::SecurityTest()
{

}
	
SecurityTest::~SecurityTest()
{

}

void SecurityTest::SetUp()
{

}
	
void SecurityTest::TearDown()
{

}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}