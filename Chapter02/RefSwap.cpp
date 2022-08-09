#include <iostream>
using namespace std;

// 매개변수로 참조자가 온다. --> 함수 매개변수는 호출 시 초기화된다. 
void SwapByRef(int &ref1, int &ref2) {
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(void) {
    int val1 = 10;
    int val2 = 20;

    SwapByRef(val1, val2);
    cout<<"VAL1: "<<val1<<endl;
    cout<<"VAL2: "<<val2<<endl;

    return 0;
}