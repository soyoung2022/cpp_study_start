#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<int> g[], bool visit[])
{
    visit[start] = true;
    cout<<start<<'\n';

    for(int i = 0; i < g[start].size(); i++)
    {
        int next = g[start][i];

        if(!visit[next]) // 방문하지 않은 노드라면 다시 탐색 
        {
            dfs(next, g, visit); // 재탐색 시 재귀 사용 
        }
    }
}

int main(void)
{
    int n, e, start;
    cin>>n>>e>>start;

    vector<int> graph[n+1];
    bool visit[n+1];
    fill_n(visit, n+1, false); // 배열 false로 채우기

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin>>u>>v;
        // 무방향 그래프로 간주
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(start, graph, visit);

    return 0;
}