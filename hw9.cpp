#include <iostream>
using namespace std;

struct Goods
{
    char item[50];
    int price;
    int year;
    int mon;
    int day;
    int discount;
};

struct Today // 맥이라서 시스템에서 날짜를 불러오는 함수 사용이 불가능해 정혜경 강사님이 말씀하신 대로 날짜를 8월 5일 (과제날짜)로 초기화하여 코딩했습니다.
{
    int todayY;
    int todayM;
    int todayD;
};

void input(Goods &s); //
void selling_price(Goods &s);
void prn(const Goods &s);
int tot_days(int y, int m, int d);
int leap_check(int year);

int main(){
    Goods s;
    input(s);
    selling_price(s);
    prn(s);
    return 0;
}
void input(Goods &s){
    cout << "품목 입력 : ";
    cin.getline(s.item, 100);
    cout << "정가 입력 : ";
    cin >> s.price;
    cout << "유통기한 입력 : ";
    cin >> s.year >> s.mon >> s.day;
}
void selling_price(Goods &s){
    Today t = {2019, 8, 5}; //맥이라서 시스템시간을 불러오는 함수가 사용불가능해 과제날짜로 초기화하라고 하셨습니다!
    int tillToday = 0;
    int expD = 0;
    int saleD = 0;
    expD = tot_days(s.year, s.mon, s.day);
    tillToday = tot_days(t.todayY, t.todayM, t.todayD);
    saleD = expD - tillToday;

    if (saleD < 0) { // 유통기한이 지나면 -1로 하고 프린트에서 구분해서 찍어주게
        s.discount = -1;
    } else if (0 <= saleD && saleD <= 3) {
        s.discount = 50;
        s.price = (int)(s.price * 0.5);
    } else if (4 <= saleD && saleD <= 10){
        s.discount = 20;
        s.price = (int)(s.price * 0.8);
    } else {
        s.discount = 0;
    }
    return;
}
void prn(const Goods &s){
    if (s.discount == -1) {
        cout << "유통기한이 지났습니다!" << endl;
        return;
    }
    cout << "품명 : " << s.item << endl;
    cout << "판매가 : " << s.price << endl;
    cout << "유통기한 : " << s.year << "년 " << s.mon << "월 " << s.day << "일" << endl;
    cout << "할인율 : " << s.discount << '%' << endl;
    return;
}
int leap_check(int year){
    if (year%4 != 0){
        return false; //false이면 평년
    } else if (year%100 != 0){
        return true;
    } else if (year%400 == 0){
        return true;
    } else {
        return false;
    }
}

int tot_days(int y, int m, int d){
    int tot = 0;
    int i;
    int endofmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for (i = 1900; i<y; i++) { //입력받은 년도 -1 년까지니까
        if (leap_check(i) == false) {//평년이면
            tot += 365;
        } else {//윤년이면
            tot += 366;
        }
    }
    for (i = 1; i<m; i++) { //입력받은 월 -1월까지 여기서 30일잇는지 31일잇는지 엔옵몬으로?
        tot += endofmonth[i-1]; //엔옵몬은 0번방부터 1월 있음
    }
    for (i = 1; i<=d; i++) { // 일 더하는것. 1일부터 입력받은 일까지
        tot += 1;
    }
    if ((leap_check(y) == 1) && (m >= 3)) { //입력한게 윤년이고 3월이상이면
        tot += 1;
    }
    return tot;
}
