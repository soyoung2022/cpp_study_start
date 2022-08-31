#include <iostream>
using namespace std;

class First
{
public:
    void FirstFunc() {cout<<"FirstFunc()\n";}
    virtual void SimpleFunc() {cout<<"First's SimpleFunc()\n";}
};

class Second: public First
{
public:
    void SecondFunc() {cout<<"SecondFunc()\n";}
    void SimpleFunc() {cout<<"Second's SimpleFunc()\n";}
};

class Third: public Second
{
public:
    void ThirdFunc() {cout<<"ThirdFunc()\n";}
    void SimpleFunc() {cout<<"Third's SimpleFunc()\n";}
};

int main(void)
{
    Third obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.SimpleFunc();

    Second &sref = obj;
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();

    First &fref = obj;
    fref.FirstFunc();
    fref.SimpleFunc();

    return 0;
}