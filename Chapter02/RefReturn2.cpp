#include <iostream>
using namespace std;

int& RefRetFunc1(int &ref) {
    ref++;
    return ref;
}

int main(void) {
    int num1=1;
    int num2=RefRetFunc1(num1); // num2는 그냥 일반 변수로, num1의 참조자가 아니다!

    num1++;
    num2+=100;
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;
    return 0;
}