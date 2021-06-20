#include "Test.h"


int main() {
	
	//testNode();

	TestPack* baseTests = CreateTestPack("Tests of the core", 2, 
		CreateTest("Linked list node test", TestNode),
		CreateTest("Queue test", TestQueue)
	);

	RunTests(baseTests);

	return 0;
}