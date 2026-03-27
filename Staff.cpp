#include "Staff.h"




Staff :: Staff () {}
Staff :: Staff (string name, int memberID, double salary, AccessCard card)
         : UniversityMember(name, memberID) {
            this->salary = salary;
            this-> card= card;
}
double Staff :: getSalary() {
    return salary;
}
void Staff :: displayRole() {
    cout<<"Role: Staff"<<endl;
}
void Staff :: displayCard() {
    cout<<card.getCardID()<<endl;
}