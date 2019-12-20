#include "Appliance.h"


Appliance::Appliance(){
    this->machineName = "";
    this->powerFlag = false;
    this->powerConsumption = 0;
    this->startHour = 0;
    this->useHour = 0;
}
Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour){
    this->machineName = machineName;
    this->powerFlag = powerFlag;
    this->powerConsumption = powerConsumption;
    this->startHour = startHour;
    this->useHour = useHour;
}
string Appliance::getMachineName() const{
    return this->machineName;
}  // machineName 멤버값 반환 함수
bool Appliance::getPowerFlag() const{
    return this->powerFlag;
} // powerFlag 멤버 값 반환 함수
int Appliance::getPowerConsumption() const{
    return this->powerConsumption;
} // powerConsumtion 멤버 값 반환 함수
time_t Appliance::getStartHour(){
    return this->startHour;
} // startHour 멤버 값 반환 함수
time_t Appliance::getUseHour(){
    return this->useHour;
} // useHour 멤버 값 반환 함수
void Appliance::setMachineName(string machineName){
    this->machineName = machineName;
}  // machineName 멤버 초기화 함수
void Appliance::setPowerFlag(bool powerFlag){
    this->powerFlag = powerFlag;
} // powerFlag 멤버 초기화 함수
void Appliance::setPowerConsumption(int powerConsumption){
    this->powerConsumption = powerConsumption;
} // powerConsumtion 멤버 초기화 함수
