#include <iostream>
using namespace std;

namespace BestComImpl
{
    void SimpleFunc(void);
} // namespace BestComImp

namespace ProgComImpl
{
    void SimpleFunc(void);
} // namespace ProgComImpl

int main(void){
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    
    return 0;
}

void BestComImpl::SimpleFunc(void){
    cout<<"BestCom이 정의한 함수"<<endl;
}
void ProgComImpl::SimpleFunc(void) {
    cout<<"ProgCom이 정의한 함수"<<endl;
}