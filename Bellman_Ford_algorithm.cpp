#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+7
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int node,edge;
    cin >> node >> edge;
    vector < tuple < int,int,int > > v;
    int dist[node+1];
    for(int i=1;i<=node;i++)
    {
        dist[i] = INF;
    }
    int starting_node;
    cin >> starting_node;
    dist[starting_node] = 0;
    for(int i=1;i<=edge;i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        v.push_back({a,b,w});
    }
    for(int i=1;i<node;i++)
    {
        for(auto e : v)
        {
            int a,b,w;
            tie(a,b,w) = e;
            dist[b] = min(dist[b],dist[a]+w);
        }
    }
    for(auto e : v)
    {
        int a,b,w;
        tie(a,b,w) = e;
        if(dist[a]+w < dist[b])
        {
            cout << "Negative Cycle." << endl;
            return 0;
        }
    }
    for(int i=1;i<=node;i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
