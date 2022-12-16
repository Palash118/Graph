#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxN 100000

vector < int > v[maxN];
bool visited[maxN];

void dfs(int s)
{
    visited[s] = true;
    for(int i=0;i<v[s].size();i++)
    {
        if(visited[v[s][i]] == false)
        {
            dfs(v[s][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int vertex,edge,a,b;
    int component = 0;
    cin >> vertex >> edge;
    for(int i=1;i<=edge;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=vertex;i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
            component++;
        }
    }
    cout << component << endl;
    return 0;
}
