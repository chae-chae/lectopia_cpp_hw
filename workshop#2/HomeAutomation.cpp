#include "HomeAutomation.h"
#include <iostream>
using namespace std;
#include <string>

HomeAutomation::HomeAutomation(){
    for (int i = 0; i<Appliance_MAX_CNT; i++) {
        this->riceCookerArray[i] = NULL;
    }
    this->riceCookerCnt = 0;
}// riceCookerArray의 메모리 영역을 모두 0으로 초기화 하고, riceCookerCnt를 0으로 초기화
HomeAutomation::HomeAutomation(const HomeAutomation &r){
    for (int i = 0; i<Appliance_MAX_CNT; i++) {
        this->riceCookerArray[i] = NULL;
    }
    this->riceCookerCnt = r.riceCookerCnt;
    for (int i = 0; i<riceCookerCnt; i++) {
        this->riceCookerArray[i] = new RiceCooker;
        this->riceCookerArray[i]->setMachineName(r.riceCookerArray[i]->getMachineName());
        this->riceCookerArray[i]->setPowerFlag(r.riceCookerArray[i]->getPowerFlag());
        this->riceCookerArray[i]->setMachineState(r.riceCookerArray[i]->getMachineState());
    }
} // deep copy constructor
HomeAutomation::~HomeAutomation(){
    for (int i = 0; i<riceCookerCnt; i++) {
        delete riceCookerArray[i];
    }
} // riceCookerArray에 동적 할당된 객체를 모두 해제함


RiceCooker ** HomeAutomation::getRiceCookerArray(){
    return this->riceCookerArray;
} // riceCookerArray 멤버 값 반환 함수
int HomeAutomation::getRiceCookerCnt() const{
    return this->riceCookerCnt;
} // riceCookerCnt 멤버 값 반환 함수

HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r){
    if (this == &r) return *this;
    for (int i = 0; i<riceCookerCnt; i++) {
        delete riceCookerArray[i];
    }
    this->riceCookerCnt = r.riceCookerCnt;
    for (int i = 0; i<riceCookerCnt; i++) {
        this->riceCookerArray[i] = new RiceCooker;
        this->riceCookerArray[i]->setMachineName(r.riceCookerArray[i]->getMachineName());
        this->riceCookerArray[i]->setPowerFlag(r.riceCookerArray[i]->getPowerFlag());
        this->riceCookerArray[i]->setMachineState(r.riceCookerArray[i]->getMachineState());
    }
    return *this;
} // 대입(할당)연산자 오버로딩 함수
bool HomeAutomation::addAppliance(RiceCooker *ap){
    int res;
    res = this->searchMachine(ap->getMachineName());
    if (res == -1 && this->riceCookerCnt < Appliance_MAX_CNT) {
        //if (this->riceCookerCnt < Appliance_MAX_CNT) {
        this->riceCookerArray[riceCookerCnt] = new RiceCooker;
        this->riceCookerArray[riceCookerCnt]->setMachineState(ap->getMachineState());
        this->riceCookerArray[riceCookerCnt]->setMachineName(ap->getMachineName());
        this->riceCookerArray[riceCookerCnt]->setPowerFlag(ap->getPowerFlag());
        this->riceCookerCnt++;
        return true;
        //}
    }
    return false;
}    // 가전제품을 목록에 추가. 동일한 제품명의 밥솥은 등록 불가
int HomeAutomation::searchMachine(string machineName){
    for (int i = 0; i<this->riceCookerCnt; i++) {
        if (this->riceCookerArray[i]->getMachineName() == machineName){
            return i;
        }
    }
    return -1;
} // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
bool HomeAutomation::deleteAppliance(string machineName){
    int res = this->searchMachine(machineName);
    if (res == -1) {
        return false;
    } else {
        delete riceCookerArray[res];
        for (int i = res; i < riceCookerCnt-1; i++){
//            riceCookerArray[i] = NULL;
            riceCookerArray[i] = riceCookerArray[i+1];
        }
        riceCookerCnt--;
        riceCookerArray[riceCookerCnt] = NULL;
//        delete riceCookerArray[riceCookerCnt];
        //        this->riceCookerArray[riceCookerCnt]->setMachineState(1);
        //        this->riceCookerArray[riceCookerCnt]->setPowerFlag(false);
        //        this->riceCookerArray[riceCookerCnt]->setMachineName("");
        return true;
    }
} // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
void HomeAutomation::listDisplayAppliance(){
    for (int i = 0; i<this->riceCookerCnt; i++) {
        this->riceCookerArray[i]->stateView();
    }
} // 등록된 가전제품 전체 목록 및 상태를  확인하다
bool HomeAutomation::controlAppliance(string machineName){
    int res;
    char yn;
    res = this->searchMachine(machineName);
    if (res == -1) { //찾는 이름이 없다
        cout << "** 해당하는 제품이 존재하지 않습니다." << endl;
        return false;
    } else { // 밥솥이 있다
        if (this->riceCookerArray[res]->getPowerFlag() == false) { //꺼져있으면 킬지끌지
            cout << "전원을 켜시겠습니까? (Y/N) : ";
            cin >> yn;
            if (yn == 'N' || yn == 'n') { //꺼져잇는데 끄겟다(안키겟다)
                return true; // 그냥 트루리턴
            } else if (yn == 'Y' || yn == 'y'){ //꺼져잇는데 키겟다
                this->riceCookerArray[res]->setPowerFlag(true);
                this->setStateAppliance(this->riceCookerArray[res]);
            }
        } else { //켜져잇으면 바로
            this->setStateAppliance(this->riceCookerArray[res]);
        }
    }
    return true;
}
void HomeAutomation::setStateAppliance(RiceCooker * ap){
    int state;
    cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : ";
    cin >> state;
    if (state == 5) { // 끄겟다면 끄고 리턴트루
        ap->setPowerFlag(false);
        ap->RiceCooker::stateView();
        return;
    }
    ap->setMachineState(state);
    ap->RiceCooker::stateView();
} // 켜져있는 가전제품의 상태를 변경하다

