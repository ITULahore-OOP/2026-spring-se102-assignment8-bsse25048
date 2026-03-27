#include "TeachingAssistant.h"





TeachingAssistant :: TeachingAssistant (string name, int memberID, double cgpa, 
                        double salary, AccessCard card, int workingHours)
                         : UniversityMember(name, memberID) , Student (name, memberID, cgpa) , Staff(name, memberID, salary, card){
                            this-> workingHours = workingHours;
                        }
void TeachingAssistant :: displayRole() {
    cout<<"Role: Teaching Assistant"<<endl;
}
void TeachingAssistant::gradeAssignment(int score) {
    cout << "numeric score: " << score << "/100" << endl;
}

void TeachingAssistant::gradeAssignment(string letterGrade) {
    cout << "letter grade: " << letterGrade << endl;
}