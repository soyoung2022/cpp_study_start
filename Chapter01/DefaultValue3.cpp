#include <iostream>
using namespace std;

int BoxVolume(int length, int width=1, int height=1);

int main(void) {
    cout<<"[3, 3, 3] : "<<BoxVolume(3, 3, 3)<<endl;
    cout<<"[5, 5, D] : "<<BoxVolume(5, 5)<<endl;
    cout<<"[7, D, D] : "<<BoxVolume(7)<<endl;
    // cout<<"[D, D, D] : "<<BoxVolume()<<endl; 컴파일 에러 발생

    return 0;
}

int BoxVolume(int length, int width, int height) {
    return length * width * height;
}