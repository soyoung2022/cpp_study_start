#include <iostream>
using namespace std;

void AddOne(int &num)
{
    num++;
}

void ChangeSign(int &num)
{
    num = (-num);
}

int main(void)
{
    int number = 3;

    AddOne(number);
    cout << "AddOne: " << number << endl;
    ChangeSign(number);
    cout << "ChangeSign: " << number << endl;
    int num2 = -9;
    ChangeSign(num2);
    cout<<"ChangeSign(negative number): "<<num2<<endl;

    return 0;
}