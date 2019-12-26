#include "word.h"
#include <stdio.h>
#include <string.h>

#pragma warning(disable: 4996)

// p2가 가리키는 구조체의 모든 멤버를 p1이 가리키는 구조체로 복사
void wordMemCpy(void *p1, void *p2){
    strcpy(((Word *)p1)->wArr, ((Word *)p2)->wArr);
    ((Word *)p1)->len = ((Word *)p2)->len;
    return;
}

// 사용자 입력 단어를 출력해 줌
void wordPrint(void *p){
    printf("%s / ", ((Word *)p)->wArr);
    return;
}

// 마지막 알파벳이 무엇인지 확인하고 이어지는지 봐주는 함수
bool wordChain(void *p1, void *p2){
    if (((Word *)p1)->wArr[0] == ((Word *)p2)->wArr[((Word *)p2)->len-1]){
        return true;
    } else {
        return false;
    }
}
