/*
백준 15552번
시도 - 1번
*/
#include <iostream>
using namespace std;

int main(void) {
    cin.tie(NULL); // cin, cout untie 시키기 
    ios_base::sync_with_stdio(false); // 버퍼 동기화 비활성화시키기

    int T, A, B;
    cin>>T;

    for(int i = 0; i < T; i++){
        cin>>A>>B;
        cout<<A+B<<'\n'; // endl 대신 개행문자 이용
    }
    return 0;
}