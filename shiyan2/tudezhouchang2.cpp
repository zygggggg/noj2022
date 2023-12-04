/*
1、跟之前一样 图不用回溯 ……？ 
2、妈的 没有全部初始化 used没初始化

*/
#include <iostream>
#include <cstring>
using namespace std;

int dx[8]={0,1,0,-1,1,1,-1,-1};//右 下 左 上
int dy[8]={1,0,-1,0,1,-1,-1,1};
int m,n,x,y;
const int N=20;
char a[N][N];
int weight [N][N]; //边长
bool used [N][N]; // 走过
int res =0;
void dfs(int x,int y)
{
    if(a[x][y]=='.'){return ;}
    int i;
    int x0,y0;
    weight [x][y]=4;
    used [x][y]=1;
    for(i=0;i<=3;i++)
    {
        x0=x+dx[i];
        y0=y+dy[i];
        if (x0 >=0 && x0 <m && y0 >=0 &&y0<n && a[x0][y0]=='X')  {weight [x][y]--;}
    }
    for (i=0;i<=7 ;i++)
    {
        x0=x+dx[i];
        y0=y+dy[i];
        if (x0 >=0 && x0 <m &&y0 >=0 &&y0<n && a[x0][y0]=='X' && used[x0][y0]== 0 )
        {
            dfs (x0 ,y0 );
        }  
    }
    
}

int main()
{
    while(cin>>m>>n>>x>>y)
    {
        if(m==0 && n ==0){break;}
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        dfs (x-1,y-1);
        for (i=0 ;i<m ;i++)
        {
            for (j=0 ;j<n ;j++)
            {
                res += weight [i][j];
            }
        }
        cout <<res <<endl;
        memset ( weight ,0 ,sizeof weight );
        memset ( a ,0 ,sizeof a );
        memset(used, false, sizeof(used));
        res =0;
    }
    return 0;
}

/*
2 2 2 2 XX XX 6 4 2 3 .XXX .XXX .XXX ...X ..X. X... 0 0 0 0

输出样例
8 18
*/