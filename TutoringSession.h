#ifndef TUTORINGSESSION_H
#define TUTORINGSESSION_H
#include "TeachingAssistant.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;


class TutoringSession {
    int sessionID;
    double durationMinutes;
    TeachingAssistant* ta;
    Student* student;
public:
    TutoringSession ();
    TutoringSession(int sessionID, double durationMinutes, TeachingAssistant* ta, Student* student);
    double getDuration();
    void displaySession();
    TutoringSession operator+ (const TutoringSession& other);
    friend bool operator> (const TutoringSession& s1, const TutoringSession& s2);
};











#endif