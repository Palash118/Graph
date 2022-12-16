#include<bits/stdc++.h>
using namespace std;

vector < int > ar[1001];
vector < int > tr[1001];
vector < int > order;
vector < int > SCC;
bool vis[1001];

void dfs(int node)
{
    vis[node] = true;
    for(int child : ar[node])
    {
        if(vis[child]==false)
            dfs(child);
    }
    order.push_back(node);
}

void dfs1(int node)
{
    vis[node] = true;
    for(int child : tr[node])
    {
        if(vis[child]==false)
            dfs1(child);
    }
    SCC.push_back(node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int vertex,edge,a,b;
    cin >> vertex >> edge;
    for(int i=1;i<=edge;i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        tr[b].push_back(a);
    }
    for(int i=1;i<=vertex;i++)
    {
        if(vis[i]==false)
            dfs(i);
    }
    for(int i=1;i<=vertex;i++)
    {
        vis[i] = false;
    }
    for(int i=1;i<=vertex;i++)
    {
        if(vis[order[vertex-i]]==false)
        {
            SCC.clear();
            dfs1(order[vertex-i]);
            for(int node : SCC)
            {
                cout << node << "\t";
            }
            cout << endl;
        }
    }
    return 0;
}
