#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // 벡터를 이용해 인접 리스트 구현하기 
    vector<int> w[6]; // (정점+1)개
    w[1].push_back(2);
    w[1].push_back(4);
    w[2].push_back(3);
    w[3].push_back(4);
    w[4].push_back(5);

    cout<<"정점 1에 인접한 정점들 출력하기\n";
    for(int v : w[1]) // for each 문 이제 C++11에서부터 이용 가능 
    {
        cout<<v<<"\n";
    }
    return 0;
}