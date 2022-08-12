#include <iostream>
using namespace std;

class SoSimple
{
    int num;
public:
    SoSimple(int n) : num(n) { }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout<<"Called SoSimple(const SoSimple& copy)\n";
    }
    void ShowData()
    {
        cout<<num<<endl;
    }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7);
    cout<<"함수호출 전\n";
    SimpleFuncObj(obj);
    cout<<"함수호출 후\n";

    return 0;
}