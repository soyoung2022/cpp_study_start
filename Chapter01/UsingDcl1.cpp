#include <iostream>

namespace Hybrid
{
    void HybFunc(void)
    {
        std::cout<<"So simple function!"<<std::endl;
        std::cout<<"In namesapce Hybrid!"<<std::endl;
    }
}

int main(void) {
    using Hybrid::HybFunc; // keyword using을 통해 이름공간 Hybrid에 선언된 함수 호출 시 이름공간 지정하지 않고  호출하겠다는 것을 선언함
    HybFunc(); // 이름공간 지정 없이 호출함 

    return 0;
}