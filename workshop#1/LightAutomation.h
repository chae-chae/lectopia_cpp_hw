#ifndef __LIGHTAUTOMATION_H__
#define    __LIGHTAUTOMATION_H__

#pragma once
#include "LightFixture.h"
#define LIGHT_MAX_CNT 5 // 최대 등록 가능한 전등의 개수
#include <iostream>
using namespace std;
#include <string>


class LightAutomation
{
public :
    
    //void initLightAutomation(); // lightArray의 메모리 영역을 모두 0으로 초기화 하고, lightCnt를 0으로 초기화
    //생성자만들기
    LightAutomation();    
    // getter, setter member function
    LightFixture * getLightArray(); // lightArray 멤버 값 반환 함수
    int getLightCnt() const ;       // lightCnt 멤버 값 반환 함수
    
    // member function // lightauto.cpp 에 다 정의하기
    bool addAlliance(LightFixture &ap);          // parameter의 전등객체를 목록에 추가. 동일한 이름의 전등객체는 등록되지 않도록 함
    int searchMachine(string machineName);    // 전등명에 해당하는 전등을 찾아서 배열의 index리턴/없을 시 -1 리턴
    bool deleteAlliance(string machineName);  // 전등명에 해당하는 전등을 목록에서 삭제하다
    void listDisplayAlliance();               // 등록된 전등 전체 목록 및 On.Off 상태를 확인(출력)하다
    bool controlAlliance(string machineName); // 해당 전등의 상태를 변경한다. (On->Off, Off->On 으로 변경)
private :
    LightFixture lightArray[LIGHT_MAX_CNT];   // 등록된 전등 객체의 정보 저장 배열
    int lightCnt; // 등록된 전등객체의 개수 저장
};
#endif
