#include "RiceCooker.h"
#include <iostream>
using namespace std;
#include <string>

RiceCooker::RiceCooker() : Appliance(){
    this->machineState = NO_OPERATION;
}
RiceCooker::RiceCooker(string machineName) : Appliance(machineName){
    this->machineState = NO_OPERATION;
}
int RiceCooker::getMachineState() const{
    return this->machineState;
}
void RiceCooker::setMachineState(int machineState){
    this->machineState = machineState;
}
void RiceCooker::stateView(){
    Appliance::stateView();
    if (getPowerFlag() == false) {
        cout << endl;
        return;
    }
    if (getPowerFlag() == true) {
        cout << " 설정 상태 : ";
        switch (this->machineState) {
            case 1:
                cout << "무동작";
                break;
            case 2:
                cout << "보온";
                break;
            case 3:
                cout << "밥짓기";
                break;
            case 4:
                cout << "데우기";
                break;
            default:
                break;
        }
        cout << endl;
    }
}
