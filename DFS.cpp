/** Depth First Search ( Calculating Number of Connected Components **/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector < int > v[1000];
bool visited[1000];

void dfs(int s) {
    visited[s] = true;
    for(int i=0;i<v[s].size();i++) {
        if(visited[v[s][i]] == false)
            dfs(v[s][i]);
    }
}

int main()  {
    int node,edge,x,y,component=0;
    cout << "Enter the number of Node :";
    cin >> node;
    cout << "Enter the number of Edge :";
    cin >> edge;
    //cin >> node >> edge;
    cout << "Enter Source and Destination Node" << endl;
    for(int i=1;i<=edge;i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=node;i++)  {
        if(visited[i] == false)   {
            dfs(i);
            component++;
        }
    }
    cout << component << endl;
    return 0;
}
