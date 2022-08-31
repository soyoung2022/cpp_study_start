#include <iostream>
using namespace std;

class First
{
public:
    virtual void MyFunc() // 가상함수의 선언 
    {
        cout<<"FirstFunc\n";
    }
};

class Second : public First
{
public:
    void MyFunc()
    {
        cout<<"SecondFunc\n";
    }
};

class Third : public Second
{
public:
    void MyFunc()
    {
        cout<<"ThirdFunc\n";
    }
};

int main(void)
{
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;

    tptr->MyFunc();
    sptr->MyFunc();
    fptr->MyFunc();
    delete tptr;

    return 0;
}