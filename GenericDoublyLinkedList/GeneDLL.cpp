#include "GeneDLL.h"
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
    lp->head = (Node *)calloc(1, sizeof(Node));    /* head node 생성 헤드노드 하나니까 1, */
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

/*----------------------------------------------------------------------------------
 Function name    : addFirst - head node 뒤에 node 추가(역순 저장)
 Parameters        : lp - 리스트 관리 구조체의 주소
 data - 추가할 데이터
 Returns            : 성공 - TRUE / 실패 - FALSE
 ----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, void *data, size_t dSize, void(*memCpy)(void*, void*))
{
    Node *newp;
    
    if (lp == NULL) { /* lp포인터 NULL check */
        return FALSE;
    }
    
    newp = (Node *)calloc(1, sizeof(Node)+dSize); /* 새 노드 생성 */
    if (newp != NULL) {                /* 새 노드 생성 성공 시 처리 */
        memCpy(newp+1, data);
        newp->prev = lp->head;        // 1번 선 연결
        newp->next = lp->head->next; /* 새 노드의 next 설정 */ // 2번 선 연결
        lp->head->next = newp;    /* head ndoe 뒤에 새 노드 연결 */ // 3 번 선 연결
        newp->next->prev = newp;    // 4번 선 연결
        ++lp->size;                    /* 리스트 size 증가 */
        return TRUE;
    }
    else {                            /* 새 노드 생성 실패 시 처리 */
        return FALSE;
    }
}
/*----------------------------------------------------------------------------------
 Function name    : addLast - tail node 앞에 새 node 추가(정순 저장)
 Parameters        : lp - 리스트 관리 구조체의 주소
 data - 추가할 데이터
 Returns            : 성공 - TRUE / 실패 - FALSE
 ----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, void *data, size_t dSize, void(*memCpy)(void*, void*))
{
    Node *newp;    /* 새 노드 주소저장용 포인터 */
    
    if (lp == NULL) { /* lp포인터 NULL check */
        return FALSE;
    }
    
    newp = (Node *)calloc(1, sizeof(Node)+dSize);    /* 새 노드 생성 데이터크기만큼 더 더해준거*/
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

/*----------------------------------------------------------------------------------
 Function name    : searchNode - data와 일치하는 첫 번째 node 검색
 Parameters        : lp - 리스트 관리 구조체의 주소
 data - 검색할 데이터
 Returns            : 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
 ----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, void *data, int (*compare)(void *, void*))
{
    Node *curp;
    
    if (lp == NULL) { /* lp포인터 NULL check */
        return NULL;
    }
    
    curp = lp->head->next;/* data첫노드를 curp로 가리키게 함 */
    /* 리스트의 마지막 데이터 노드까지 curp를 옮기면서 검색하기 */
    while (curp != lp->tail) {
        if (compare(curp+1/*data영역*/, data) == 0) {
            return curp;    /* 찾은 노드의 주소 리턴 */
        }
        else {
            curp = curp->next;
        }
    }
    
    return NULL;    /* 못찾으면 NULL pointer 리턴 */
}
/*----------------------------------------------------------------------------------
 Function name    : removeNode - data와 일치하는 첫 번째 노드 삭제
 Parameters        : lp - 리스트 관리 구조체의 주소
 data - 삭제할 데이터
 Returns            : 성공 - TRUE / 실패 - FALSE
 ----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, void *data, int (*compare)(void *, void*), void(*dataFree)(void *))
{
    Node *delp;
    if (lp == NULL) { /* lp포인터 NULL check */
        return FALSE;
    }
    delp = searchNode(lp, data, compare);  /* 삭제할 node를 검색 함 */
    if (delp != NULL) { /* 삭제할 노드를 찾았으면 삭제하기 */
        delp->prev->next = delp->next;
        delp->next->prev = delp->prev;
        if (dataFree != NULL){
            dataFree(delp +1); //2중프리필요
        }
        free(delp);
        --lp->size;    /* 리스트 size 감소 */
        return TRUE;
    }
    else {    /* 삭제할 노드의 못찾았으면 삭제 실패 */
        return FALSE;
    }
}
/*----------------------------------------------------------------------------------
 Function name    : sortList - 노드 정렬(오름차순)
 Parameters        : lp - 리스트 관리 구조체의 주소
 Returns            : 없음
 ----------------------------------------------------------------------------------*/
void sortList(List *lp, size_t dSize, int (*compare)(void *, void*), void(*memCpy)(void*, void*), void(*dataFree)(void *))
{
    Node *curp;
    Node *nextp;
    void *temp;
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    
    temp = calloc(1, dSize); //같은 void *라서 캐스팅안해도됨
    curp = lp->head->next;
    while (curp->next != lp->tail) {
        nextp = curp->next;
        while (nextp != lp->tail) {
            if (compare(curp+1, nextp+1) > 0){ //데이터부분을 비교하기위해 +1을 해줌 앞에 있는 데이터가 크면 깊은 복사실시
                memCpy(temp, curp+1);
                memCpy(curp+1, nextp+1);
                memCpy(nextp+1, temp);
            }
            nextp = nextp->next;
        }
        curp = curp->next;
    }
    if (dataFree != NULL){//부가 메모리가 있다면
        dataFree(temp);//부가 메모리도 꼭 해제해주기
    }
    free(temp); // 반드시 해제 만약 이거만 프리하면 딸려있던게 안없어짐 그니까 위에서 데이터프리를 해주기
}
/*----------------------------------------------------------------------------------
 Function name    : destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
 Parameters        : lp - 리스트 관리 구조체의 주소
 Returns            : 없음
 ----------------------------------------------------------------------------------*/
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


