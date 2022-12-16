#include<bits/stdc++.h>
using namespace std;

vector < int > v[101];
int dis[101];
int low[101];
bool visited[101];
int timer;
vector < int > arti;

void articulation_point(int node,int par)
{
    timer++;
    dis[node] = low[node] = timer;
    visited[node] = true;
    int no_of_children = 0;
    for(int child : v[node])
    {
       if(child == par) continue;
       if(visited[child]==true)
         low[node] = min(low[node],dis[child]);
       else if(visited[child] == false)
       {
           articulation_point(child,node);
           low[node] = min(low[node],low[child]);
           if(dis[node] <= low[child] && par != -1)
           {
               arti.push_back(node);
           }
           no_of_children++;
       }
       if(no_of_children>1 && par == -1)
       {
           arti.push_back(node);
       }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int node,edge,x,y;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    articulation_point(1,-1);
    for(int n : arti)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
