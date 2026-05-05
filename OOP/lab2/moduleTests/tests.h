#pragma once

#include "testFramework.h"

// CONTAINS //
bool testContainsEmpty();
bool testContainsAfterAdd();
bool testContainsMultiple();
bool testContainsNotExisting();
bool testContainsEmptyStr();
bool testContainsAfterAddStr();
bool testContainsMultipleStr();
bool testContainsNotExistingStr();
bool testContainsEmptyStringStr();

// ADD //

// INT //
bool testAddNewElement();
bool testAddDuplicate();
bool testAddMultiple();
// STRING //
bool testAddNewElementStr();
bool testAddDuplicateStr();
bool testAddMultipleStr();
bool testAddEmptyStringStr();
bool testAddCaseSensitiveStr();

// REMOVE //

// INT //
bool testRemoveExisting();
bool testRemoveNotExisting();
bool testRemoveLastElement();
// STRING //
bool testRemoveExistingStr();
bool testRemoveNotExistingStr();
bool testRemoveLastElementStr();
bool testRemoveFirstElementStr();
bool testRemoveEmptyStringStr();

// TYPES //
bool testDoubleType();
bool testCharType();
bool testBoolType();

// CLEAR //
bool testClear();
bool testClearStr();

// CONSTRUCTORS //
bool testInitializerListConstructor();
bool testCopyConstructor();
bool testMoveConstructor();
bool testInitializerListConstructorStr();
bool testInitializerListConstructorDuplicateStr();
bool testCopyConstructorStr();
bool testMoveConstructorStr();

// OPERATORS //
bool testUnionLogic();
bool testIntersectionLogic();
bool testSubtractLogic();
bool testUnionLogicStr();
bool testIntersectionLogicStr();
bool testSubtractLogicStr();

bool testOperatorPlus();
bool testOperatorMultiply();
bool testOperatorDivide();
bool testOperatorPlusStr();
bool testOperatorMultiplyStr();
bool testOperatorDivideStr();

bool testOperatorPlusEqual();
bool testOperatorMultiplyEqual();
bool testOperatorDivideEqual();
bool testOperatorPlusEqualStr();
bool testOperatorMultiplyEqualStr();
bool testOperatorDivideEqualStr();

bool testAssignmentOperator();
bool testAssignmentOperatorStr();

// ITERATOR //
bool testIteratorNotEqualBeginEnd();
bool testIteratorEqualAfterIncrement();
bool testIteratorSelfCompare();
bool testIteratorNotEqualBeginEndStr();
bool testIteratorEqualAfterIncrementStr();
bool testIteratorSelfCompareStr();
bool testIteratorDereferenceStr();

#include "tests.cpp"
