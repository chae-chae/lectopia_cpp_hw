#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

class Save
{
private:
    char name[20]; // 이름
    int capital; // 원금
    int profit; // 이자소득
    int tax; // 세금
    int tot; // 총금액
    static double ratio; // 이율 – 기본 이율은 원금의 20%로 설정하시오
public:
    static double tax_ratio; // 세율 – 기본 세율은 10%로 설정하시오
    Save(const char *np="아무개", int n=0); // 오버로디드 생성자
    void calculate(); // 총금액
    static void set_ratio(double r); // 정적 멤버함수 : ratio를 수정하기 위한 멤버함수
    const char *getName()const;
    int getCap() const;
    int getPro() const;
    int getTax() const;
    int getTot() const;
    double getRatio() const;
    void setName(const char *);
    void setCap(const int);
};

double Save::tax_ratio = 0.1;

Save::Save(const char *np, int n){
    strcpy(this->name, np);
    this->capital = n;
}

void Save::calculate(){ // 총금액
    this->profit = (int)(this->capital * this->ratio);
    this->tax = (int)(this->profit * this->tax_ratio);
    this->tot = this->capital + this->profit - this->tax;
}

void Save::set_ratio(double r){
    ratio = r;
}

const char *Save::getName()const{
    return this->name;
}

int Save::getCap() const{
    return this->capital;
}
int Save::getPro() const{
    return this->profit;
}
int Save::getTax() const{
    return this->tax;
}
int Save::getTot() const{
    return this->tot;
}
double Save::getRatio() const{
    return this->ratio;
}
void Save::setName(const char *np){
    strcpy(this->name, np);
}
void Save::setCap(const int cap){
    if (cap >= 0) {
        this->capital = cap;
    }
}

double Save::ratio = 0.2;

int main()
{
    Save a("철이", 1000000), b("메텔", 2000000);
    a.calculate();
    cout << "이름 : " << a.getName() << endl;
    cout << "원금 : " << a.getCap() << endl;
    cout << "이자소득 : " << a.getPro() << endl;
    cout << "세금 : " << a.getTax() << endl;
    cout << "총금액 : " << a.getTot() << endl;
    cout << "이율 : " << a.getRatio() << endl;
    cout << "세율 : " << a.tax_ratio << endl;
    cout << endl;
    Save::tax_ratio=0.15; // 세율 변경
    Save::set_ratio(0.25); // 이율 변경
    b.calculate();
    cout << "이름 : " << b.getName() << endl;
    cout << "원금 : " << b.getCap() << endl;
    cout << "이자소득 : " << b.getPro() << endl;
    cout << "세금 : " << b.getTax() << endl;
    cout << "총금액 : " << b.getTot() << endl;
    cout << "이율 : " << b.getRatio() << endl;
    cout << "세율 : " << b.tax_ratio << endl;
    return 0;
}
