#include <iostream>
using namespace std;

void MyFunc(void){
    cout<<"MyFunc(void) called"<<endl;
}

void MyFunc(char c) {
    cout<<"MyFunc(char c) called"<<endl;
}

void MyFunc(int a, int b) {
    cout<<"MFunc(int a, int b) called"<<endl;
}

int main(void) {
    MyFunc();
    MyFunc('A');
    MyFunc(2, 3);

    return 0;
}