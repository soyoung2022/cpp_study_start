#include <iostream>
using namespace std;

int main(void) {
    int result = 0, n;
    for(int i = 1; i <= 5; i++){
        cout<<i<<"번째 정수 입력: ";
        cin>>n;
        result += n;
    }
    cout<<"합계 = "<<result<<endl;

    return 0;
}