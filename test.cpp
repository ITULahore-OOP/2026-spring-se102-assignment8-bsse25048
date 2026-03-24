#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <iostream>
#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"

using namespace std;

// Utility struct to temporarily redirect std::cout for testing void functions
struct CoutRedirect
{
    std::stringstream buffer;
    std::streambuf *old;
    CoutRedirect() : old(std::cout.rdbuf(buffer.rdbuf())) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
    std::string getString() { return buffer.str(); }
};

TEST_CASE("Test 1: AccessCard and Staff Composition")
{
    AccessCard card("AC-123", 3);
    REQUIRE(card.getCardID() == "AC-123");
    REQUIRE(card.getAccessLevel() == 3);

    Staff staff("Alice", 1001, 55000.0, card);
    REQUIRE(staff.getName() == "Alice");
    REQUIRE(staff.getMemberID() == 1001);
    REQUIRE(staff.getSalary() == Approx(55000.0));
}

TEST_CASE("Test 2: Student Attributes and Updates")
{
    Student student("Bob", 1002, 3.5);
    REQUIRE(student.getName() == "Bob");
    REQUIRE(student.getMemberID() == 1002);
    REQUIRE(student.getCGPA() == Approx(3.5));

    student.updateCGPA(3.8);
    REQUIRE(student.getCGPA() == Approx(3.8));
}

TEST_CASE("Test 3: TeachingAssistant - Diamond Problem Resolution")
{
    AccessCard taCard("AC-TA1", 2);
    // If virtual inheritance is missing, compilation will fail or getters will be ambiguous
    TeachingAssistant ta("Charlie", 1003, 3.9, 15000.0, taCard, 20);

    REQUIRE(ta.getName() == "Charlie");
    REQUIRE(ta.getMemberID() == 1003);
    REQUIRE(ta.getCGPA() == Approx(3.9));
    REQUIRE(ta.getSalary() == Approx(15000.0));
}

TEST_CASE("Test 4: TutoringSession Operator Overloading (+ and >)")
{
    AccessCard taCard("AC-TA2", 2);
    TeachingAssistant ta("David", 1004, 3.7, 12000.0, taCard, 15);
    Student s("Eve", 1005, 3.2);

    TutoringSession session1(1, 45.0, &ta, &s);
    TutoringSession session2(2, 30.0, &ta, &s);

    // Test > operator
    REQUIRE((session1 > session2) == true);
    REQUIRE((session2 > session1) == false);

    // Test + operator
    TutoringSession merged = session1 + session2;
    REQUIRE(merged.getDuration() == Approx(75.0)); // 45 + 30
}

TEST_CASE("Test 5: Concept - Run-Time Polymorphism (Overriding & Virtual Functions)")
{
    AccessCard card("AC-123", 1);
    Student s("Alice", 101, 3.5);
    Staff st("Bob", 102, 50000, card);
    TeachingAssistant ta("Charlie", 103, 3.9, 15000, card, 20);

    // Create an array of base class pointers
    UniversityMember *members[3];
    members[0] = &s;
    members[1] = &st;
    members[2] = &ta;

    CoutRedirect redirect; 
    // If run-time polymorphism works, it should trigger the derived versions dynamically.
    members[0]->displayRole();
    members[1]->displayRole();
    members[2]->displayRole();

    string output = redirect.getString();

    // Verify the correct overridden methods were dynamically bound and executed
    REQUIRE(output.find("Role: Student") != string::npos);
    REQUIRE(output.find("Role: Staff") != string::npos);
    REQUIRE(output.find("Role: Teaching Assistant") != string::npos);
}

TEST_CASE("Test 6: Concept - Compile-Time Polymorphism (Method Overloading)")
{
    AccessCard card("AC-124", 2);
    TeachingAssistant ta("David", 104, 3.8, 12000, card, 15);

    CoutRedirect redirect;

    // Call both overloaded versions of gradeAssignment
    ta.gradeAssignment(95);   // Calls the int version
    ta.gradeAssignment("A+"); // Calls the string version

    string output = redirect.getString();

    // Verify both versions executed correctly based on their distinct signatures
    REQUIRE(output.find("numeric score: 95/100") != string::npos);
    REQUIRE(output.find("letter grade: A+") != string::npos);
}

TEST_CASE("Test 7: Concept - The Diamond Problem Strict Memory Check")
{
    AccessCard taCard("AC-TA1", 2);
    TeachingAssistant ta("Eve", 105, 3.9, 16000.0, taCard, 20);

    // Strict Memory Address Check (The core of resolving the Diamond Problem)
    // Cast the TA pointer to both its direct parent types
    Student *studentPtr = &ta;
    Staff *staffPtr = &ta;

    // Cast both parent pointers up to the base class
    UniversityMember *baseFromStudent = static_cast<UniversityMember *>(studentPtr);
    UniversityMember *baseFromStaff = static_cast<UniversityMember *>(staffPtr);

    // If virtual inheritance is implemented correctly, both paths must point
    // to the EXACT SAME shared instance of the UniversityMember base class.
    // If they missed virtual inheritance, this will fail.
    REQUIRE(baseFromStudent == baseFromStaff);
}