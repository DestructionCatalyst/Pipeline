#pragma once

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct SimpleTestResult {
	int exitCode;
	const char* comment;
} SimpleTestResult;

// Basincally a function with a displayable name
typedef struct Test {
	const char* name;
	void* (*testFunction)();
} Test;

// A static array of tests that can be launched simultaneously
typedef struct TestPack {
	const char* name;
	int testCount;
	Test* tests;
} TestPack;

// Create a single test from the function that returns a pointer to the test result
Test CreateTest(const char* name, void* (*testFunction)());

SimpleTestResult* CreateTestResult(int exitCode, const char* comment);

//Create a test pack from a given number of tests
TestPack* CreateTestPack(const char* name, int testCount, ...);

// Runs all the tests in a text pack and deletes it
void RunTests(TestPack* testPack);