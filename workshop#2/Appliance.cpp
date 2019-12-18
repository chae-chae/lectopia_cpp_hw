#include "Appliance.h"
#include <iostream>
using namespace std;
#include <string>


Appliance::Appliance(){
    this->machineName = "";
    this->powerFlag = false;
}
Appliance::Appliance(string machineName,bool powerFlag){
    this->machineName = machineName;
    this->powerFlag = powerFlag;
}
string Appliance::getMachineName() const{
    return this->machineName;
}
bool Appliance::getPowerFlag() const{
    return this->powerFlag;
}
void Appliance::setMachineName(string machineName){
    this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag){
    this->powerFlag = powerFlag;
}
bool Appliance::turnOn(){
    if (this->powerFlag == true) {
        return false;
    } else {
        this-> powerFlag = true;
        return true;
    }
}
bool Appliance::turnOff(){
    if (this->powerFlag == false) {
        return false;
    } else {
        this-> powerFlag = false;
        return true;
    }
}
void Appliance::stateView(){
    cout << "제품명 : " << this->machineName;
    cout << " (";
    if (this->powerFlag == true) {
        cout << "ON";
    } else {
        cout << "OFF";
    }
    cout << ')';
}

