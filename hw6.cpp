#include <iostream>
//#include <iomanip>
//#include <stdio.h>
using namespace std;

size_t my_strlen(const char *sp, char ch = '\0');

int main(){
    
    char str[100];
    char ch;
    
    cout << "문자열 입력 : ";
    cin >> str;
    cout << "문자열의 길이 : " << my_strlen(str) << endl;
    cout << "문자 입력 : ";
    cin >> ch;
    
    cout << ch << " 이전 까지의 길이 : " << my_strlen(str, ch) << endl;
    
}
size_t my_strlen(const char *sp, char ch){
    size_t len = 0;
    for (int i = 0; i<100; i++) {
        if (sp[i] != ch && sp[i] != '\0') {
            len++;
        } else {
            break;
        }
    }
    return len;
}
