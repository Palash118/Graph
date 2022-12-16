#include<bits/stdc++.h>
using namespace std;
int ara[100000];
int node;
bool Find(int ara[],int a,int b)
{
    if(ara[a] == ara[b])
        return true;
    else
        return false;
}

void Union(int ara[],int a,int b)
{
    int temp = ara[a];
    for(int i=0;i<node;i++)
    {
        if(ara[i] == temp)
            ara[i] = ara[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> node;
    int ara[node];
    for(int i=0;i<node;i++)
    {
        ara[i] = i;
    }
    Union(ara,2,1);
    Union(ara,4,3);
    Union(ara,8,4);
    Union(ara,9,3);
    Union(ara,6,5);
    Union(ara,5,2);
    int t;
    for(int i=0;i<node;i++)
    {
        cout << ara[i] << " ";
    }
    cout << endl;
    cin >> t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        if(Find(ara,a,b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
