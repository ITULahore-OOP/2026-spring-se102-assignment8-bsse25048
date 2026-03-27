#include "TutoringSession.h"



TutoringSession :: TutoringSession () {}
TutoringSession :: TutoringSession (int sessionID, double durationMinutes, 
                    TeachingAssistant* ta, Student* student) {
                        this->sessionID = sessionID;
                        this->durationMinutes = durationMinutes;
                        this->ta = ta;
                        this->student = student;
                    }
double TutoringSession :: getDuration() {
    return durationMinutes;
}
void TutoringSession :: displaySession() {
    cout<<"session ID: "<<sessionID<<endl;
}
TutoringSession TutoringSession :: operator+ (const TutoringSession& other) {
    TutoringSession session;
    session.durationMinutes = this->durationMinutes + other.durationMinutes;
    return session;
}
bool operator> (const TutoringSession& s1, const TutoringSession& s2) {
    return s1.durationMinutes>s2.durationMinutes;
}
