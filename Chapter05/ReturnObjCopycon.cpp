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
    SoSimple& Adder(int n)
    {
        num+=n;
        return *this; // return self-reference
    }
    void ShowData()
    {
        cout<<num<<endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout<<"return 이전\n";
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    // SimpleFuncObj 리턴 결과 생성된 임시 객체의 num 값 출력
    SimpleFuncObj(obj).Adder(30).ShowData();
    // obj 객체의 num 값 출력 
    obj.ShowData();

    return 0;
}