#pragma once
#pragma warning(disable : 4996)

// p2가 가리키는double형 변수의 내용을 p1이 가리키는 double형 변수에 복사
void doubleMemCpy(void *p1, void *p2);

// double 값을  출력해 줌
void doublePrint(void *p);

// 값을 비교하여 p1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
int doubleCompare(void *p1, void *p2);
