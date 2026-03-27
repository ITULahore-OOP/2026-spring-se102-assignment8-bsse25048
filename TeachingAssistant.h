#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H
#include "Student.h"
#include "Staff.h"
#include <iostream>
#include <string>
using namespace std;


class TeachingAssistant : public Student, public Staff {
    int workingHours;
public:
        TeachingAssistant(string name, int memberID, double cgpa, 
            double salary, AccessCard card, int workingHours);
        
        void displayRole() override;
        void gradeAssignment(int score);
        void gradeAssignment(string letterGrade);
};









#endif