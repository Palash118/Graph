#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector < int > v[1000];
int level[1000];
bool visited[1000];

int bfs(int s,int s1)
{
    queue < int > q;
    q.push(s);
    level[s] = 0;
    visited[s] = false;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i=0;i<v[p].size();i++)
        {
            if(visited[v[p][i]] == false)
            {
                level[v[p][i]] = level[p] +1;
                q.push(v[p][i]);
                visited[v[p][i]] = true;

            }
        }
    }
    return level[s1];
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout << "Adjacency List : " << endl;
    for(int i=1;i<=vertex;i++)
    {
        cout << i << " -- ";
        for(int j=0;j<v[i].size();j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Shortest path : " << bfs(1,3) << endl;
    return 0;
}
