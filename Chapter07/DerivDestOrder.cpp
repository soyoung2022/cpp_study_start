#include <iostream>
using namespace std;

class SoBase
{
    int baseNum;
public:
    SoBase(int n) : baseNum(n)
    {
        cout<<"SoBase() : "<<baseNum<<"\n";
    }
    ~SoBase()
    {
        cout<<"~SoBase() : "<<baseNum<<"\n";
    }
};

class SoDerived : public SoBase
{
    int derivNum;
public:
    SoDerived(int n) : SoBase(n), derivNum(n)
    {
        cout<<"SoDerived() : "<<derivNum<<"\n";
    }
    ~SoDerived()
    {
        cout<<"~SoDerived() : "<<derivNum<<"\n";
    }
};

int main(void)
{
    SoDerived drv1(15);
    SoDerived drv2(27);
    
    return 0;
}