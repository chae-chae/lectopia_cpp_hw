#include <iostream>
using namespace std;
#include "MyAry.h"


class SmartArray : public MyArray
{
private:
    int max; // 최고값 저장
public:
    SmartArray() {
        max = 0;
    } // 디폴트 생성자
    SmartArray(int s) : MyArray(s), max(0) // 오버로디드 생성자
    {}
    bool put(int index, int val); // put함수의 재정의
    int getMax();// max값 리턴
    bool operator>(const SmartArray &br);
};

bool SmartArray::put(int index, int val){
    if (this->max < *(MyArray::getAry()+index)) {
        this->max = val;
    }
    return MyArray::put(index, val);
}
int SmartArray::getMax(){
    return this->max;
}
bool SmartArray::operator>(const SmartArray &br){
    if (this->max >= br.max) {
        return true;
    } else {
        return false;
    }
}
    
int main(){
    
    SmartArray cheoli(3);
    SmartArray metel(5);
    int temp, res, num;
    int tot = 0;
    
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    
    cout << "철이의 세 과목 점수 입력 : ";
    for (int i = 0; i<3; i++) {
        cin >> temp;
        if (cheoli.put(i, temp) == false) {
            cout << "배열 쓰기 실패" << endl;
        }
    }
    for (int i = 0; i<3; i++) {
        res = cheoli.get(i, num);
        if (res) {
            tot += num;
        } else {
            cout << "배열 읽기 실패" << endl;
        }
    }
    cout << "철이의 총점 : " << tot << endl;
    cout << "철이의 평균 : " << tot/3.0 << endl;
    
    temp = 0;
    res = 0;
    num = 0;
    tot = 0;
    
    cout << "메텔의 다섯 과목 점수 입력 : ";
    for (int i = 0; i<5; i++) {
        cin >> temp;
        if (metel.put(i, temp) == false) {
            cout << "배열 쓰기 실패" << endl;
        }
    }
    for (int i = 0; i<5; i++) {
        res = metel.get(i, num);
        if (res) {
            tot += num;
        } else {
            cout << "배열 읽기 실패" << endl;
        }
    }
    cout << "메텔의 총점 : " << tot << endl;
    cout << "메텔의 평균 : " << tot/5.0 << endl;
    
    cout << cheoli.getMax()<< endl;
    cout << metel.getMax() << endl;

    
    if (cheoli.getMax() > metel.getMax()) {
        cout << "철이의 최고점은 메텔보다 크다..." << endl;
    } else {
        cout << "철이의 최고점은 메텔보다 크지 않다..." << endl;
    }
    
    
    
    return 0;
}
