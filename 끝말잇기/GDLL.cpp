#include "GDLL.h"
//여기에 특정자료형의 헤더를 인클루드하면 안된다! person.h 절대있으면안댐
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

/*----------------------------------------------------------------------------------
 Function name    : createList - 연결 리스트 생성 및 초기화
 Parameters        : lp - 리스트 관리 구조체의 주소
 Returns            : 성공 - TRUE / 실패 - FALSE
 ----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
    if (lp == NULL) {  /* lp포인터 NULL check */
        return FALSE;
    }
    lp->head = (Node *)calloc(1, sizeof(Node));    /* head node 생성 헤드노드 하나니까 1 */
    if (lp->head == NULL) {
        return FALSE;
    }
    lp->tail = (Node *)calloc(1, sizeof(Node));    /* tail node 생성 */
    if (lp->tail == NULL) {
        free(lp->head);
        return FALSE;
    }
    
    lp->head->next = lp->tail; /* head node와 tail node 연결 */
    lp->tail->next = lp->tail; /* tail node의 next는 자기 자신을 가리키도록 설정 */
    lp->head->prev = lp->head; // head node의 prev는 자기 자신을 가리키도록 설정
    lp->tail->prev = lp->head; // tail node와 head node를 연결
    lp->size = 0;    /* 연결 리스트 크기 0으로 초기화 */
    
    return TRUE;
}

BOOL addLast(List *lp, void *data, size_t dSize, void(*memCpy)(void*, void*))
{
    Node *newp;    /* 새 노드 주소저장용 포인터 */
    
    if (lp == NULL) { /* lp포인터 NULL check */
        return FALSE;
    }
    
    newp = (Node *)calloc(1, sizeof(Node)+dSize);    /* 새 노드 생성 데이터크기만큼 더 간 주소에 할당해주기 */
    if (newp != NULL) {    /*  새 노드 생성 성공 시 처리 */
        memCpy(newp+1, data);
        newp->prev = lp->tail->prev; // 1번 선 연결
        newp->next = lp->tail; // 2번 선 연결
        newp->prev->next = newp; // 3번 선
        lp->tail->prev = newp; // 4번 선 연결
        ++lp->size;    /* 리스트 size 증가 */
        return TRUE;
    }
    else {    /* 새 노드 생성 실패 시 처리 */
        return FALSE;
    }
}

/*----------------------------------------------------------------------------------
 Function name    : displayList - 리스트 내의 모든 데이터 출력
 Parameters        : lp - 리스트 관리 구조체의 주소
 Returns            : 없음
 ----------------------------------------------------------------------------------*/
void displayList(List *lp, void (*dataPrint)(void *))
{
    Node *curp;
    
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    
    curp = lp->head->next;  /* data 있는 첫노드를 curp로 가리키게 함 */
    
    /* 리스트의 마지막 노드까지 curp를 옮기면서 data영역 출력하기 */
    while (curp != lp->tail) {
        /*printf("%8d\n", curp->data); 요런 표현이 있으면 안된당 데이터종속적인거*/
        dataPrint(curp+1); //Node의 데이터영역의 주소를 출력보조함수로 보내줌 주소계산
        curp = curp->next;
    }
    
    printf("\n");
    
    return;
}


void destroyList(List *lp, void(*dataFree)(void *))
{
    Node *curp;
    Node *nextp;
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    curp = lp->head->next;//알맹이를 가리킴
    while (curp != lp->tail) { //알맹이인동안
        nextp = curp->next;
        if (dataFree != NULL){//부가메모리가 있다면 먼저
            dataFree(curp+1); //부가메모리를 해제하기
        }
        free(curp); // 그 후 노드를 해제
        curp = nextp;
    }
    free(lp->head);
    free(lp->tail);
    
    lp->head = lp->tail = NULL;
    lp->size = 0;
    return;
}


