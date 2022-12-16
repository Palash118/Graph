#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+7
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int node,edge,x,y,weight;
    cin >> node >> edge;
    int dist[node+1][node+1];
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(i==j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    for(int i=1;i<=edge;i++)
    {
        cin >> x >> y >> weight;
        dist[x][y] = weight;
        dist[y][x] = weight;
    }
    for(int k=1;k<=node;k++)
    {
        for(int i=1;i<=node;i++)
        {
            for(int j=1;j<=node;j++)
            {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
