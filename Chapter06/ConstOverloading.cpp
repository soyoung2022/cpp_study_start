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
    void SimpleFunc()
    {
        cout<<"SimpleFunc: "<<num<<endl;
    }
    void SimpleFunc() const 
    {
        cout<<"const SimpleFunc: "<<num<<"\n";
    }
};

void YourFunc(const SoSimple &obj)
{
    obj.SimpleFunc();
}

int main(void)
{
    SoSimple obj1(2);
    const SoSimple obj2(7);

    obj1.SimpleFunc();
    obj2.SimpleFunc(); // const 객체이므로 const 함수 호출 

    YourFunc(obj1); // 매개변수로 const 참조자 --> const 함수 호출 
    YourFunc(obj2);

    return 0;
}