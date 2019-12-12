#include "LightFixture.h"
#include "LightAutomation.h"
#include <iostream>
using namespace std;
#include <string>

LightAutomation::LightAutomation(){
    this->lightCnt = 0;
}
LightFixture * LightAutomation::getLightArray(){
    return this->lightArray;
}
int LightAutomation::getLightCnt() const{
    return this->lightCnt;
}

bool LightAutomation::addAlliance(LightFixture &ap){
    for (int i = 0; i<this->lightCnt; i++) {
        if (this->lightArray[i].getMachineName() == ap.getMachineName()){
            return false;
        }
    }
    if (this->lightCnt < LIGHT_MAX_CNT) {
        this->lightArray[lightCnt].setMachineName(ap.getMachineName());
        this->lightArray[lightCnt].setPowerFlag(ap.getPowerFlag());
        this->lightCnt++;
        return true;
    } else {
        return false;
    }
    
}
int LightAutomation::searchMachine(string machineName){
    for (int i = 0; i<this->lightCnt; i++) {
        if (this->lightArray[i].getMachineName() == machineName) {
            return i;
        }
    }
    return -1;
}
bool LightAutomation::deleteAlliance(string machineName){
    for (int i = 0; i<this->lightCnt; i++) {
        if (this->lightArray[i].getMachineName() == machineName) {
            for (int j = i; j<lightCnt-1; j++){
                this->lightArray[j].setMachineName(lightArray[j+1].getMachineName());
                this->lightArray[j].setPowerFlag(lightArray[j+1].getPowerFlag());
            }
            lightCnt--;
            this->lightArray[lightCnt].setMachineName("");
            this->lightArray[lightCnt].setPowerFlag(false);
            return true;
        }
    }
    return false;
}
void LightAutomation::listDisplayAlliance(){
//    if (this->lightArray[0].getMachineName() == "") {
//        cout << "등록된 전등이 없습니다" << endl;
//        return;
//    }
    for (int i = 0; i<this->lightCnt; i++) {
        this->lightArray[i].stateView();
    }
}
bool LightAutomation::controlAlliance(string machineName){
    for (int i = 0; i<this->lightCnt; i++) {
        if (this->lightArray[i].getMachineName() == machineName) {
            if (this->lightArray[i].getPowerFlag()){
                this->lightArray[i].turnOff();
                return true;
            } else {
                this->lightArray[i].turnOn();
                return true;
            }
        }
    }
    return false;
}
