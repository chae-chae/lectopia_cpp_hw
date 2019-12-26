#pragma once
#pragma warning(disable: 4996)

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct _word
{
    char wArr[50]; // 앝은 복사 단어배열
    int len; // 단어의 길이 저장
}Word;

// p2가 가리키는 구조체의 모든 멤버를 p1이 가리키는 구조체로 복사
void wordMemCpy(void *p1, void *p2);

// 구조체 멤버 중 포인터 멤버에 동적메모리 할당이 되어있는 경우 그 메모리를 해제하고 초기상태로 모두 초기화 시킴
//void wordClear(void *p);

// 구조체 멤버의 값을 한줄에 출력해 줌
void wordPrint(void *p);

// 마지막 알파벳이 무엇인지 확인하고 이어지는지 봐주는 함수
bool wordChain(void *p1, void *p2);
