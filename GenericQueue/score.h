#pragma once
#pragma warning(disable: 4996)

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct _score
{
    char name[20]; // 성명 저장 배열
    int* score; // 3과목 성적 입력
}Score;

// p2가 가리키는 구조체의 모든 멤버를 p1이 가리키는 구조체로 복사
void scoreMemCpy(void *p1, void *p2);

// 구조체 멤버 중 포인터 멤버에 동적메모리 할당이 되어있는 경우 그 메모리를 해제하고 초기상태로 모두 초기화 시킴
void scoreClear(void *p);

// 구조체 멤버의 값을 한줄에 출력해 줌
void scorePrint(void *p);

// 성명을 비교하여 p1이 가리키는 성명이 크면 1, 같으면 0, 작으면 -1 리턴
int scoreNameCompare(void *p1, void *p2);
