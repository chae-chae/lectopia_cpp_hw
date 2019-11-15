#include <iostream>
#include <math.h>
using namespace std;

class Time{
private:
    int hour;
    int min;
public:
    Time();
    Time(int, int);
    Time(double);
    Time(const Time &tr);
    Time plus(const Time &tr);
    void setHour(int);
    int getHour()const;
    void setMin(int);
    int getMin()const;
};

Time::Time(){
    this->hour = 0;
    this->min = 0;
//    cout << "default";

}
Time::Time(int h, int m) : hour(h), min(m){
    int iH = h, iM = m;
    if ( m >= 60 ){
        iH += m/60;
        iM = m%60;
    }
    this->hour = iH;
    this->min = iM;
//    cout << "overloaded";
}
Time::Time(double dt){
    int iH, iM;
    double Dm;
    
    Dm = dt - (int)dt;
    iH = (int)(dt - Dm);
    iM = abs((int)(Dm*60));
    
    this->hour = iH;
    this->min = iM;
}
Time::Time(const Time &tr){
//    cout << "copy";
    this->hour = tr.hour;
    this->min = tr.min;
}
Time Time::plus(const Time &tr){
    Time res;
    res.hour = this->hour + tr.hour;
    if ( (this->min + tr.min) >= 60 ){
        res.hour += (this->min + tr.min)/60;
        res.min = (this->min + tr.min)%60;
    } else {
        res.min = this->min + tr.min;
    }
    return res;
}
void Time::setHour(int h){
    this->hour = h;
}
int Time::getHour()const{
    return this->hour;
}
void Time::setMin(int m){
    int iH = 0, iM = m;
    if ( m >= 60 ){
        iH = m/60;
        iM = m%60;
    }
    this->hour += iH;
    this->min = iM;
}
int Time::getMin()const{
    return this->min;
}
int main(){
    Time a(3, 20), b;
    cout << a.getHour() << "시간 " << a.getMin() << "분" << endl;
    b.setHour(4);
    b.setMin(42);
    cout << b.getHour() << "시간 " << b.getMin() << "분" << endl;
    Time res = a.plus(b);
    cout << "두 시간을 더하면 : " << res.getHour() << "시간 " << res.getMin() << "분" << endl;
    return 0;
}
