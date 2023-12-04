// 用queue
// 反思： 大雪菜里面 其实不要单纯的用PII 而是用node 那么node就可以不止二维
// 那么就可以扩展成 x y res step 对！ step也可以放在这里！！ 
// 还是要加d[N][N] 只是不一定int d[N][N] ; 而是可以弄成node d[N][N]
// 但是还是这样的Life_d d[N][N] 比较清楚 ！！ 因为d用不到x和y
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Node 
{
    int x , y , res ; //剩余血量
};
queue <Node> q;
struct Life_d
{
    int life , d;
};
int m , n , t;
const int N = 210;
char g[N][N];
Life_d d[N][N]; // 步数 其实这个可以在node那里扩展 然后直接 node d[N][N] 但感觉还是这样比较清楚
int homex , homey;
int stx , sty;
int dx[4] = {1 , 0 , -1 , 0};
int dy[4] = {0 , 1 , 0 , -1};
int bfs ()
{
    int i;
    q.push({stx , sty , t});
    d[stx][sty] = {t, 0};
    while (q.empty() == 0)
    {
        int nt;
        Node now = q.front();
        q.pop();
        if (now.x == homex && now.y == homey){return d[now.x][now.y].d;} // 到家
        for (i=0 ; i<4 ; i++)
        {
            int nx = now.x +dx[i];
            int ny = now.y +dy[i];
            if (nx >=0 && nx <m && ny >=0 && ny <n)
            {
                if (g[nx][ny] == 'w')
                {
                    nt = now.res - 1;
                    if(nt == 0){continue;} // 死了 那么这个节点不能加入
                }
                else
                {
                    nt = now.res;
                }
                if (d[nx][ny].d == 0 || (d[nx][ny].d != 0 && d[nx][ny].life < nt) )
                    // 没到过 或者到过 但是在这里的生命值比较小 那么更新在这里的节点
                    { 
                        q.push({nx , ny , nt});
                        d[nx][ny].d = d[now.x][now.y].d + 1 ;
                        d[nx][ny].life = nt;
                    }
            }
        }
    }
    return -1;
}

int main()
{   
    // memset(d , -1 , sizeof (d));
    cin >> m >> n >> t;
    int i , j;
    for (i=0 ; i<m ; i++)
    {
        for (j=0 ; j<n ; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == '+'){homex = i; homey = j;}
            if (g[i][j] == '!'){stx = i; sty = j;}
        }
    }
    cout << bfs();
    return 0 ;
}