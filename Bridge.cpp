#include<bits/stdc++.h>
using namespace std;
vector < int > ara[101];
int in[101],low[101];
bool visited[101];
int timer = 0;

void dfs(int node,int par)
{
    visited[node] = true;
    in[node] = low[node] = timer;
    timer++;
    for(int child : ara[node])
    {
        if(child == par) continue;
        if(visited[child] == true)
        {
            low[node] = min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            if(low[child] > in[node])
                cout << node << " - " << child << endl;
            low[node] = min(low[node],low[child]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int vertex,edge,x,y;
    cin >> vertex >> edge;
    while(edge--)
        cin >> x >> y, ara[x].push_back(y), ara[y].push_back(x);
    dfs(1,-1);
    return 0;
}
