#include <iostream>
using namespace std;

class SoBase
{
    int baseNum;
public:
    SoBase() : baseNum(20)
    {
        cout<<"SoBase()\n";
    }
    SoBase(int n) : baseNum(n)
    {
        cout<<"soBase(int n)\n";
    }
    void ShowBaseData() const
    {
        cout<<baseNum<<"\n";
    }
};

class SoDerived : public SoBase
{
    int derivNum;
public:
    SoDerived() : derivNum(30)
    {
        cout<<"SoDerived()\n";
    }
    SoDerived(int n) : derivNum(n)
    {
        cout<<"SoDerived(int n)\n";
    }
    SoDerived(int n1, int n2) : derivNum(n1), SoBase(n2)
    {
        cout<<"SoDerived(int n1, int n2)\n";
    }
    void ShowDerivData()
    {
        ShowBaseData();
        cout<<derivNum<<"\n";
    }
};

int main(void)
{
    cout<<"case1......\n";
    SoDerived dr1;
    dr1.ShowDerivData();
    cout<<"----------------------\n";
    cout<<"case2.......\n";
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout<<"----------------------\n";
    SoDerived dr3(12, 23);
    dr3.ShowDerivData();

    return 0;
}