# c++ study
## 교재
> 열혈 C++ 프로그래밍

# 내용 정리
## Chapter 01
### 매개변수에 설정하는 디폴트 값 
- 디폴트 값은 함수의 선언 부분에만 표현하면 된다. 
- 전달되는 인자는 왼쪽에서부터 채워지기 때문에 디폴트 값은 오른쪽부터 채워야 한다. 
- 모든 매개변수에 디폴트 값이 지정되지 않았다면, 인자를 전달하지 않는 형태의 함수 호출은 컴파일 에러로 이어진다. 
### 문제 01-3[매개변수의 디폴트 값]
> 디폴트 값이 있는 매개변수를 가지는 SimpleFunc는 인자로 어떠한 값을 전달하지 않아도 호출되어야 한다. 하지만, void, 즉, 인자로
아무것도 전달되지 않는 SimpleFunc가 존재한다면, 호출할 함수를 찾을 때 오류가 발생한다. 
### 이름공간
- 이름공간 안에 함수를 정의하거나 변수를 선언하면, 같은 이름의 변수나 함수가 있어도 충돌이 발생하지 않는다.
    👉🏻 이름충돌을 막고 싶다면, 이름공간을 활용하자!
- 범위 지정 연산자(scope resolution operator) :: 을 사용하여 이름공간을 지정한다. 
- 이름이 같은 전역변수와 지역변수가 존재할 때, 범위 지정 연산자를 다음과 같이 사용할 수 있다. 
```c++
#include <iostream>

int number=10;

int main(void) {
    int number = 7;
    number += 2; // 지역변수 number에 더하기
    ::number+=2; // 전역변수 number에 더하기 - 범위 지정 연산자 사용

    return 0;
}
```
- 이름공간은 다른 이름공간 안에 삽입될 수 있다. 그럴 때는 이름공간1::이름공간2::변수(함수)명
- using 키워드를 사용해 이름공간 지정 없이 사용할 수 있다. 
- "using 이름공간::함수나 변수 이름" 형태로 사용할 수 있는데, 지역변수 선언과 마찬가지로 선언 이후부터 효력을 발휘하며 선언된 지역을 벗어나면 효력을 잃는다. 
- 다음과 같이 여러 이름공간이 중첩되었을 시, 이름공간에 별칭을 만들 수 있다.
```c++
#include <iostream>
using namespace std;

namespace AAA{
    namespace BBB{
        namespace CCC{
            int num1;
            int num2;
        }
    }
}

int main(void){
    AAA::BBB::CCC::num1=20;
    AAA::BBB::CCC::num2=30;

    namespace ABC=AAA::BBB::CCC; // 별칭 ABC 선언
    cout<<ABC::num1<<endl;
    cout<<ABC::num2<<endl;

    return 0;
}
```

# 오류 정리
## 헤더 파일, 소스 파일 분리했을 때 실행 시 나는 에러
<img width="612" alt="Screen Shot 2022-08-09 at 1 59 06 AM" src="https://user-images.githubusercontent.com/80568332/183473161-74350749-9b43-48df-a71d-04968f1683fe.png">

> 오류가 난 이유를 검색하다 스택오버플로우에서 다음과 같은 글을 찾았다. https://stackoverflow.com/questions/66502205/mac-os-vs-code-insiders-code-runner-undefined-symbols-for-architecture-arm6

### 해결 방법
> 터미널로 해당 파일이 존재하는 디렉토리로 들어가서 다음과 같은 코드를 차례로 작성했더니 실행 파일이 만들어지고, 원하는 값이 나왔다.
```shell
g++ SimpleMain.cpp SimpleFunc.cpp -o SimpleMain
./SimpleMain
```