#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+5;
typedef pair < int,int > PII;
bool marked[MAX];
vector < PII > ara[MAX];

int prim(int x)
{
    priority_queue < PII, vector<PII>, greater<PII> > Q;
    int y,minimum_cost = 0;
    PII p;
    Q.push({0,x});
    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        int x = p.second;
        if(marked[x]==true)
            continue;
        minimum_cost += p.first;
        marked[x] = true;
        for(int i=0;i<ara[x].size();i++)
        {
            int y = ara[x][i].second;
            if(marked[y] == false)
            Q.push(ara[x][i]);
        }
    }
    return minimum_cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int node,edge,x,y,weight;
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
        cin >> x >> y >> weight;
        ara[x].push_back(make_pair(weight,y));
        ara[y].push_back(make_pair(weight,x));
    }
    int minimum_cost = prim(1);
    cout << minimum_cost << endl;
    return 0;
}
