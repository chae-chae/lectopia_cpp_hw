#ifndef __HOMEAUTOMATION_H__
#define    __HOMEAUTOMATION_H__
#include "Appliance.h"
#include "RiceCooker.h"

#define Appliance_MAX_CNT 5 // 최대 등록 가능한 가전제품의 개수

class HomeAutomation
{
public :
    HomeAutomation(); // riceCookerArray의 메모리 영역을 모두 0으로 초기화 하고, riceCookerCnt를 0으로 초기화
    HomeAutomation(const HomeAutomation &r); // deep copy constructor
    ~HomeAutomation(); // riceCookerArray에 동적 할당된 객체를 모두 해제함
    
    // getter, setter member function
    RiceCooker ** getRiceCookerArray(); // riceCookerArray 멤버 값 반환 함수
    int getRiceCookerCnt() const ; // riceCookerCnt 멤버 값 반환 함수
    
    // member function
    HomeAutomation & operator=(const HomeAutomation &r); // 대입(할당)연산자 오버로딩 함수
    bool addAppliance(RiceCooker *ap);    // 가전제품을 목록에 추가. 동일한 제품명의 밥솥은 등록 불가
    int searchMachine(string machineName); // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
    bool deleteAppliance(string machineName); // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
    void listDisplayAppliance(); // 등록된 가전제품 전체 목록 및 상태를  확인하다
    bool controlAppliance(string machineName);   // 해당 가전제품을 제어하다
    void setStateAppliance(RiceCooker * ap); // 켜져있는 가전제품의 상태를 변경하다
private :
    RiceCooker * riceCookerArray[Appliance_MAX_CNT]; // 등록된 밥솥 객체의 정보 저장 배열(동적객체 할당 후 주소저장)
    int riceCookerCnt; // 등록된 밥솥 객체의 개수 저장
};
#endif
