#include <iostream>
#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"

using namespace std;

int main() {

    
    AccessCard card1("AC101", 1);
    AccessCard card2("AC102", 2);
    AccessCard card3("AC103", 3);

    
    Student s1("Ali", 1001, 3.5);
    Student s2("Sara", 1002, 3.8);

    
    Staff st1("Usman", 2001, 50000, card1);

    
    TeachingAssistant ta1("Hina", 3001, 3.7, 40000, card2, 20);

    
    cout << "----- Run-time Polymorphism -----" << endl;

    UniversityMember* members[4];

    members[0] = &s1;
    members[1] = &s2;
    members[2] = &st1;
    members[3] = &ta1;

    for (int i = 0; i < 4; i++) {
        members[i]->displayRole();   
    }

    
    cout << "\n----- Compile-time Polymorphism -----" << endl;

    ta1.gradeAssignment(85);          
    ta1.gradeAssignment("A");         

    
    cout << "\n----- Operator Overloading -----" << endl;

    TutoringSession ts1(1, 60, &ta1, &s1);
    TutoringSession ts2(2, 90, &ta1, &s2);

    
    TutoringSession total = ts1 + ts2;

    cout << "Session 1 duration: " << ts1.getDuration() << endl;
    cout << "Session 2 duration: " << ts2.getDuration() << endl;
    cout << "Combined duration: " << total.getDuration() << endl;

    
    if (ts2 > ts1) {
        cout << "Session 2 is longer than Session 1" << endl;
    } else {
        cout << "Session 1 is longer or equal" << endl;
    }

    return 0;
}