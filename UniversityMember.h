#ifndef UNIVERSITYMEMBER_H
#define UNIVERSITYMEMBER_H
#include <iostream>
#include <string>
using namespace std;

class UniversityMember {     //abstract class
    string name;
    int memberID;
public:
    UniversityMember ();
    UniversityMember(string name, int memberID);
    virtual ~UniversityMember();
    string getName();
    int getMemberID();
    virtual void displayRole()=0;      //pure virtual function

};






#endif
