#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector < int > v[1000];
bool visited[1000];
int indegree[10000];
vector < int > t;

void topological_sort(int n)
{
    queue < int > q;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            indegree[v[i][j]]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            visited[i] = true;
        }

    }
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        t.push_back(p);
        for(int i=0;i<v[p].size();i++)
        {
            int k = v[p][i];
            if(visited[k]==false)
            {
                indegree[k]--;
                if(indegree[k]==0)
                {
                    q.push(k);
                    visited[k] = true;
                }
            }
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
    for(int i=1;i<=edge;i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
    }
    topological_sort(vertex);
    for(int i=0;i<t.size();i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
    return 0;
}
