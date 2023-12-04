/*
3 2 2
0 1
1 2
*/
/*
5 8 4
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5

输出
48
*/
#include <iostream>

using namespace std;
const int N=110;
int g[N][N];
int colour[N];
int n,r,m;
int cnt=0;
bool pending(int t)
{
    int i=0;
    for(i=0;i<n-1;i++)
    {
        if(g[t][i]==1&&colour[i]==colour[t])return 0;
    }
    return 1;
}

void dfs(int t)
{
    if(t>=n){cnt++;return ;}
    int i;
    for(i=1;i<=m;i++)
    {
        colour[t]=i;
        if(pending(t))
        {
            dfs(t+1);
        }
        colour[t]=0;
    }
}


int main()
{
    int i,u,v;
    cin>>n>>r>>m;//n个点 r条边  m种颜色
    for(i=0;i<r;i++)
    {
        cin>>u>>v;
        g[v][u]=1;
        g[u][v]=1;
    }
    dfs(0);
    cout<<cnt<<endl;
    return 0;       
}