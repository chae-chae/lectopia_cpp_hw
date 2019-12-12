#include "LightFixture.h"
#include <iostream>
using namespace std;
#include <string>



LightFixture::LightFixture(){
    this->machineName = "";
    this->powerFlag = false;
}

LightFixture::LightFixture(string machineName, bool powerFlag){
    this->machineName = machineName;
    this->powerFlag = powerFlag;
}

string LightFixture::getMachineName() const{
    return this->machineName;
}
bool LightFixture::getPowerFlag() const{
    return this->powerFlag;
}
void LightFixture::setMachineName(string machineName){
    this->machineName = machineName;
}
void LightFixture::setPowerFlag(bool powerFlag){
    this->powerFlag = powerFlag;
}
bool LightFixture::turnOn(){
    if (this->powerFlag == true) {
        return false;
    } else {
        this-> powerFlag = true;
        return true;
    }
}
bool LightFixture::turnOff(){
    if (this->powerFlag == false) {
        return false;
    } else {
        this-> powerFlag = false;
        return true;
    }
}
void LightFixture::stateView(){
    cout << "제품명 : " << this->machineName;
    cout << " (";
    if (this->powerFlag == true) {
        cout << "ON";
    } else {
        cout << "OFF";
    }
    cout << ')' << endl;
}

