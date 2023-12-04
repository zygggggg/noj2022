/*
1、图的问题 又忘！ 别忘标记！
2、图的问题别忘边界！
3、注意边界处理方法 自己不会
int nx = x + change[i][0];
        int ny = y + change[i][1];
        if(nx>=0 && nx<m && ny>=0 && ny<n
            这样加了之后再判断！
            先加 再判断 再深搜 
4、注意别无脑深搜 判断周长时直接判断四周就好！
5、注意dfs(x-1,y-1);
6、图的问题 经典
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
7、 深搜首要考虑的就是什么时候结束
之前都有if(t>n)
这次不用！ 这次直接等他全部搜完自己退出
回忆迷宫的退出
8、在dfs函数中，判断边界时使用了farm[x+change[i][0]][y+change[i][1]]，
但没有先判断x+change[i][0]和y+change[i][1]是否越界，可能会导致数组越界访问错误。处处都要判断！
9、注意全部都要返回初始值！ 不要落下！ 自己落下了flag
for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        result+=res[i][j];
        farm[i][j]=0;
        str[i][j]=0;
        res[i][j]=0;
        flag[i][j]=false;！！
    }
    cout<<result<<endl;
10 找了亿万年的错！！ res[x][y]=4;要放在dfs里面  因为最后无脑加res 有可能把不连通的什么全加进去了
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int m,n,x,y;
char a[N][N];
int res[N][N];
bool flag[N][N];
int d_row[8]={0,-1,0,1,1,-1,-1,1};
int d_col[8]={-1,0,1,0,-1,-1,1,1};
void dfs(int x,int y)
{
    if(a[x][y]=='.'){return ;}
    res[x][y]=4;
    int i;
    flag[x][y]=1;
    for(i=0;i<=3;i++)
    {
        int dx=x+d_row[i],dy=y+d_col[i];
    if(dx>=1&&dx<=m&&dy>=1&&dy<=n&&a[dx][dy]=='X'){res[x][y]--;}
    }
    for(i=0;i<8;i++)
    {
        int dx=x+d_row[i],dy=y+d_col[i];
        if(dx>=1&&dx<=m&&dy>=1&&dy<=n&&a[dx][dy]=='X'&&flag[dx][dy]==0){dfs(dx,dy);}
    }
    
}
int main()
{
    while(cin>>m>>n>>x>>y)
    {
        if(m==0){break;}
        int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];       
        }
    }
    dfs(x,y);
    int cnt=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cnt+=res[i][j];
        }
    }
    cout<<cnt<<endl;
    cnt=0;
    memset(res,0,sizeof(res));
    memset(a,0,sizeof(a));
    memset(flag,0,sizeof(a));
    }
    return 0;
}