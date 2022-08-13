#include <iostream>
using namespace std;

int simObjCnt=0;
int cmxObjCnt=0;

class SoSimple
{
public:
    SoSimple()
    {
        simObjCnt++;
        cout<<simObjCnt<<"번째 SoSimple 객체\n";
    }
};

class SoComplex
{
public:
    SoComplex()
    {
        cmxObjCnt++;
        cout<<cmxObjCnt<<"번째 SoCimplex 객체\n";
    }
    SoComplex(SoComplex &copy){
        cmxObjCnt++;
        cout<<cmxObjCnt<<"번째 SoComplex 객체\n";
    }
};

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2=com1;
    SoComplex();

    return 0;
}