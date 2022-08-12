#include <iostream>
using namespace std;

class SoSimple
{
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout<<"New Object: "<<this<<"\n";
    }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout<<"New Copy Obj: "<<this<<"\n";
    }
    ~SoSimple() 
    {
        cout<<"Destroy obj: "<<this<<"\n";
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout<<"Param ADR: "<<&ob<<"\n";
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj);

    cout<<endl;
    SoSimple tempRef = SimpleFuncObj(obj);
    cout<<"Return Obj "<<&tempRef<<endl;

    return 0;
}