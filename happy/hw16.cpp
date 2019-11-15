#include <iostream>
using namespace std;
#include <string>
#include "Happy.h"

int main() {
    Happy a("철이"), b("메텔"), w;
    char item[100];
    int price;
    cout << "철이가 돈을 씁니다..." << endl;
    while(1){1
        cout << "구입 내역 : ";
        cin >> item;
        if(strcmp(item, "끝")==0) break;
        cout << "금액 입력 : ";
        cin >> price;
        a.use(item, price);
    }
    cout << endl;
    cout << "메텔이 돈을 씁니다..." << endl;
    while(1){
        cout << "구입 내역 : ";
        cin >> item;
        if(strcmp(item, "끝")==0) break;
        cout << "금액 입력 : ";
        cin >> price;
        b.use(item, price);
    }
    cout << endl;
    cout << "최종 승자는?" << endl;
    w=a.winner(b);
    cout << w.getName() << "이고 총 " << w.getIndex() << "건을 사용하고 남은 금액은 " << w.getMoney() << "원 입니다." << endl;
    
    // 승자의 사용내역을 출력하는 코드 넣어서 완성하시오.
    cout << "사용 내역 : ";
    for (int i = 0; i<w.getIndex(); i++) {
        cout << w.getList()[i] << ' ';
    }
    cout << endl;
    
    Happy temp(a);
    
    return 0;
    
}
