#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include "Robot.h"


Robot::Robot() // name은 Null string("") 생성자에서 1바이트만 t할당해주고, energy는 0으로 초기화
{
    this->name = new char[1]; // new char [strlen("")+1];
    strcpy(this->name, ""); // this->name[0] = '\0';
    this->energy = 0;
}
Robot::~Robot() // delete해주기
{
    delete [] this->name;
}
Robot::Robot(const char *name, int energy) // name받아야함
{
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    if(energy >= 0) {
        this->energy = energy;
    } else {
        this->energy = 0;
    }
}
Robot::Robot(const Robot& r) //복사생성자에도 const해주기 원본인 애가 바뀌지않게, Deep Copy 필요
{
    this->name = new char[strlen(r.name)+1];
    strcpy(this->name, r.name);
    this->energy = r.energy; //get에너지나 겟네임 되지만 굳이 그럴필요 없음 비효율적
}
void Robot::errPrn() // 에너지 부족- 에러메시지 출력
{
    cout << "에너지 부족" << endl;
}
void Robot::go()              // 전진 메시지 출력 후 에너지 10 감소 // 에너지가 10만큼 있는지 검사하고 움직여야함
{
    if(this->energy < 10){
        this->errPrn();
    } else {
        cout << this->name << " 전진..." << endl;
        this->energy -= 10;
    }
}
void Robot::back()          // 후진 메시지 출력 후 에너지 20 감소 // 에너지 양이 20 이상입니까? 20미만이면 errPrn()호출해주기, 20이상이면 후진메시지 나오게
{
    if(this->energy < 20){
        this->errPrn();
    } else {
        cout << this->name << " 후진..." << endl;
        this->energy -= 20;
    }
}
void Robot::turn()            // 턴 메시지 출력 후 에너지 30 감소
{
    if(this->energy < 30){
        this->errPrn();
    } else {
        cout << this->name << " 턴..." << endl;
        this->energy -= 30;
    }
}
void Robot::jump()       // 점프 메시지 출력 후 에너지 40 감소
{
    if(this->energy < 40){
        this->errPrn();
    } else {
        cout << this->name << " 점프..." << endl;
        this->energy -= 40;
    }
}
void Robot::charge(int e)      // e값 만큼 충전 // 현재 에너지 양이 50이 있는데 100을 충전하면 150 됨. 에너지 충전할 양이 음수일수는 없으니까 e값이 음수인지 체크필요
{
    if (e > 0){
        cout << this->name << "에너지 " << e << " 충전..." << endl;
        this->energy += e;
    }
}
char *Robot::getName()const      // name멤버의 값 리턴 // name이라는 멤버의 주소만 리턴해주면 된다. return name; 간단한 코드
{
    return this->name;
}
void Robot::setName(const char * name)   // name멤버의 값을 전달된 문자열로 재 초기화 // 똘똘이->신사임당 // 기존메모리 해제하고 신사임당들어갈 만큼 다시 할당하고 거기에 복사해주기
{
    delete [] this->name;
    this->name = new char [strlen(name) + 1];
    strcpy(this->name, name);
}
int Robot::getEnergy()const        // energy멤버의 값 리턴  // 그냥 return energy하면 끝
{
    return this->energy;
}
void Robot::setEnergy(int e)    // energy멤버의 값을 전달된 숫자로 재 초기화 0이상이면 셋 // charge랑은 다름 원래 100에너지있었는데 50이 들어오면 50으로 바뀜, 여기도 음수체크
{
    if (e >= 0){
        this->energy = e;
    }
}
