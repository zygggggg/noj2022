/*
1、注意used！！
2、注意是 int dfs  那么最后要return 0   用到dfs的时候也要return！
*/
#include <iostream>

using namespace std;

const int N=30;
char a[N][N];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int st1,st2,ed1,ed2;
int m,n;
bool used[N][N];
bool dfs(int st1,int st2)
{
    if(a[st1][st2]=='1'){return 0;}
    if(st1==ed1&&st2==ed2){return 1;}
    int i;
    for(i=0;i<=3;i++)
    {
        int x=st1+dx[i],y=st2+dy[i];
        if(x>=0&&x<=m&&y>=0&&y<=n&&a[x][y]=='0'&&used[x][y]==0)
        {
            used[x][y]=1;
            return dfs(x,y);
            // used[x][y]=0;  找到就行 应该不用回溯
        }
    }
return 0;
}

int main()
{
    cin>>m>>n;
    int i,j;
    cin>>st1>>st2>>ed1>>ed2;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    used[st1][st2]=1;
    if(dfs(st1,st2)){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
    return 0;
}
/*
3 3
0 0
2 2
0 0 0
1 1 0
0 1 0
*/