#ifndef STAFF_H
#define STAFF_H
#include "UniversityMember.h"
#include "AccessCard.h"
#include <iostream>
#include <string>
using namespace std;



class Staff : virtual public UniversityMember {
    double salary;
    AccessCard card;
public:
    Staff ();
    Staff(string name, int memberID, double salary, AccessCard card);
    double getSalary();
    void displayRole() override;
    void displayCard();
};










#endif