#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)


char* ustrchr(char *str, int ch);
char* ustrcat(char *s1, char *s2);
char* ustrstr(char *s1, char *s2);
void ustrcpy(char *s1, char *s2);
unsigned int ustrlen(char *str);
int ustrcmp(char *s1, char *s2);



int main(void) {
	char a[30] = "apple pie";
    char b[30] = "le";

	//test'

	printf("%p\n", strstr(a, b));
	printf("u : %p\n", ustrstr(a, b));

	//printf("%p\n", strchr(a, 'e'));
	//printf("u : %p\n", ustrchr(a, 'e'));
	
	//printf("%p\n", a);
	//printf("%p %s\n", strcat(a, b), a);
	//printf("%p\n", a);
	//printf("%p %s\n", ustrcat(a, b), a);

	//strcpy(a, b);
	//ustrcpy(a, b);
	//printf("%s\n", a);

	//printf("%d\n", strlen(a));
	//printf("u :%d\n", ustrlen(a));

	//printf("%d\n", strcmp(a, b));
	//printf("u : %d\n", ustrcmp(a, b));
    
    return 0;
}


char* ustrchr(char *str, int ch){ //완료
    int len = ustrlen(str);
    int i;
    for(i = 0; i < len; i++){
        if(*(str+i) == ch) return str+i;
    }
    return NULL;
}

char* ustrcat(char *s1, char *s2){ //완료 3
    char* temp = s1;
    while(*s1 != '\0') *s1++;
    while(*s2 != '\0') *s1++ = *s2++;
    *s1 = 0;
    return temp;
}
char* ustrstr(char *s1, char *s2){ // 완료
    int len1 = ustrlen(s1);
    int len2 = ustrlen(s2);
    int i,j;
    for(i = 0; i <= len1 - len2; i++){
        for(j = 0; j < len2; j++){
            if(*(s1+i+j) != *(s2+j)) break;
        }
        if(j == len2)
            return s1+i;
    }
    return NULL;
}
void ustrcpy(char *s1, char *s2){ //완료
    while(*s2 != '\0'){
        *s1++ = *s2++;
    }
    *s1 = NULL;
}
unsigned int ustrlen(char *str){ // length 완료
    int i;
    for(i = 0;; i++){
        if(*(str+i) == '\0') break;
    }
    return i;
}
int ustrcmp(char *s1, char *s2){ // 완
    int temp = 0;
    while(true){
        if(*s1++ != *s2++){
            temp = (*(s1-1) - *(s2-1));
            break;
        }else if(*s1 == 0 && *s2 == 0) { break; }
    }
    if(temp > 0) return 1;
    else if(temp < 0) return -1;
    else return temp;
}
