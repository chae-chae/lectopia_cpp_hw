#include "AirConditioner.h"

AirConditioner::AirConditioner(): Appliance(), machineState(SENDAIR){
    this->setTemperature = 25;
} // Appliance는 default 생성자로 생성, machineState는 송풍으로 초기화
AirConditioner::AirConditioner(string machineName, int powerConsumption): Appliance(machineName, powerConsumption), machineState(SENDAIR){
    this->setTemperature = 25;
}// Appliance는 Overloaded 생성자로 생성, machineState는 송풍으로 초기화
// getter, setter member function
int AirConditioner::getMachineState() const{
    return machineState;
} // machineState 멤버값 반환 함수
int AirConditioner::getSetTemperature() const{
    return setTemperature;
}  // setTemperature 멤버값 반환 함수
void AirConditioner::setMachineState(int machineState){
    this->machineState = machineState;
} // machineState 멤버 초기화 함수
void AirConditioner::setSetTemperature(int setTemperature){ // 25도 기본
    this->setTemperature = setTemperature;
} // setTemperature 멤버 초기화 함수
// member function
AirConditioner & AirConditioner::operator++(){
    this->setTemperature++;
    return *this;
} // 설정 온도를 1도씩 올린다(prefix increment)
AirConditioner & AirConditioner::operator--(){
    this->setTemperature--;
    return *this;
} // 설정 온도를 1도씩 내린다(prefix decrement)
AirConditioner AirConditioner::operator++(int){
    AirConditioner temp(*this);
    this->setTemperature++;
    return temp;
} // 설정 온도를 1도씩 올린다(postfix increment)
AirConditioner AirConditioner::operator--(int){
    AirConditioner temp(*this);
    this->setTemperature--;
    return temp;
} // 설정 온도를 1도씩 내린다(postfix decrement)
void AirConditioner::stateView(){
    cout << "제품명 : " << this->getMachineName();
    cout << " (";
    if (this->getPowerFlag() == true) {
        cout << "ON) 설정 상태 : ";
        switch (this->machineState) {
            case 1:
                cout << "송풍";
                break;
            case 2:
                cout << "냉방";
                break;
            case 3:
                cout << "난방";
                break;
            default:
                break;
        }
        cout << "(설정온도 : " << this->getSetTemperature() << ')' << endl;
    } else {
        cout << "OFF)" << endl;
        return;
    }
}  // 객체의 상태 출력
