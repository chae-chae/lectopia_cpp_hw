#include "HomeAutomation.h"

HomeAutomation::HomeAutomation(){
    for (int i = 0; i<APPLIANCE_MAX_CNT; i++) {
        this->applianceArray[i] = NULL;
    }
    this->applianceCnt = 0;
} // appliaceArray의 메모리 영역을 모두 0으로 초기화 하고, applianceCnt를 0으로 초기화
HomeAutomation::HomeAutomation(const HomeAutomation &r){
    this->applianceCnt = r.applianceCnt;
    for (int i = 0; i<applianceCnt; i++) {
        if (dynamic_cast<AirConditioner *>(r.applianceArray[i])) {
            this->applianceArray[i] = new AirConditioner;
            this->applianceArray[i] = r.applianceArray[i];
        } else if (dynamic_cast<Washer *>(r.applianceArray[i])){
            this->applianceArray[i] = new Washer;
            this->applianceArray[i] = r.applianceArray[i];
        } else if (dynamic_cast<RiceCooker *>(r.applianceArray[i])){
            this->applianceArray[i] = new RiceCooker;
            this->applianceArray[i] = r.applianceArray[i];
        } else {
            cout << "넌 뭐니???";
        }
    }
    for (int i = applianceCnt; i<APPLIANCE_MAX_CNT; i++) {
        this->applianceArray[i] = NULL;
    }
} // deep copy constructor
HomeAutomation::~HomeAutomation(){
    for (int i = 0; i<applianceCnt; i++) {
        delete this->applianceArray[i];
        this->applianceArray[i] = NULL;
    }
} // applianceArray에 동적 할당된 객체를 모두 해제함


// getter, setter member function
Appliance ** HomeAutomation::getApplianceArray(){
    return this->applianceArray;
} // applianceArray 멤버 값 반환 함수
int HomeAutomation::getApplianceCnt() const {
    return this->applianceCnt;
}// applianceCnt 멤버 값 반환 함수

// member function
HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r){
    if (this == &r) return *this; // 나한테 나를 대입하는지 확인하는 필수코드
    for (int i = 0; i<applianceCnt; i++) {
        delete this->applianceArray[i];
        this->applianceArray[i] = NULL;
    }
    this->applianceCnt = r.applianceCnt;
    for (int i = 0; i<applianceCnt; i++) {
        if (dynamic_cast<AirConditioner *>(r.applianceArray[i])) {
            this->applianceArray[i] = new AirConditioner;
            this->applianceArray[i] = r.applianceArray[i];
        } else if (dynamic_cast<Washer *>(r.applianceArray[i])){
            this->applianceArray[i] = new Washer;
            this->applianceArray[i] = r.applianceArray[i];
        } else {/*if (dynamic_cast<RiceCooker *>(r.applianceArray[i])){*/
            this->applianceArray[i] = new RiceCooker;
            this->applianceArray[i] = r.applianceArray[i];
        }
    }
    for (int i = applianceCnt; i<APPLIANCE_MAX_CNT; i++) {
        this->applianceArray[i] = NULL;
    }
    return *this;
} // 대입(할당)연산자 오버로딩 함수
bool HomeAutomation::addAppliance(Appliance *ap){
    if (applianceCnt == APPLIANCE_MAX_CNT) { // 맥스만큼 찼으면 바로 나오게하자
        return false;
    }
    int index;
    index = this->searchMachine(ap->getMachineName()); // 찾으면 그방 아니면 -1
    if (index == -1) { //이름이 없다면 추가가능
        if (dynamic_cast<AirConditioner *>(ap)) {
            this->applianceArray[applianceCnt] = new AirConditioner(ap->getMachineName(), ap->getPowerConsumption());
            this->applianceCnt++;

        } else if (dynamic_cast<Washer *>(ap)) {
            this->applianceArray[applianceCnt] = new Washer(ap->getMachineName(), ap->getPowerConsumption());
            this->applianceCnt++;
        } else {/*if (dynamic_cast<RiceCooker *>(ap)) {*/
            this->applianceArray[applianceCnt] = new RiceCooker(ap->getMachineName(), ap->getPowerConsumption());
            this->applianceCnt++;
        }
        return true;
    } else {
        return false;
    }
}    // 가전제품을 목록에 추가.  동일한 제품명 추가 불가능.
int HomeAutomation::searchMachine(string machineName){
    for (int i = 0; i<applianceCnt; i++) {
        if (this->applianceArray[i]->getMachineName() == machineName) {
            return i;
        }
    }
    return -1;
} // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
bool HomeAutomation::deleteAppliance(string machineName){
    if (applianceCnt == 0) { //암것두 없다면 그냥 바로
        return false;
    }
    int index;
    char yn;
    index = this->searchMachine(machineName); // 찾으면 그방 아니면 -1
    if (index == -1) { // 찾는 이름 없으면 바로
        return false;
    } else {
        cout << "** 정말로 삭제하겠습니까?(y/n) : ";
        cin >> yn;
        if (yn == 'Y' || yn == 'y'){ // 네 삭제
            delete this->applianceArray[index]; // 할당 해제
            applianceCnt--; // 삭제했으니까 여기서 수 줄이면 밑에서 그냥 씨엔티라고 쭉 써도됨
            for (int i = index; i<applianceCnt ; i++) { // index방부터 줄어든 cnt번방까지 땡기기
                applianceArray[i] = applianceArray[i+1]; //하나 뒤에거 땡기기
            }
            applianceArray[applianceCnt] = NULL;
            return true;
        } else { // 아니오 혹은 다른글자하면 안지움
            return false;
        }
    }
} // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
void HomeAutomation::listDisplayAppliance(){
    for (int i = 0; i<applianceCnt; i++) {
        if (dynamic_cast<AirConditioner *>(applianceArray[i])) {
            (dynamic_cast<AirConditioner *>(applianceArray[i]))->stateView();
        } else if (dynamic_cast<Washer *>(applianceArray[i])) {
            (dynamic_cast<Washer *>(applianceArray[i]))->stateView();
        } else {
            (dynamic_cast<RiceCooker *>(applianceArray[i]))->stateView();
        }
    }
} // 등록된 가전제품 전체 목록 및 상태를  확인하다
bool HomeAutomation::controlAppliance(string machineName){ // on off 상세처리부르기
    int index;
    char yn;
    index = this->searchMachine(machineName);
    if (index == -1) { //찾는 이름이 없다
        cout << "** 해당하는 제품이 존재하지 않습니다." << endl;
        return false;
    } else { // 존재하면
        if (this->applianceArray[index]->getPowerFlag() == false){ // 꺼져있으면 킬지말지
            cout << "전원을 켜시겠습니까? (Y/N) : ";
            cin >> yn;
            if (yn == 'N' || yn == 'n') { //꺼져잇는데 끄겟다(안키겟다)
                return true; // 그냥 트루리턴하고 가기
            } else if (yn == 'Y' || yn == 'y'){
                this->applianceArray[index]->turnOn(); //전원 on
                setStateAppliance(applianceArray[index]);
            }
        } else { // 켜져있으면 바로
            setStateAppliance(applianceArray[index]);
        }
    }
    return true;
}   // 해당 가전제품을 제어하다
void HomeAutomation::setStateAppliance(Appliance * ap){ // 상세처리
    int state;
    int temper;
    if (dynamic_cast<AirConditioner *>(ap)) {
        while(true)
        {
            state = inputInteger("1.송풍 / 2.냉방 / 3.난방 / 4.끄기 : ");
                if (state > 0 && state <= 3) {
                    break;
                } else if (state == 4){
                    ap->turnOff();
                    ap->stateView();
                    return;
                }
        }
        (dynamic_cast<AirConditioner *>(ap))->setMachineState(state);
        while (true)
        {
            temper = inputInteger("1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : ");
            if (temper == 1){
                dynamic_cast<AirConditioner *>(ap)->operator++();
            } else if (temper == 2){
                dynamic_cast<AirConditioner *>(ap)->operator--();
            } else if (temper == 3){
                break;
            }
        }
        ap->stateView();
        return;
    } else if (dynamic_cast<Washer *>(ap)) {
        while(true)
        {
            state = inputInteger("1.무동작 / 2.일반빨래 / 3.삶은빨래 / 4.건조 / 5.끄기 : ");
            if (state > 0 && state <= 4) {
                break;
            } else if (state == 5){
                ap->turnOff();
                ap->stateView();
                return;
            }
        }
        (dynamic_cast<Washer *>(ap))->setMachineState(state);
        ap->stateView();
    } else {/*if (dynamic_cast<RiceCooker *>(ap)) {*/
        while(true)
        {
            state = inputInteger("1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : ");
            if (state > 0 && state <= 4) {
                break;
            } else if (state == 5){
                ap->turnOff();
                ap->stateView();
                return;
            }
        }
        (dynamic_cast<RiceCooker *>(ap))->setMachineState(state);
        ap->stateView();
    }
} // 켜져있는 가전제품의 상태를 변경하다
