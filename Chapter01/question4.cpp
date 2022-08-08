#include <iostream>
using namespace std;

int main(void) {

    int price;
    while(true){
        int salaray = 50;
        cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        cin>>price;
        if(price == -1){
            break;
        }
        salaray += (price * 0.12);
        cout<<"이번 달 급여: "<<salaray<<endl;
    }
    cout<<"프로그램을 종료합니다."<<endl;

    return 0;
}