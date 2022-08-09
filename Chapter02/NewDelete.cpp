#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrAdr(int len){
    char * str = new char[len]; // (char*) malloc(sizeof(char)*len); 대신 
    return str;
}

int main(void) {
    char* str = MakeStrAdr(20);
    strcpy(str, "I am so happy!");
    cout<<str<<endl;
    delete []str; // free(str) 

    return 0;
}