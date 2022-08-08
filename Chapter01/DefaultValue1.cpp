#include <iostream>
using namespace std;

int Adder(int num1=1, int num2=2){
    return (num1+num2);
}

int main(void) {
    cout<<Adder()<<endl;
    cout<<Adder(5)<<endl; // 인자를 하나만 전달하면 첫 번째 매개변수로 전달된다. 두 번째 매개변수 num2에는 2가 전달된 것으로 간주한다(디폴트 값)
    cout<<Adder(3, 5)<<endl;

    return 0;
}