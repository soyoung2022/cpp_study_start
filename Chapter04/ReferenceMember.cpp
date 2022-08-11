#include <iostream>
using namespace std;

class AAA
{
public:
    AAA() 
    {
        cout<<"Empty object"<<endl;
    }
    void ShowYourName() 
    {
        cout<<"I'm Class AAA"<<endl;
    }
};

class BBB
{
    AAA &ref;
    const int &num;
public:
    BBB(AAA &r, const int &n):ref(r), num(n)
    {
        // empty constructor body
    }
    void ShowYourName() 
    {
        ref.ShowYourName();
        cout<<"and\n";
        cout<<"I'm ref num "<<num<<endl;
    }
};

int main(void) 
{
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();

    return 0;
}