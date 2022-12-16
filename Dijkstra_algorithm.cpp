#include<bits/stdc++.h>
using namespace std;

#define SIZE 100000+1
bool visited[SIZE];
int dist[SIZE];
vector < pair < int,int > > v[SIZE];

void dijkstra()
{
    multiset < pair < int,int > > q;
    q.insert({0,1});
    while(!q.empty())
    {
        pair < int,int > p = *q.begin();
        q.erase(q.begin());
        int next = p.second;
        if(visited[next])
            continue;
        visited[next] = true;
        for(int i=0;i<v[next].size();i++)
        {
            int w = v[next][i].second;
            int y = v[next][i].first;
            if(dist[next]+w < dist[y])
            {
                dist[y] = dist[next] + w;
                q.insert({dist[y],y});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int vertex,edge,x,y,weight;
    cin >> vertex >> edge;
    for(int i=1;i<=edge;i++)
    {
        cin >> x >> y >> weight;
        v[x].push_back(make_pair(y,weight));
    }
    for(int i=0;i<=vertex;i++)
    {
        visited[i] = false;
        dist[i] = 1e9;
    }
    dist[1] = 0;
    dijkstra();
    for(int i=2;i<=vertex;i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
