#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, vector<int> graph[], bool visit[])
{
    stack<int> s;
    s.push(start);
    visit[start] = true;
    cout<<start<<"\n";

    while(!s.empty()) // 스택이 빌 때까지
    {
        int current = s.top();
        s.pop(); 

        for(int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if(!visit[next])
            {
                cout<<next<<"\n";
                s.push(current); // current도 다시 push
                s.push(next);
                visit[next] = true;
                break; // 너비가 아니라 깊이 우선이므로 한 번 찾으면 break 필요
            }
        }
    }
}

int main(void)
{
    int n, e, start;
    cin>>n>>e>>start;

    vector<int> graph[n+1];
    bool visit[n+1];
    fill_n(visit, n+1, false);

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 정렬하기 
    for(int i = 0; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start, graph, visit);

    return 0;
}