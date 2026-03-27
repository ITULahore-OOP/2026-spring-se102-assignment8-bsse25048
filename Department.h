#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "UniversityMember.h"
#include <iostream>
#include <string>
using namespace std;



class Department {
    string departmentName;
    UniversityMember* members[50];
    int memberCount;
public:
    Department ();
    Department (string departmentName);
    void addMember(UniversityMember* member);
    void displayAllRoles();
};








#endif