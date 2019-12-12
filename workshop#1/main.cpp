#include<iostream>
using namespace std;
#include "LightAutomation.h"

int menu(const char **menuList, int menuCnt); // 전달된 메뉴를 출력하고 정확한 메뉴번호를 리턴하는 함수
void displayTitle(string title); // 처리중인 내용 출력하기 위한 타이틀 출력함수
void screen(LightAutomation &rHa); // 주메뉴를 출력하고 메뉴를 선택받아 반복적으로 주메뉴를 처리하는 함수
void listDisplayAlliance(LightAutomation &r); // 등록된 전등의 상태출력
void controlAlliance(LightAutomation &r); // 등록된 전등 제어하기
void addAlliance(LightAutomation &r); // 전등 등록(동일한
void deleteAlliance(LightAutomation &r); // 전등 삭제
void myflush();

int main()
{
    LightAutomation homeAuto;
    //homeAuto.initLightAutomation(); 생성자로 대신함
    screen(homeAuto);
    return 0;
}

void screen(LightAutomation &r)
{
    const char *menuList[]={"전등 상태확인 ", "전등 제어 ", "전등 등록 ", "전등 삭제 ", "종료 "};
    int menuCnt = sizeof(menuList)/sizeof(menuList[0]);
    int menuNum;
    
    displayTitle("홈 조명 케어시스템 시작");
    while(true)
    {
        menuNum = menu(menuList, menuCnt);
        if(menuNum==menuCnt) {break;}
        switch(menuNum)
        {
            case 1 : listDisplayAlliance(r); break;
            case 2 : controlAlliance(r); break;
            case 3 : addAlliance(r); break;
            case 4 : deleteAlliance(r); break;
        }
    }
    displayTitle("홈 조명 케어시스템 종료");
    return;
}
void listDisplayAlliance(LightAutomation &r) // 등록된 전등의 상태출력
{
//    string machineName;
//    bool res;
    displayTitle("전등 상태 보기");
    if (r.getLightCnt() == 0) {
        cout << "등록된 전등이 없습니다" << endl;
	displayTitle("전등 상태 보기 종료");
        return;
    }
    r.listDisplayAlliance();

    displayTitle("전등 상태 보기 종료");
    //r의 멤버함수를 호출 r.listDisplayAlliance();               // 등록된 전등 전체 목록 및 On.Off 상태를 확인(출력)하다
}
void controlAlliance(LightAutomation &r) // 등록된 전등 제어하기
{
    string machineName;
    bool res;
    displayTitle("전등 제어 하기");
    if (r.getLightCnt() == 0) {
        cout << "등록된 전등이 없습니다. 전등을 먼저 등록하세요" << endl;
        return;
    }
    cout << "* 제어할 전등명 입력 : ";
    cin >> machineName;
    res = r.controlAlliance(machineName);
    if (res){
        cout << "전등명 : " << machineName << "의 제어가 완료되었습니다." << endl;
    } else {
        cout << "** 해당하는 제품이 존재하지 않습니다." << endl;
        cout << "전등명 : " << machineName << "의 제어가 실패하였습니다." << endl;
    }

}
void addAlliance(LightAutomation &r) // 전등 등록. 동일한 이름의 전등객체는 등록되지 않도록 함
{
    LightFixture temp;
    string machineName;
    bool res;
    displayTitle("전등 등록 하기");
    cout << "* 전등명 입력( 예)거실등, 안방등 등) : ";
    cin >> machineName;
    temp.setMachineName(machineName);
    res = r.addAlliance(temp);
    if (res){
        cout << "전등명 : " << machineName << "의 등록이 완료되었습니다." << endl;
    } else {
        cout << "전등명 : " << machineName << "의 등록이 실패하였습니다." << endl;
    }

}
void deleteAlliance(LightAutomation &r) // 전등 삭제
{
    string machineName;
    bool res;
    displayTitle("전등 삭제 하기");
    cout << "* 전등명 입력( 예)거실등, 안방등 등) : ";
    cin >> machineName;
    res = r.deleteAlliance(machineName);
    if (res){
        cout << "전등명 : " << machineName << "의 삭제가 완료되었습니다." << endl;
    } else {
        cout << "전등명 : " << machineName << "의 삭제가 실패하였습니다." << endl;
    }
}

int menu(const char **menuList, int menuCnt)
{
    int i, menuNum;
    cout << "\n=================================" << endl;
    for (i = 0; i<menuCnt; i++) {
        cout << i+1 << ". " << menuList[i] << endl;
    }
    cout << "=================================" << endl;
    cout << "# 메뉴번호를 입력하세요 : ";
    cin >> menuNum;
    
    while (cin.get() != '\n') {
        myflush();
        cout << "# 메뉴번호를 입력하세요 : ";
        cin >> menuNum;
    }
    return menuNum;
}
void displayTitle(string title) // 화면 타이틀 출력 함수
{
    cout << endl << "------------------------------" << endl;
    cout << "    " << title << endl;
    cout << "------------------------------" <<endl;
}

void myflush(){
    cin.clear();
    while (cin.get() != '\n');
}
