#include <iostream>
using namespace std;

class SoSimple
{
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
        cout<<simObjCnt<<"번째 SoSimple 객체\n";
    }
};
int SoSimple::simObjCnt=0;

class SoComplex
{
    static int cmxObjCnt;
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
int SoComplex::cmxObjCnt=0;

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2=com1;
    SoComplex();

    return 0;
}