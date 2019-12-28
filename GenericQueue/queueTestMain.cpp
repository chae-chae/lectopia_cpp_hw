#include "circularQueue.h"
#include <stdio.h>
#include "score.h"
int menu(const char **, int);
void myFlush();
void input(Queue *);
void myDelete(Queue *);
/*--------------------------------------------------------------------------------
 Function name    :  main()
 ---------------------------------------------------------------------------------*/
int main()
{
    Queue que;        /* 큐 관리구조체 선언*/
    const char *menuList[] = { "입력하기", "삭제하기", "출력하기", "종료" }; /* 메뉴리스트*/
    int menuCnt;    /* 메뉴개수 저장 변수*/
    int menuNum;    /* 메뉴번호 저장 변수*/
    
    createQueue(&que, 5, sizeof(Score)); /* 크기가 5인 큐 생성 및 초기화*/
    
    menuCnt = sizeof(menuList) / sizeof(menuList[0]); /* 메뉴 개수 계산 하기*/
    while (1)
    {
        menuNum = menu(menuList, menuCnt);
        if (menuNum == menuCnt) /* 종료메뉴 선택 시 반복문 탈출 하기*/
        {
            break;
        }
        switch (menuNum)
        {
            case 1: input(&que); break;
            case 2: myDelete(&que); break;
            case 3: printQueue(&que, sizeof(Score), scorePrint); /* queue내의 모든 데이터 출력 하기*/
        }
    }
    destroyQueue(&que, sizeof(Score), scoreClear);
    return 0;
}
/*--------------------------------------------------------------------------------------------------------
 Function name    : input() - 큐에 데이터를 반복적으로 입력 함
 Parameters        : qPtr - 큐의 주소
 Returns            : 없음
 ----------------------------------------------------------------------------------------------------------*/
void input(Queue *qPtr)
{
    Score enqueData = {"", NULL};
//    char tname[20];
    
    while (1) {
        printf("enqueue할 성명을 입력하시오(end 입력 시 종료) : ");
        scanf("%s", enqueData.name);
        if (strcmp(enqueData.name, "end") == 0 ){
            break;
        }
        enqueData.score = (int *)calloc(3, sizeof(int)); //인큐할거 임시로 넣는거임
        printf("과목 1 성적을 입력하시오 : ");
        while (scanf("%d", &enqueData.score[0]) != 1) { /* 문자가 입력되면 while문을 반복수행*/
            myFlush();
            printf("과목 1 성적을 입력하시오 : ");
        }
        printf("과목 2 성적을 입력하시오 : ");
        while (scanf("%d", &enqueData.score[1]) != 1) { /* 문자가 입력되면 while문을 반복수행*/
            myFlush();
            printf("과목 2 성적을 입력하시오 : ");
        }
        printf("과목 3 성적을 입력하시오 : ");
        while (scanf("%d", &enqueData.score[2]) != 1) { /* 문자가 입력되면 while문을 반복수행*/
            myFlush();
            printf("과목 3 성적을 입력하시오 : ");
        }
//        printf("%d %d %d\n", enqueData.score[0], enqueData.score[1], enqueData.score[2]);
//        if (scanf("%d", &enqueData) != 1) { /* 문자나 EOF가 입력되면 while문을 빠져 나감*/
//            myFlush();
//            break;
//        }
//        enqueue(Queue * qp, void* enqueData,  size_t dSize, void(*memCpy)(void *, void *)
        if (enqueue(qPtr, &enqueData, sizeof(Score), scoreMemCpy) == FALSE)
            printf("enqueue 실패!!\n");
        free(enqueData.score); //메모리 누수(leak)방지
    }
}
/*------------------------------------------------------------------------------------------------------------
 Function name    : myDelete() - 큐에 데이터를 반복적으로 꺼냄
 Parameters        : qPtr - 큐의 주소
 Returns            : 없음
 ------------------------------------------------------------------------------------------------------------*/
void myDelete(Queue *qPtr)
{
    int i;
    int cnt; /* dequeue할 횟수를 입력 받아 저장할 변수*/
    Score dequeData = {"", NULL}; /* dequeue한 데이터를 저장할 변수*/
    int res; /* dequeue()함수의 리턴값을 저장할 변수*/
    printf("Queue에서 데이터를 dequeue할 회수를 입력하시오: ");
    scanf("%d", &cnt);
    for (i = 0; i<cnt; i++) {
        res = dequeue(qPtr, &dequeData, sizeof(Score), scoreMemCpy, scoreClear);
        if (res == 1) /* 성공적으로 get 작업을 수행 했으면*/
        {
            scorePrint(&dequeData);
//            printf("dequeue 데이터: %5d\n", dequeData);
        }
        else
            printf("dequeue 실패!\n");
    }
    free(dequeData.score);
}
/*------------------------------------------------------------------------------------------------------------
 Function name    : menu() - 메뉴를 출력하고 메뉴번호를 입력 받아 리턴 함
 Parameters        : menuLIst - 메뉴 출력할 문자열
 menuCnt - 메뉴 개수
 Returns            : 선택된 메뉴번호
 ------------------------------------------------------------------------------------------------------------*/
int menu(const char **menuList, int menuCnt)
{
    int i;
    int menuNum = 0; /* 입력된 메뉴번호 저장 변수*/
    int res; /* scanf()함수의 리턴값 저장 변수*/
    for (i = 0; i<menuCnt; i++)
    {
        printf("%d. %s\n", i + 1, menuList[i]);
    }
    while (menuNum<1 || menuNum>menuCnt) /* 메뉴번호 범위의 번호가 입력시 까지 반복*/
    {
        printf("# 메뉴번호를 입력하세요 : ");
        res = scanf("%d", &menuNum);
        if (res != 1) /* 정수가 입력되지 않았으면*/
        {
            myFlush(); /* 입력버퍼 비우기*/
            continue;
        }
    }
    return menuNum;
}

/*------------------------------------------------------------------------------------------------------------
 Function name    : myFlush() - 입력버퍼 지우기
 Parameters        : 없음
 Returns            : 없음
 ------------------------------------------------------------------------------------------------------------*/
void myFlush()
{
    while (getchar() != '\n')
    {
        ;
    }
}
//
//void mOutput(Queue *qp)
//{
//    printQueue(qp, sizeof(Score), scorePrint);
//}
