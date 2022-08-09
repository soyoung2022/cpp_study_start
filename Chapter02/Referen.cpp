#include <iostream>
using namespace std;

int main(void) {
    int num1=1020;
    int &num2 = num1; // 선언되지 않았던 num2에 온 & --> num2는 reference

    num2 = 3047;
    cout<<"VAL: "<<num1<<endl;
    cout<<"REF: "<<num2<<endl;

    // 이미 선언된 변수들 앞에 온 & -> 주소를 출력 
    cout<<"VAL: "<<&num1<<endl;
    cout<<"REF: "<<&num2<<endl;

    return 0;
}