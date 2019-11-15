#include <iostream>
using namespace std;
#pragma once

class MyArray
{
private:
    int *ary;
    int size;
public:
    MyArray() { ary=NULL; size=0; } // 디폴트 생성자
    MyArray(int s); // 오버로디드 생성자
    MyArray(const MyArray &br); // 복사 생성자
    ~MyArray() { delete [] ary; } // 소멸자
    MyArray &operator=(const MyArray &br); // 대입연산자
    bool put(int index, int val); // val의 값을 index방에 저장. 성공하면 true, 실패하면 false 리턴
    bool get(int index, int &getdata); // 배열요소 중 index방의 값을 getdata에 저장
    // 성공하면 true, 실패하면 false 리턴
    int getSize(); // 배열요소의 개수 확인
    int *getAry(void); // 배열요소의 내용 확인
};


MyArray::MyArray(int s){
    this->size = s;
    this->ary = new int[this->size];
}
MyArray::MyArray(const MyArray &br){
    this->size = br.size;
    this->ary = new int[this->size];
    for (int i = 0; i<size; i++) {
        this->ary[i] = br.ary[i];
    }
}
MyArray & MyArray::operator=(const MyArray &br){
    if (this == &br) return *this;
    delete [] this->ary;
    this->size = br.size;
    this->ary = new int [this->size];
    return *this;
}
bool MyArray::put(int index, int val){
    if (this->size > index) {
        this->ary[index] = val;
        return true;
    } else {
        return false;
    }
}
bool  MyArray::get(int index, int &getdata){
    if (this->size > index) {
        getdata = this->ary[index];
        return true;
    } else {
        return false;
    }
}
int MyArray::getSize(){
    return this->size;
}
int * MyArray::getAry(void){
    return this->ary;
}
