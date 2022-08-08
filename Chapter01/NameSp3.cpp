#include <iostream>
using namespace std;

namespace BestComImpl
{
    void SimpleFunc(void);
} // namespace BestComImp

namespace BestComImpl
{
    void PreetyFunc(void);
}

namespace ProgComImpl
{
    void SimpleFunc(void);
}

int main(void){
    BestComImpl::SimpleFunc();
    return 0;
}

void BestComImpl::SimpleFunc(void) {
    cout<<"BestCom이 정의한 함수"<<endl;
    PreetyFunc(); //  동일한 이름공간 BestComImpl에 정의된 함수 호출 시 이름공간 명시할 필요 없다. 

}

void BestComImpl::PreetyFunc(void) {
    cout<<"So Pretty!!"<<endl;
}

void ProgComImpl::SimpleFunc(void) {
    cout<<"ProgCom이 정의한 함수"<<endl;
}