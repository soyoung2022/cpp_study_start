#include <iostream>
using namespace std;

class TwoNumber
{
    int num1;
    int num2;
public:
    TwoNumber(int num1, int num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }
    /* 
    위 생성자를 대체할 수 있는 이니셜라이저 방식 
    TwoNumber(int num1, int num2) : num1(num1), num2(num2)
    {
    }
    */
    void ShowTwoNumber() {
        cout<<this->num1<<endl;
        cout<<this->num2<<endl;
    }
};

int main(void)
{
    TwoNumber two(2, 4);
    two.ShowTwoNumber();
    return 0;
}