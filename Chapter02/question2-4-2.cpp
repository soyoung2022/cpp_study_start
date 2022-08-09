#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(void) {
    srand(time(NULL)); // seed를 현재 시간으로 주기 

    for(int i = 0; i < 5; i++){
        cout<<i+1<<"번째 난수 = ";
        int random_number = rand()%101; // 0~100까지의 난수 구하기 
        cout<<random_number<<endl;
    }
    return 0;
}