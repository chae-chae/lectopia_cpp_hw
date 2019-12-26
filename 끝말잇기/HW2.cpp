#include <iostream>
using namespace std;
#include <stdio.h> //FILE I/O
#include <assert.h>
#include <string.h>
#include "word.h"
#include "GDLL.h"

struct pointword{
    char word[50];
    bool state; //지워진 단어는 true / 안 지워진 단어는 false
};
void fileRead(pointword *sp);
void pointwordPrint(pointword *sp);
void pointwordSort(pointword *sp);
void showUserWord(List * lp, void (*dataPrint)(void *));
int mInput(List *lp, int* game, pointword* pwp, int *scorep);
void pointUpCheck(pointword *pwp, Word *iDp, int *scorep);



int main(){
    List list;        /* 리스트관리 구조체 변수 */
    
    createList(&list); //list관리구조체 만듦
    
    pointword pw[5]; //포인트워드형 배열 다섯개만듦
    
    //시작
    printf("# 포인트 단어를 파일로부터 입력받는 중입니다...\n\n");
    fileRead(pw);
    pointwordSort(pw);
    Word start = {"pointer", 7};
    addLast(&list, &start, sizeof(Word), wordMemCpy);
    
    int game = 1;
    int score = 0;
    
    while (game <=10) {
        pointwordPrint(pw);
        showUserWord(&list, wordPrint);
        mInput(&list, &game, pw, &score);
        printf("\n");
        if (score == 100){
            break;
        }
    }
    printf("** 당신의 점수는 %d점 입니다\n", score);
    destroyList(&list, NULL);
    
    return 0;
}

//캐릭터배열만들어서 스트링카피로 포문돌려서 하나씩 복사해두고 그거로 초기화해주기
void fileRead(pointword *sp){ //완
    char wAry[5][50] = {"tiger", "hen", "cow", "rabbit", "lion"};
    for (int i = 0; i<5; i++){
        strcpy((sp+i)->word, wAry[i]);
        (sp+i)->state = false; //안지워졌으면 false
    }
}
void pointwordPrint(pointword *sp){ //완
    printf("* 포인트단어 : ");
    for (int i = 0; i<5 ; i++) {
        if ((sp+i)->state == false) {
            printf("%s / ", (sp+i)->word);
        }
    }
    printf("\n");
}
void pointwordSort(pointword *sp){ //완
    char temp[50];
    for (int i = 0; i<5; i++) {
        for (int j = i+1; j<5; j++){
            if ((strcmp((sp+i)->word, (sp+j)->word)) > 0){
                strcpy(temp, (sp+i)->word);
                strcpy((sp+i)->word, (sp+j)->word);
                strcpy((sp+j)->word, temp);
            }
        }
    }
}
void showUserWord(List * lp, void (*dataPrint)(void *)){ //사용자가 이때까지 뭘 입력했나 보여줌
    printf("* 사용자 입력 단어 : ");
    displayList(lp, wordPrint);
}
int mInput(List *lp, int *game, pointword* pwp, int *scorep)
{
    Word inData = {"", 0}; //wArr, len
    
    printf("# 끝말잇기 단어 입력 (%d회차) : ", *game);
    scanf("%s", inData.wArr);
    inData.len = (int)strlen(inData.wArr);
    
    if (wordChain(&inData, (char *)lp->tail->prev+sizeof(Node))){
        addLast(lp, &inData, sizeof(Word), wordMemCpy);
        pointUpCheck(pwp, &inData, scorep);
        *game += 1;
        return 1;
    }
    printf("* 잘못 입력하셨습니다. 다시 입력해주세요.\n");
    return 0;
}

void pointUpCheck(pointword *pwp, Word *iDp, int *scorep){
    
    for (int i = 0; i<5; i++) {
        if (strcmp((pwp+i)->word, iDp->wArr) == 0) {
            (pwp+i)->state = true;
            *scorep += 20;
        }
    }
}
void myflush()
{
    while (getchar() != '\n') {
        ;
    }
}
