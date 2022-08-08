#include <iostream>

int main(void) {
    double val1;
    std::cout<<"첫 번째 숫자 입력: ";
    std::cin>>val1; // cin 입력받기

    double val2;
    std::cout<<"두 번째 숫자 입력: ";
    std::cin>>val2;

    double result=val1+val2;
    std::cout<<"덧셈결과 = "<<result<<std::endl;
    return 0;
}