#include <iostream>
using namespace std;

int main(void) {
    char name[100], phone_number[100];
    cout<<"이름이 무엇인가요? ";
    cin>>name;

    cout<<"전화번호를 입력해주세요 : ";
    cin>>phone_number;

    cout<<"\n이름 : "<<name<<"\n전화번호 : "<<phone_number<<endl;

    return 0;
}