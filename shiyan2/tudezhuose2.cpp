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

输出  48 ？ 96？ 
*/
/*
1、注意是r条边 不能用n sb!!
2、卧槽！！ 破案！！ 要从dfs1  注意有5号位   这题不能随便dfs0
*/
#include <iostream>
#include <cstring>
using namespace std;
int n,r,m; //n个顶点 r条边 m个颜色 
const int N=110;
int g[N][N];  //边
int colour [N]; //第i个点
int cnt=0;
bool pending (int t,int col)//  第t个点 （后面的点没色 col是颜色）
{
    int i;
    for(i=0;i<t;i++)
    {
        if (g[t][i]==1 && col == colour [i]){return 0;}
    }
    return 1;
}

void dfs(int t )
{
    if (t==n ){cnt ++; return ;}
    int i;
    for(i=1;i<=m;i++) //第t个点 第i个色
    {
        if (pending (t,i))
        {
            colour [t]=i; //可以的话 那么就放这个颜色 下一个
            dfs (t+1);
            colour [t]=0;
        }
    }
}

int main()
{
    int i;
    cin>>n>>r>>m;
    int u,v;
    for(i=0;i<r;i++)
    {
        cin >>u >> v;
        g[u][v]=g[v][u]=1;
    }
    dfs (0);
    cout <<cnt <<endl;
    return 0;
}