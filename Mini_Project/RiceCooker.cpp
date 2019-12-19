#include "RiceCooker.h"


RiceCooker::RiceCooker() : Appliance(), machineState(NO_OPERATION){
} // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
RiceCooker::RiceCooker(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption), machineState(NO_OPERATION) {
} // Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
int RiceCooker::getMachineState() const{
    return this->machineState;
} // machineState 멤버 값 반환 함수
void RiceCooker::setMachineState(int machineState){
    this->machineState = machineState;
} // machineState 멤버 초기화 함수
// member function
void RiceCooker::stateView(){
    cout << "제품명 : " << this->getMachineName();
    cout << " (";
    if (this->getPowerFlag() == true) {
        cout << "ON) 설정 상태 : ";
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
    } else {
        cout << "OFF)" << endl;
        return;
    }
} // 객체의 상태 출력
