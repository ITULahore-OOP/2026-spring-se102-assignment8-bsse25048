#include "Department.h"


Department::Department() {}

Department::Department(string departmentName) {
    this->departmentName = departmentName;
    memberCount = 0;

    for (int i = 0; i < 50; i++) {
        members[i] = nullptr;
    }
}

void Department::addMember(UniversityMember* member) {
    if (memberCount < 50) {
        members[memberCount] = member;
        memberCount++;
    }
    else {
        cout << "Department is full. Cannot add more members." << endl;
    }
}

void Department::displayAllRoles() {
    for (int i = 0; i < memberCount; i++) {
        if (members[i] != nullptr) {
            members[i]->displayRole();
        }
    }
}