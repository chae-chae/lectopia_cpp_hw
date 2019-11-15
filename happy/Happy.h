#pragma once
#include <iostream>
using namespace std;
#include <string>
#pragma warning (disable:4996)

class Happy
{
private:
    string name;
    int money;
    char *list[100]; // 사용 내역을 저장하는 char * 배열
    int index; // 사용 내역 개수
public:
    Happy(string np="", int money=10000); // 디폴트 생성자 함수
    Happy(Happy &r); // 복사 생성자 함수
    ~Happy(); // 소멸자 함수
    Happy & operator=(Happy &r); // 대입연산자 함수
    void use(char *lp, int n); // 사용 함수(사용내역과 금액을 받는다)
    Happy &winner(Happy &r); // 잔액 비교하여 많은 금액이 남은 사람의 객체리턴
    void setName(string &name);
    string & getName();
    void setMoney(int money);
    int getMoney();
    char ** getList();
    int getIndex();
};

Happy::Happy(string np, int money){
    this->name = np;
    this->money = money;
//    for (int i = 0; i<100; i++) {
//        this->list[i] = 0;
//    }
    this->index = 0;
}
Happy::Happy(Happy &r){
    this->name = r.name;
    this->money = r.money;
    for (int i = 0; i<r.index; i++) {
        this->list[i] = new char[strlen(r.list[i])+1];
        strcpy(this->list[i], r.list[i]);
    }
    this->index = r.index;
}
Happy::~Happy(){
    for (int i = 0; i<this->index; i++) {
        delete [] this->list[i];
    }
}
Happy & Happy::operator=(Happy &r){
    if (this == &r) return *this;
    
    this->name = r.name;
    this->money = r.money;
    
    for (int i = 0; i<this->index; i++) {
        delete [] this->list[i];
    }
    this->index = r.index;
    
    for (int i = 0; i<this->index; i++) {
        this->list[i] = new char[strlen(r.list[i])+1];
        strcpy(this->list[i], r.list[i]);
    }
    return *this;
}
void Happy::use(char *lp, int n){
    this->list[this->index] = new char[strlen(lp)+1];
    strcpy(this->list[this->index], lp);
    this->money -= n;
    this->index++;
}
Happy & Happy::winner(Happy &r){
    if (this->money > r.money) {
        return *this;
    } else {
        return r;
    }
}
void Happy::setName(string &name){
    this->name = name;
}
string & Happy::getName(){
    return this->name;
}
void Happy::setMoney(int money){
    this->money = money;
}
int Happy::getMoney(){
    return this->money;
}
char ** Happy::getList(){
    return this->list;
}
int Happy::getIndex(){
    return this->index;
}
