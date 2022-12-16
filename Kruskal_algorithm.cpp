#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4+5;
int id[MAX],node,edge;
pair < int, pair < int,int > > p[MAX];

void initialize()
{
    for(int i=0;i<MAX;i++)
    {
        id[i] = i;
    }
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x,int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

int kruskal(pair<int,pair<int,int> > p[])
{
    int x,y,cost,minimum_cost = 0;
    for(int i=0;i<edge;i++)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            minimum_cost += cost;
            union1(x,y);
        }
    }
    return minimum_cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,y,weight,minimum_cost,cost;
    initialize();
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight,make_pair(x,y));
    }
    sort(p,p+edge);
    minimum_cost = kruskal(p);
    cout << minimum_cost << endl;
    return 0;
}
