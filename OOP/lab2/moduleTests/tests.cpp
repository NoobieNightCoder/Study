#include "../setContainer/setContainer.h"
#include <string>

// CONTAINS //
bool testContainsEmpty() {
    set<int> s;
    return !s.contains(10);
}

bool testContainsAfterAdd() {
    set<int> s;
    s.add(5);
    return s.contains(5);
}

bool testContainsMultiple() {
    set<int> s({1,2,3});
    return s.contains(1) && s.contains(2) && s.contains(3);
}

bool testContainsNotExisting() {
    set<int> s({1,2,3});
    return !s.contains(99);
}

bool testContainsEmptyStr() {
    set<std::string> s;
    return !s.contains("one");
}

bool testContainsAfterAddStr() {
    set<std::string> s;
    s.add("one");
    return s.contains("one");
}

bool testContainsMultipleStr() {
    set<std::string> s({"one","two","three"});
    return s.contains("one") && s.contains("two") && s.contains("three");
}

bool testContainsNotExistingStr() {
    set<std::string> s({"one","two","three"});
    return !s.contains("four");
}

bool testContainsEmptyStringStr() {
    set<std::string> s({"", "one"});
    return s.contains("") && !s.contains(" ");
}



// ADD //
bool testAddNewElement() {
    set<int> s;
    s.add(1);
    return s.getLength() == 1 && s.contains(1);
}

bool testAddDuplicate() {
    set<int> s({1});
    s.add(1);
    return s.getLength() == 1;
}

bool testAddMultiple() {
    set<int> s;
    s.add(1);
    s.add(2);
    s.add(3);
    return s.getLength() == 3 && s.contains(2);
}

bool testAddNewElementStr() {
    set<std::string> s;
    s.add("one");
    return s.getLength() == 1 && s.contains("one");
}

bool testAddDuplicateStr() {
    set<std::string> s({"one"});
    s.add("one");
    return s.getLength() == 1;
}

bool testAddMultipleStr() {
    set<std::string> s;
    s.add("one");
    s.add("two");
    s.add("three");
    return s.getLength() == 3 && s.contains("two");
}

bool testAddEmptyStringStr() {
    set<std::string> s;
    s.add("");
    return s.getLength() == 1 && s.contains("");
}

bool testAddCaseSensitiveStr() {
    set<std::string> s;
    s.add("one");
    s.add("One");
    return s.getLength() == 2 && s.contains("one") && s.contains("One");
}



// REMOVE //
bool testRemoveExisting() {
    set<int> s({1,2,3});
    s.remove(2);
    return !s.contains(2) && s.getLength() == 2;
}

bool testRemoveNotExisting() {
    set<int> s({1,2,3});
    s.remove(99);
    return s.getLength() == 3;
}

bool testRemoveLastElement() {
    set<int> s({5});
    s.remove(5);
    return s.getLength() == 0 && !s.contains(5);
}

bool testRemoveExistingStr() {
    set<std::string> s({"one","two","three"});
    s.remove("two");
    return !s.contains("two") && s.getLength() == 2;
}

bool testRemoveNotExistingStr() {
    set<std::string> s({"one","two","three"});
    s.remove("four");
    return s.getLength() == 3;
}

bool testRemoveLastElementStr() {
    set<std::string> s({"one"});
    s.remove("one");
    return s.getLength() == 0 && !s.contains("one");
}

bool testRemoveFirstElementStr() {
    set<std::string> s({"one","two","three"});
    s.remove("one");
    return s.getLength() == 2 && !s.contains("one") && s.contains("two") && s.contains("three");
}

bool testRemoveEmptyStringStr() {
    set<std::string> s({"", "one"});
    s.remove("");
    return s.getLength() == 1 && !s.contains("") && s.contains("one");
}

// TYPES //
bool testDoubleType() {
    set<double> s;
    s.add(1.5);
    s.add(2.5);
    s.add(1.5);
    s.remove(1.5);
    return s.getLength() == 1 && !s.contains(1.5) && s.contains(2.5);
}

bool testCharType() {
    set<char> s;
    s.add('a');
    s.add('b');
    s.add('a');
    s.remove('a');
    return s.getLength() == 1 && !s.contains('a') && s.contains('b');
}

bool testBoolType() {
    set<bool> s;
    s.add(true);
    s.add(false);
    s.add(true);
    s.remove(false);
    return s.getLength() == 1 && s.contains(true) && !s.contains(false);
}

// CLEAR //
bool testClear() {
    set<int> s({1,2,3});
    s.clear();
    return s.getLength() == 0 && !s.contains(1);
}

bool testClearStr() {
    set<std::string> s({"one","two","three"});
    s.clear();
    return s.getLength() == 0 && !s.contains("one");
}

// CONSTRUCTORS //
bool testInitializerListConstructor() {
    set<int> s({1,2,3});
    return s.getLength() == 3 && s.contains(2);
}

bool testCopyConstructor() {
    set<int> s1({1,2,3});
    set<int> s2(s1);
    return s2.getLength() == 3 && s2.contains(1) && s2.contains(3);
}

bool testMoveConstructor() {
    set<int> s1({1,2});
    set<int> s2(std::move(s1));
    return s2.getLength() == 2 && s2.contains(1) && s1.getLength() == 0;
}

bool testInitializerListConstructorStr() {
    set<std::string> s({"one","two","three"});
    return s.getLength() == 3 && s.contains("two");
}

bool testInitializerListConstructorDuplicateStr() {
    set<std::string> s({"one","two","one"});
    return s.getLength() == 2 && s.contains("one") && s.contains("two");
}

bool testCopyConstructorStr() {
    set<std::string> s1({"one","two","three"});
    set<std::string> s2(s1);
    return s2.getLength() == 3 && s2.contains("one") && s2.contains("three");
}

bool testMoveConstructorStr() {
    set<std::string> s1({"one","two"});
    set<std::string> s2(std::move(s1));
    return s2.getLength() == 2 && s2.contains("one") && s1.getLength() == 0;
}

// OPERATORS //
bool testUnionLogic() {
    set<int> s1({1,2});
    set<int> s2({2,3});
    s1.unite(s2);
    return s1.getLength() == 3 && s1.contains(3);
}

bool testIntersectionLogic() {
    set<int> s1({1,2,3});
    set<int> s2({2,3,4});
    s1.intersection(s2);
    return s1.getLength() == 2 && s1.contains(2) && s1.contains(3);
}

bool testSubtractLogic() {
    set<int> s1({1,2,3});
    set<int> s2({2,3});
    s1.subtract(s2);
    return s1.getLength() == 1 && s1.contains(1);
}

bool testUnionLogicStr() {
    set<std::string> s1({"one","two"});
    set<std::string> s2({"two","three"});
    s1.unite(s2);
    return s1.getLength() == 3 && s1.contains("three");
}

bool testIntersectionLogicStr() {
    set<std::string> s1({"one","two","three"});
    set<std::string> s2({"two","three","four"});
    s1.intersection(s2);
    return s1.getLength() == 2 && s1.contains("two") && s1.contains("three");
}

bool testSubtractLogicStr() {
    set<std::string> s1({"one","two","three"});
    set<std::string> s2({"two","three"});
    s1.subtract(s2);
    return s1.getLength() == 1 && s1.contains("one");
}

bool testOperatorPlus() {
    set<int> s1({1,2});
    set<int> s2({2,3});
    set<int> r = s1 + s2;
    return r.getLength() == 3 && r.contains(3);
}

bool testOperatorMultiply() {
    set<int> s1({1,2,3});
    set<int> s2({2,3,4});
    set<int> r = s1 * s2;
    return r.getLength() == 2 && r.contains(2) && r.contains(3);
}

bool testOperatorDivide() {
    set<int> s1({1,2,3});
    set<int> s2({2});
    set<int> r = s1 / s2;
    return r.getLength() == 2 && r.contains(1) && r.contains(3);
}

bool testOperatorPlusStr() {
    set<std::string> s1({"one","two"});
    set<std::string> s2({"two","three"});
    set<std::string> r = s1 + s2;
    return r.getLength() == 3 && r.contains("three");
}

bool testOperatorMultiplyStr() {
    set<std::string> s1({"one","two","three"});
    set<std::string> s2({"two","three","four"});
    set<std::string> r = s1 * s2;
    return r.getLength() == 2 && r.contains("two") && r.contains("three");
}

bool testOperatorDivideStr() {
    set<std::string> s1({"one","two","three"});
    set<std::string> s2({"two"});
    set<std::string> r = s1 / s2;
    return r.getLength() == 2 && r.contains("one") && r.contains("three");
}

bool testOperatorPlusEqual() {
    set<int> s1({1});
    set<int> s2({2});
    s1 += s2;
    return s1.getLength() == 2 && s1.contains(2);
}

bool testOperatorMultiplyEqual() {
    set<int> s1({1,2});
    set<int> s2({2});
    s1 *= s2;
    return s1.getLength() == 1 && s1.contains(2);
}

bool testOperatorDivideEqual() {
    set<int> s1({1,2});
    set<int> s2({2});
    s1 /= s2;
    return s1.getLength() == 1 && s1.contains(1);
}

bool testOperatorPlusEqualStr() {
    set<std::string> s1({"one"});
    set<std::string> s2({"two"});
    s1 += s2;
    return s1.getLength() == 2 && s1.contains("two");
}

bool testOperatorMultiplyEqualStr() {
    set<std::string> s1({"one","two"});
    set<std::string> s2({"two"});
    s1 *= s2;
    return s1.getLength() == 1 && s1.contains("two");
}

bool testOperatorDivideEqualStr() {
    set<std::string> s1({"one","two"});
    set<std::string> s2({"two"});
    s1 /= s2;
    return s1.getLength() == 1 && s1.contains("one");
}

bool testAssignmentOperator() {
    set<int> s1({1,2,3});
    set<int> s2;
    s2 = s1;
    return s2.getLength() == 3 && s2.contains(2);
}

bool testAssignmentOperatorStr() {
    set<std::string> s1({"one","two","three"});
    set<std::string> s2;
    s2 = s1;
    return s2.getLength() == 3 && s2.contains("two");
}

// ITERATOR //
bool testIteratorNotEqualBeginEnd() {
    set<int> s({1});
    return s.iteratorBegin() != s.iteratorEnd();
}

bool testIteratorEqualAfterIncrement() {
    set<int> s({1});
    auto it = s.iteratorBegin();
    auto end = s.iteratorEnd();
    ++it;
    return !(it != end);
}

bool testIteratorSelfCompare() {
    set<int> s({1,2});
    auto it = s.iteratorBegin();
    return !(it != it);
}

bool testIteratorNotEqualBeginEndStr() {
    set<std::string> s({"one"});
    return s.iteratorBegin() != s.iteratorEnd();
}

bool testIteratorEqualAfterIncrementStr() {
    set<std::string> s({"one"});
    auto it = s.iteratorBegin();
    auto end = s.iteratorEnd();
    ++it;
    return !(it != end);
}

bool testIteratorSelfCompareStr() {
    set<std::string> s({"one","two"});
    auto it = s.iteratorBegin();
    return !(it != it);
}

bool testIteratorDereferenceStr() {
    set<std::string> s({"one"});
    auto it = s.iteratorBegin();
    return *it == "one";
}
