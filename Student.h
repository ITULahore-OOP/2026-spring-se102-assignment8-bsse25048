#ifndef STUDENT_H
#define STUDENT_H
#include "UniversityMember.h"
#include <iostream>
#include <string>
using namespace std;

class Student : virtual public UniversityMember {
    double cgpa;
public:
    Student ();
    Student (string name, int memberID, double cgpa);
    double getCGPA();
    void updateCGPA(double newCGPA);
    void displayRole() override;
};


#endif