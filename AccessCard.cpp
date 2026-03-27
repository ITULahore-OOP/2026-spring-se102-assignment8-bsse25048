#include "AccessCard.h"




AccessCard :: AccessCard () {}
AccessCard :: AccessCard (string cardID, int accessLevel) {
    this->cardID = cardID;
    this->accessLevel = accessLevel;
}
string AccessCard :: getCardID() {
    return cardID;
}
int AccessCard :: getAccessLevel() {
    return accessLevel;
}
void AccessCard :: displayCardInfo() {
    cout<<"card ID: "<< cardID << endl;
    cout<<"access level"<< accessLevel << endl;
}