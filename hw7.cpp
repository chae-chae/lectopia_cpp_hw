#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

struct Savings{
    int w500;
    int w100;
    int w50;
    int w10;
};

void init(Savings &s);
void input(int &unit, int &cnt);
void save(Savings &s, int unit, int cnt);
int total(Savings &s);

int main(){
    
    Savings m;
    int unit, cnt;
    init(m);
    
    while (1) {
        input(unit, cnt);
        if (unit < 0){
            break;
        }
        save(m, unit, cnt);
    }
    cout << "총 저금액 : " << total(m) << endl;
    return 0;
}

void init(Savings &s){ //동전 모두 0개로 초기화
	s.w10 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w500 = 0;
}

void input(int &unit, int &cnt){
    while (1){
        cout << "동전의 금액 : ";
        cin >> unit;
        if (cin.fail() == true) { //문자받으면
            unit = -1;
            cin.clear();
            break;
        }
        if (unit != 500 && unit != 100 && unit != 50 && unit != 10){
            continue;
        }
        cout << "동전의 개수 : ";
        cin >> cnt;
        if (cin.fail() == true) { //문자받으면
            unit = -1;
            cin.clear();
            break;
        }
        break;
    }
    return;
}
void save(Savings &s, int unit, int cnt){ //동전의 개수를 저장
    switch (unit) {
        case 500:
            s.w500 += cnt;
            break;
        case 100:
            s.w100 += cnt;
            break;
        case 50:
            s.w50 += cnt;
            break;
        case 10:
            s.w10 += cnt;
        default:
            break;
    }
    return;
}
int total(Savings &s){
    int tot = 0;
    tot = s.w10*10 + s.w50*50 + s.w100*100 + s.w500*500;
    return tot;
}
