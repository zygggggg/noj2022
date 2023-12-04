#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair <int , int > PII;
int st1,st2,ed1,ed2;
const int N=15;
char g[N][N];
int d[N][N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int bfs (int st1, int st2)
{
    queue <PII> q;
    d[st1][st2]=0;
    q.push({st1,st2});
    int i;
    while (!q.empty())
    {
        PII now = q.front();
        q.pop ();
        for (i=0;i<4;i++)
        {
            int nx=now.first+dx[i];
            int ny=now.second+dy[i];
            if (nx>=0 && nx <=11 && ny >=0 && ny<=11 && g[nx][ny]=='.' && d[nx][ny]==-1 )
            {
                d[nx][ny]=d[now.first][now.second]+1;
                q.push ({nx,ny});
            }
        }
    }
    return d[ed1][ed2];
}
int main()
{   
    memset (d, -1 , sizeof d) ;
    cin >> st1 >> st2 >>ed1 >>ed2 ;
    int i;
    int j;
    st1--,st2--,ed1--,ed2--;
    for (i=0;i<=11;i++) //从0开始 注意变st ed
    {
        for (j=0;j<=11;j++)
        {
            cin >> g[i][j];
        }
    }
    cout << bfs(st1, st2) ;
    return 0;
}

/*
2 9 11 8
XXXXXXXXXXXX
X......X.XXX
X.X.XX.....X
X.X.XX.XXX.X
X.X.....X..X
X.XXXXXXXXXX
X...X.X....X
X.XXX...XXXX
X.....X....X
XXX.XXXX.X.X
XXXXXXX..XXX
XXXXXXXXXXXX

输出样例
28
*/