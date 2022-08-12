#include <iostream>
using namespace std;

class SoSimple
{
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2)
    :num1(n1), num2(n2)
    {
    }
    // SoSimple(const SoSimple & copy)
    // :num1(copy.num1), num2(copy.num2)
    // {
    //     cout<<"Called SoSimple(SoSimple & copy)\n";
    // }
    void ShowSimpleData() 
    {
        cout<<num1<<endl;
        cout<<num2<<endl;
    }
};

int main(void) {
    SoSimple sim1(10, 20);
    cout<<"생성 및 초기화 직전\n";
    SoSimple sim2 = sim1; // SoSimple sim2(sim1)
    cout<<"생성 및 초기화 직후\n";
    sim2.ShowSimpleData();

    return 0;
}