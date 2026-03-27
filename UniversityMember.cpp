#include "UniversityMember.h"



UniversityMember :: UniversityMember () {}
UniversityMember :: UniversityMember (string name, int memberID) {
    this->name = name;
    this->memberID = memberID;
}
UniversityMember :: ~UniversityMember() {
    cout<<"UnversityMember destroyed"<<endl;
}
string UniversityMember :: getName() {
    return name;
}
int UniversityMember :: getMemberID() {
    return memberID;
}
void UniversityMember :: displayRole() {}