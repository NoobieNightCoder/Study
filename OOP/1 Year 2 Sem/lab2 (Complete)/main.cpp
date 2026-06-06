#include <iostream>
#include <cassert>
#include <string>

#include "setContainer/setContainer.h"
#include "moduleTests/testFramework.h"
#include "moduleTests/tests.h"

using namespace std;

struct TestCase {
    const char* name;
    bool (*func)();
};

const TestCase Tests[] = {
    // CONTAINS //
    ADD_TEST(testContainsEmpty),
    ADD_TEST(testContainsAfterAdd),
    ADD_TEST(testContainsMultiple),
    ADD_TEST(testContainsNotExisting),
    ADD_TEST(testContainsEmptyStr),
    ADD_TEST(testContainsAfterAddStr),
    ADD_TEST(testContainsMultipleStr),
    ADD_TEST(testContainsNotExistingStr),
    ADD_TEST(testContainsEmptyStringStr),

    // ADD //
    ADD_TEST(testAddNewElement),
    ADD_TEST(testAddDuplicate),
    ADD_TEST(testAddMultiple),
    ADD_TEST(testAddNewElementStr),
    ADD_TEST(testAddDuplicateStr),
    ADD_TEST(testAddMultipleStr),
    ADD_TEST(testAddEmptyStringStr),
    ADD_TEST(testAddCaseSensitiveStr),

    // REMOVE //
    ADD_TEST(testRemoveExisting),
    ADD_TEST(testRemoveNotExisting),
    ADD_TEST(testRemoveLastElement),
    ADD_TEST(testRemoveExistingStr),
    ADD_TEST(testRemoveNotExistingStr),
    ADD_TEST(testRemoveLastElementStr),
    ADD_TEST(testRemoveFirstElementStr),
    ADD_TEST(testRemoveEmptyStringStr),

    // TYPES //
    ADD_TEST(testDoubleType),
    ADD_TEST(testCharType),
    ADD_TEST(testBoolType),

    // CLEAR //
    ADD_TEST(testClear),
    ADD_TEST(testClearStr),

    // CONSTRUCTORS //
    ADD_TEST(testInitializerListConstructor),
    ADD_TEST(testCopyConstructor),
    ADD_TEST(testMoveConstructor),
    ADD_TEST(testInitializerListConstructorStr),
    ADD_TEST(testInitializerListConstructorDuplicateStr),
    ADD_TEST(testCopyConstructorStr),
    ADD_TEST(testMoveConstructorStr),

    // OPERATORS //
    ADD_TEST(testUnionLogic),
    ADD_TEST(testIntersectionLogic),
    ADD_TEST(testSubtractLogic),
    ADD_TEST(testUnionLogicStr),
    ADD_TEST(testIntersectionLogicStr),
    ADD_TEST(testSubtractLogicStr),

    ADD_TEST(testOperatorPlus),
    ADD_TEST(testOperatorMultiply),
    ADD_TEST(testOperatorDivide),
    ADD_TEST(testOperatorPlusStr),
    ADD_TEST(testOperatorMultiplyStr),
    ADD_TEST(testOperatorDivideStr),

    ADD_TEST(testOperatorPlusEqual),
    ADD_TEST(testOperatorMultiplyEqual),
    ADD_TEST(testOperatorDivideEqual),
    ADD_TEST(testOperatorPlusEqualStr),
    ADD_TEST(testOperatorMultiplyEqualStr),
    ADD_TEST(testOperatorDivideEqualStr),

    ADD_TEST(testAssignmentOperator),
    ADD_TEST(testAssignmentOperatorStr),

    // ITERATOR //
    ADD_TEST(testIteratorNotEqualBeginEnd),
    ADD_TEST(testIteratorEqualAfterIncrement),
    ADD_TEST(testIteratorSelfCompare),
    ADD_TEST(testIteratorNotEqualBeginEndStr),
    ADD_TEST(testIteratorEqualAfterIncrementStr),
    ADD_TEST(testIteratorSelfCompareStr),
    ADD_TEST(testIteratorDereferenceStr)
};


int main() {
    cout << "--- RUNNING MODULE TESTS ---" << endl;

    for(const auto& test : Tests) {
        report(test.name, test.func());
    }    

    cout << "----------------------------" << endl;
    return 0;
}
