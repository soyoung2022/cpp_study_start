#include <iostream>
using namespace std;

class Temporary
{
    int num;
public:
    Temporary(int n) : num(n)
    {
        cout<<"create obj: "<<num<<"\n";
    }
    ~Temporary()
    {
        cout<<"destroy obj: "<<num<<"\n";
    }
    void ShowTempInfo()
    {
        cout<<"My num is "<<num<<endl;
    }
};

int main(void)
{
    Temporary(100);
    cout<<"******** after make!"<<endl<<endl;

    Temporary(200).ShowTempInfo();
    cout<<"******** after make!"<<endl<<endl;

    const Temporary &ref = Temporary(300); // 임시 객체는 참조 값을 반환한다. 
    cout<<"******** end of main!"<<endl<<endl;

    return 0;
}