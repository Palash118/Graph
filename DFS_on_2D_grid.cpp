#include<bits/stdc++.h>
using namespace std;

int n,m;
bool vis[1001][1001];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool is_valid(int x,int y)
{
    if(x<1 || y<1 || x>n || y>m)
        return false;
    if(vis[x][y]==true)
        return false;
    return true;
}

void dfs(int x,int y)
{
    vis[x][y] = true;
    cout << x << '\t' << y << endl;
    for(int i=0;i<4;i++)
    {
        if(is_valid(x+dx[i],y+dy[i]))
            dfs(x+dx[i],y+dy[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    dfs(1,1);
    return 0;
}
