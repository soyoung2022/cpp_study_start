#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 9; // 정점의 개수 9개 
bool visit[MAX];
vector<int> list[MAX];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while(!q.empty()) // 큐에 값이 있을 경우 걔속 반복
    {
        int current = q.front();
        q.pop();
        cout<<current<<"\n";

        for(int i = 0; i < list[current].size(); i++)
        {
            int next = list[current][i];
            if(!visit[next]) // 정점을 아직 방문하지 않았을 때 
            {
                q.push(next);
                visit[next] = true;
            }
        }
    }
}

int main(void)
{
    int v, u, count = 8; // 8개의 간선 입력 가능하도록 설정 
    while(count--)
    {
        cin>>v>>u;
        // 무방향 그래프로 간주 --> 양쪽 다 벡터에 추가  
        list[v].push_back(u);
        list[u].push_back(v);
    }

    bfs(1); // 1번 노드부터 bfs 탐색!

    return 0;
}