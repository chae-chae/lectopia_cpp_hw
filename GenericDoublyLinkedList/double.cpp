#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

// p2가 가리키는double형 변수의 내용을 p1이 가리키는 double형 변수에 복사
void doubleMemCpy(void *p1, void *p2){
    //double temp;
    
    if ((double *)p2 != NULL) { //복사할 내용이 있다면
        (*(double *)p1) = (*(double *)p2); //더블값 복사해주기
    }
    return;
}

// double 값을  출력해 줌
void doublePrint(void *p){
    printf("%lf\n", *(double *)p);
    return;
}

// 값을 비교하여 p1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
int doubleCompare(void *p1, void *p2){
    if ((*(double *)p1) > (*(double *)p2)) {
        return 1;
    } else if ((*(double *)p1) < (*(double *)p2)){
        return -1;
    } else {
        return 0;
    }
}
