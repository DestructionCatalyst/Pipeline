#include "Test.h"


int main() {

	//testNode();

	TestPack* baseTests = CreateTestPack("Tests of the core", 4,
		CreateTest("Linked list node test", TestNode),
		CreateTest("Queue test", TestQueue),
		CreateTest("Hash function test", TestHashFunction),
		CreateTest("Hash table test", TestHashTable)
	);

	RunTests(baseTests);

	return 0;
}