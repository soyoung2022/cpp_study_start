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
## Chapter 02
### bool 자료형
> C언어에는 없지만 c++에는 존재하는 기본 자료형(하지만, 최근에는 C 표준에서 지원하는 경우도 있음)

- true와 false는 각각 참과 거짓을 표현하기 위한 1바이트 크기의 데이터다. 

    👉🏻 데이터의 크기 알기 위해 sizeof() 연산자 사용할 수 있음
- true와 false가 온 자리가 숫자를 위한 자리라면, true는 1로, false는 0으로 해석된다. 
### 참조자(Reference)
> 참조자는 자신이 참조하는 변수를 대신할 수 있는 하나의 이름이다. 여기서 알 수 있는 것은 "변수"에 사용할 수 있다는 것이고, 별명과 비슷하다는 것이다. 

- &이 이미 선언된 변수 앞에 오면 주소 반환 의미를 가지지만, 새로 선언되는 변수 이름 앞에 오면 참조자의 선언을 의미하게 된다. 
- 참조자는 선언과 동시에 어떤 변수를 참조해야 한다. 또한, 참조의 대상을 바꾸는 것도 안된다. 
- NULL에 대해 참조할 수 없다.
- 참조자로 값을 바꿀 수 있다. 
- 참조자와 참조자가 참조하는 변수의 주소 값은 같다. 
- 지역적 참조자는 지역 변수와 같이, 함수 빠져나가면 소멸된다. 
- 참조자에 &을 붙여 주소를 알아낼 수 있다.
- 하나의 변수에 대해 여러 참조자를 선언하는 것도 가능하다(개수 제한 없다)
- 참조자에 대해 또 다른 참조자를 선언해도 된다. 
```c++
int num = 1010;
int &num2 = num1; // num2는 num1의 참조자이다. 
num2 = 3030; // num1과 num2의 값이 3030으로 바뀜 
cout<<"&num2 : "<<&num2<<endl; // 참조자 주소 알아내기
int array[2] = {1,2};
int &num3 = array[1]; // 배열의 원소도 참조할 수 있다. 
```
### Call-by-reference와 참조자
> Call-by-reference는 주소 값을 전달받아, 함수 외부에 선언된 변수에 접근하는 형태의 함수호출을 의미한다. 
여기서 핵심은 함수 외부에 선언된 변수에 접근하는 것이다.

✨ C++에서는 주소 값뿐만 아니라 참조자를 이용해 Call-by-reference 형태의 함수를 정의할 수 있다. 

✔️ 딘점
- 코드 분석하는 과정에서 함수의 호출문장만 보고도 함수의 특성을 어느 정도 판단할 수 있어야 하는데, 참조자를 매개변수로 하는 함수는 이를 파악하기 어렵다. 

👉🏻 해결법
> const를 이용하자! 함수 내에서 참조자를 이용해 값을 변경하지 않으면 const를 사용해 참조자를 선언해 함수의 원형을 보고 값의 변형이 일어나지 않음을 알 수 있도록 한다. 

```c++
void HapyFunc(const int &ref) {
    ...
}
```
- 지역변수를 참조형으로 반환하면 안된다!
- 상수화된 변수에 대해서는 const 참조자 선언이 이루어져야 한다. 
- const 참조자는 상수를 참조할 수 있다. 
- ✨ const 참조자를 이용해 함수를 정의하면, 함수 호출 시 변수 선언을 하지 않고 원하는 상수를 넘길 수 있다! ✨
```c++
const int a = 10; // a는 상수화된 '변수'이다. 
const int &ref = a; // const 참조자 선언 : a 값 변경 불가능
const int &refC = 3;
```
### new & delete 
> new는 malloc을 대신하는 키워드이고, delete은 free를 대신하는 키워드이다. 

- 사용 방법은 다음과 같다. 
```c++
int * ptr = new int;
double * arrayptr = new double[20];

delete ptr;
delete []arrayptr;
```

- new 키워드로 힙에 할당된 메모리에 참조자를 선언할 수 있다. 
    👉🏻 포인터 연산 없이 힙 영역에 접근했다는 사실이 중요하다!

- new와 malloc의 작동 방법에 차이가 있는데, 이는 아래 코드에서 확인할 수 있다. 
```c++
#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
    public:
    Simple()
    {
        cout<<"I'm Simple constructor!"<<endl;
    }
};

int main(void) {
    cout<<"case 1 : ";
    Simple * sp1 = new Simple;

    cout<<"case 2 : ";
    Simple * sp2 = (Simple*) malloc(sizeof(Simple)*1);
    
    cout<<endl<<"end of main"<<endl;
    delete sp1;
    free(sp2);
    
    return 0;
}
```
### C언어의 표준 함수 C++에서 출력하기
> C언어의 헤어파일에서 확장자 .h를 빼고 맨 앞에 c를 붙이면 그 헤더파일에 대응되는 C++의 헤더파일이 된다. 
물론 그냥 C언어 헤더파일을 이용해도 되지만, 그냥 C++ 헤더파일을 이용하는 것이 좋다고 한다. 함수들이 c++ 형태로 개선되어 작성되기 때문이다. 

👉🏻 단, C 표준 함수들도 이름공간 std 안에 선언되어 있어 std::를 사용하거나 using namespace std;를 작성해야 한다. 


----------------------------

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