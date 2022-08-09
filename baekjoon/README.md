# 백준 문제 풀이하며 공부한 내용 정리
## 작성 형식
- heading2로 번호와 어떤 내용에 대한 정리인지 간단하게 적기
- heading3는 각 내용 소제목
- 그 아래에 정리하고자 하는 내용 적기

--- 

## 15552번 (15552.cpp) - 입출력에서 실행 속도 높이기 
### ios_base::sync_with_stdio(false);
✔️ 장점
> ios_base::sync_with_stdio는 C의 stdio와 C++의 iostream을 동기화하는 역할을 한다. 이때, stdio와 iostream의 buffer를 모두 사용하기 때문에, 시간적 딜레이가 발생한다. 따라서 이를 false로 동기화를 비활성화시키면, 독립적인 buffer를 사용하게 되어 실행 속도가 빨라진다.

✔️ 단점
> 동기화된 C++ buffer는 thread-safe를 보장하지만, 동기화가 비활성화된 C++ buffer는 이를 보장하지 않는다. 따라서 멀티 스레드 환경에서 출력 순서를 보장하지 않는다. 또한, C의 버퍼와 분리되었기에 gets, printf, scanf 등을 사용할 수 없다. 


### cin.tie(NULL);
> cin을 cout으로부터 untie한다. 기본적으로 cin과 cout은 tie된 상태인데, 이 상태에서는 출력을 하기 위해 직접 flush하지 않아도 된다. 다른 스트림이 작업을 요청하면 자동적으로 버퍼를 flush하는 것을 보장하기 때문이다. 입출력이 반복된다면, 계속해서 버퍼를 flush하느라 시간이 소요된다. 이를 cin과 cout를 untie함으로써 해결한다. 단, untie되면 묶음이 풀리며 입력 전에 먼저 출력을 원한다면 수동으로 flush 해줘야 한다. 

👉🏻 예시
```c++
#include <iostream>
using namespace std;

int main(void){
    int number;
    cin.tie(NULL); // stream untie
    cout<<"Enter number: "; // output이 출력되지 않고 (flush되지 않은 상태로)
    cin>>number;            // 사용자에게 입력 요구

    return 0;
}
```

### endl 대신 개행문자를 사용하자
> endl은 개행과 함께 출력 버퍼를 지우는 일도 같이 해서 딜레이가 발생한다. 따라서, 실행 속도를 높이기 위해서는 endl 대신 개행문자(\n)를 사용하는 것이 좋다. 

---