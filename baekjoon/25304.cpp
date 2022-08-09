/*
백준 25304번 
시도 - 1번
*/
#include <iostream>
using namespace std;

int main(void) {
    int X, N;
    cin>>X;
    cin>>N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin>>a>>b;
        X -= (a*b);
        if(X < 0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(X == 0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}