#include "Washer.h"

Washer::Washer() : Appliance(), machineState(NO_OPERATION){
} // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
Washer::Washer(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption), machineState(NO_OPERATION){
} // Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화

// getter, setter member function
int Washer::getMachineState() const{
    return this->machineState;
} // machineState 멤버 값 반환 함수
void Washer::setMachineState(int machineState){
    this->machineState = machineState;
} // machineState 멤버 초기화 함수
// member function
void Washer::stateView(){
    cout << "제품명 : " << this->getMachineName();
    cout << " (";
    if (this->getPowerFlag() == true) {
        cout << "ON) 설정 상태 : ";
        switch (this->machineState) {
            case 1:
                cout << "무동작";
                break;
            case 2:
                cout << "일반빨래";
                break;
            case 3:
                cout << "삶은빨래";
                break;
            case 4:
                cout << "건조";
                break;
            default:
                break;
        }
        cout << endl;
    } else {
        cout << "OFF)" << endl;
        return;
    }
}  // 객체의 상태 출력
