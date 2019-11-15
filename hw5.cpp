#include <iostream>
#include <iomanip>
using namespace std;
void myflush();

int main(){
    char name[20];
    int k, e, m;
    int tot = 0;
    double av;
    
    cout << "이름 : ";
    cin.getline(name, sizeof(name), '\n');
    //cout << name;
    cout << "세 과목의 점수 : ";
    cin >> k >> e >> m;
    tot = k + e + m;
    av = (k+e+m)/3.0;
    //cout << k << ' ' << e << ' ' << m <<endl;
    cout << endl;
    cout << setw(20) << ' ' << "=====< 성적표 >=====" << endl;
    for (int i = 0; i<60; i++) {
        cout << '=';
    }
    cout << endl;
    cout << setw(10) << "이름" << setw(10) << "국어" << setw(10) << "영어" << setw(10) << "수학" << setw(10) << "총점" << setw(10) << "평균" << endl;
    for (int i = 0; i<60; i++) {
        cout << '=';
    }
    cout << endl;
    cout << setw(10) << name << setw(10) << k << setw(10) << e << setw(10) << m << setw(10) << tot << fixed << setprecision(2) << setw(10) << av << endl;

    return 0;
}
void myflush(){
    while (cin.get()!='\n');
}

