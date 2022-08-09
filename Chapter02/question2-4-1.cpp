#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
    char str[] = "Happy Birthday!";
    cout<<strlen(str)<<endl; // string length
    char str2[] = "Mommy";
    strcat(str, str2); // string concatenate
    cout<<str<<endl;
    char * result = new char[100];
    strcpy(result, str); // string copy
    cout<<result<<endl;
    cout<<strcmp(result, str)<<endl; // 같으면 0을 반환 
    delete []result;

    return 0;
}