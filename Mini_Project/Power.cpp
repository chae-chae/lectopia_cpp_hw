#include "Power.h"
#include "HomeAutomation.h"



int Power::calPowerConsumption(HomeAutomation &rHa){
    int sumPower = 0;
    
    for (int i = 0; i<rHa.getApplianceCnt(); i++) {
        rHa.applianceArray[i]->turnOff();
        sumPower += rHa.applianceArray[i]->getPowerConsumption()*(rHa.applianceArray[i]->getUseHour()/60.0);
    }
    return sumPower;
} // Power class의 calPowerConsumption()멤버함수를 friend 등록
