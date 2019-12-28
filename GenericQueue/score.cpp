
#include "score.h"
#include <stdio.h>
#include <string.h>

#pragma warning(disable: 4996)

// 구조체 멤버 중 포인터 멤버에 동적메모리 할당이 되어있는 경우 그 메모리를 해제하고 초기상태로 모두 초기화 시킴
void scoreClear(void *p){
    strcpy(((Score *)p)->name, "");
    
    if(((Score *)p)->score != NULL){ //점수동적메모리 할당 되어있다면 해제하는거로
        free(((Score *)p)->score);
    }
    ((Score *)p)->score = NULL;
}

// p2가 가리키는 구조체의 모든 멤버를 p1이 가리키는 구조체로 복사
void scoreMemCpy(void *p1, void *p2){

        scoreClear(p1);

    strcpy(((Score *)p1)->name, ((Score *)p2)->name); //이름 복사
    
    if (((Score *)p2)->score != NULL){ //넣을 성적 값 받았는지
        ((Score *)p1)->score = (int *)calloc(3, sizeof(int));//진짜 넣을 세칸을 할당해주고 각각넣기
        ((Score *)p1)->score[0] = ((Score *)p2)->score[0];
        ((Score *)p1)->score[1] = ((Score *)p2)->score[1];
        ((Score *)p1)->score[2] = ((Score *)p2)->score[2];
    }
    return;
}


// 구조체 멤버의 값을 한줄에 출력해 줌
void scorePrint(void *p){
    printf("성명 : %s / 과목1 성적 : %d / 과목2 성적 : %d / 과목3 성적 : %d\n",
           ((Score *)p)->name, ((Score *)p)->score[0], ((Score *)p)->score[1], ((Score *)p)->score[2]);
    return;
}

// 성명을 비교하여 p1이 가리키는 성명이 크면 1, 같으면 0, 작으면 -1 리턴
int scoreNameCompare(void *p1, void *p2){
    return (strcmp(((Score *)p1)->name, ((Score *)p2)->name));
}
