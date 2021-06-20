#include "TestPack.h"

Test CreateTest(const char* name, void* (*testFunction)()) {
    Test t;

    t.name = name;
    t.testFunction = testFunction;

    return t;
}

SimpleTestResult* CreateTestResult(int exitCode, const char* comment) {
    SimpleTestResult* result = (SimpleTestResult*)malloc(sizeof(SimpleTestResult));

    result->exitCode = exitCode;
    result->comment = comment;

    return result;
}

TestPack* CreateTestPack(const char* name, int testCount, ...) {
	TestPack* testPack = (TestPack*) malloc(sizeof(TestPack));

    testPack->name = name;
	testPack->testCount = testCount;
	testPack->tests = (Test*)malloc(sizeof(Test) * testCount);

    va_list testFunctions;         
    va_start(testFunctions, testCount);    
    for (int i = 0; i < testCount; i++)
    {
        testPack->tests[i] = va_arg(testFunctions, Test);  
    }
    va_end(testFunctions); 

    return testPack;
}

void RunTests(TestPack* testPack) {
    int passed = 0;
    int skipped = 0;

    printf("Launching tests from pack \"%s\"\n\n", testPack->name);

    for (int i = 0; i < testPack->testCount; i++)
    {
        SimpleTestResult* res = (SimpleTestResult*) testPack->tests[i].testFunction();

        if (res->exitCode == 0) {
            printf("%s - passed\n", testPack->tests[i].name);
            ++passed;
        }
        else if (res->exitCode < 0) {
            printf("%s - skipped\n", testPack->tests[i].name);
            ++skipped;
        }
        else
            printf("%s - failed: %s\n", testPack->tests[i].name, res->comment);

        free(res);
    }

    printf("\nStatistics: passed %d of %d tests\n", passed, testPack->testCount - skipped);

    free(testPack->tests);
    free(testPack);
}