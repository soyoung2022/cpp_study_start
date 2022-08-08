#include <iostream>
using namespace std;

int main(void) {
    int number;
    cout<<"숫자를 입력해주세요 : ";
    cin>>number;

    for(int i = 1; i <= 9; i++){
        cout<<number<<"*"<<i<<" = "<<number*i<<endl;
    }

    return 0;
}