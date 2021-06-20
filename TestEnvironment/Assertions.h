#pragma once

#include "TestEnvironment.h"

#define assert_equals(a, b, comm) {if ((a)!=(b)) return CreateTestResult(1, (comm));};

#define pass_test {return CreateTestResult(0, "");};

#define skip_test {return CreateTestResult(-1, "Test skipped");};