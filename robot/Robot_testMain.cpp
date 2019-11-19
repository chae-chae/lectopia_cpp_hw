#include <iostream>
using namespace std;
#include "Robot.h"

void initRobot(Robot *rp, int cnt); // 로봇을 초기화 시키고 오는 함수
void workRobot(Robot *rp, int cnt); // 로봇에게 일을 시키는 함수 로봇명 쫙 보여주고 1.전진 2.후진 이런거뜨게
void printRobot(Robot *rp, int cnt); // 로봇 이름, 에너지랑 출력해주는 함수
void myflush();
void chooseWork(Robot *rp);

int main(){
    Robot *rp;
    int cnt;
    
    cout << "구입할 로봇 대수를 입력하시오 : ";
    cin >> cnt;
    while (cin.get() != '\n') {
        myflush();
        cout << "구입할 로봇 대수를 입력하시오 : ";
        cin >> cnt;
    }
    
    rp = new Robot[cnt]; // 로봇 cnt만큼 만들어짐
    
    initRobot(rp, cnt); // 로봇을 초기화 시키고 오는 함수
    workRobot(rp, cnt); // 로봇에게 일을 시키는 함수 로봇명 쫙 보여주고 1.전진 2.후진 이런거뜨게
    printRobot(rp, cnt); // 로봇 이름, 에너지랑 출력해주는 함수
    
    delete [] rp; // 로봇 해제
    
    return 0;
}
void initRobot(Robot *rp, int cnt){
    char tname[100];
    int en;
    for (int i = 0; i<cnt; i++){
        cout << i+1 << "번 로봇 명을 입력하시오 : ";
        cin >> tname;
        (rp+i)->setName(tname);
        
        cout << (rp+i)->getName() << "의 에너지 양을 입력하시오 : ";
        cin >> en;
//        while (cin.get() != '\n') {
//            myflush();
//            cout << "잘못된 입력입니다. 에너지 양엔 숫자만 입력하세요 : ";
////            cin >> en;
//        }
        (rp+i)->setEnergy(en);
        //cout << (rp+i)->getEnergy() << endl;
    }
    myflush();
}
void workRobot(Robot *rp, int cnt){
    char tname[100];
    while (1){
        cout << "# 로봇명 선택(";
        for (int i = 0; i<cnt-1; i++){
            cout << (rp+i)->getName() << ", ";
        }
        cout << (rp+cnt-1)->getName() << ") : ";
        cin.getline(tname, sizeof(tname));
        if(tname[0] == '\0'){ //enter 입력시 루프빠져나옴
            break;
        }
        //        cout << tname;
        for (int i = 0; i<cnt; i++){
            if (strcmp(tname, (rp+i)->getName()) == 0){
                chooseWork(rp+i);
                break;
            }
        }
    }
}
void printRobot(Robot *rp, int cnt){
    for (int i = 0; i<cnt ; i++) {
        cout << i+1 << ". " << (rp+i)->getName() << " : " << (rp+i)->getEnergy() << endl;
    }
}
void myflush(){
    cin.clear();
    while (cin.get() != '\n');
}
void chooseWork(Robot *rp){
    int sel;
    cout << "# 할 일 선택 (1.전진 / 2.후진 / 3.회전 / 4.점프 / 5.충전) : ";
    cin >> sel;
    switch (sel) {
        case 1:
            rp->go();
            break;
        case 2:
            rp->back();
            break;
        case 3:
            rp->turn();
            break;
        case 4:
            rp->jump();
            break;
        case 5:
            int e;
            cout << "# 충전할 에너지 양 입력 : ";
            cin >> e;
            rp->charge(e);
            break;
        default:
            break;
    }
    myflush();
}
