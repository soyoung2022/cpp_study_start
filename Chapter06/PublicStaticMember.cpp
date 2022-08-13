#include <iostream>
using namespace std;

class SoSimple
{
public:
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt=0;

int main(void)
{
    cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체\n";
    SoSimple sim1;
    SoSimple sim2;

    cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체\n";
    cout<<sim1.simObjCnt<<"번째 SoSimple 객체\n";
    cout<<sim2.simObjCnt<<"번째 SoSimple 객체\n";

    return 0;
}