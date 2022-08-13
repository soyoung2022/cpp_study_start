#include <iostream>
using namespace std;

class SoSimple
{
    int num;
public:
    SoSimple(int n) : num(n) {}
    SoSimple& Addnum(int n)
    {
        num += n;
        return *this; 
    }
    void ShowData() const 
    {
        cout<<"num: "<<num<<"\n";
    }
};

int main(void)
{
    const SoSimple obj(7);
    // obj.Addnum(3); --> const라서 안 됨
    obj.ShowData();
    return 0;
}