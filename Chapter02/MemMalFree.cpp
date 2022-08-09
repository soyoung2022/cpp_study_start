#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * MakeStrAdr(int len){
    char * str = (char*) malloc(sizeof(char)*len);
    return str;
}

int main(void) {
    int len;
    cout<<"길이를 입력해주세요: ";
    cin>>len;
    char* str = MakeStrAdr(len);
    strcpy(str, "I am so happy!");
    cout<<str<<endl;
    free(str);

    return 0;
}