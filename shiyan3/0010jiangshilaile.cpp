// ��queue
// ��˼�� ��ѩ������ ��ʵ��Ҫ��������PII ������node ��ônode�Ϳ��Բ�ֹ��ά
// ��ô�Ϳ�����չ�� x y res step �ԣ� stepҲ���Է�������� 
// ����Ҫ��d[N][N] ֻ�ǲ�һ��int d[N][N] ; ���ǿ���Ū��node d[N][N]
// ���ǻ���������Life_d d[N][N] �Ƚ���� ���� ��Ϊd�ò���x��y
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Node 
{
    int x , y , res ; //ʣ��Ѫ��
};
queue <Node> q;
struct Life_d
{
    int life , d;
};
int m , n , t;
const int N = 210;
char g[N][N];
Life_d d[N][N]; // ���� ��ʵ���������node������չ Ȼ��ֱ�� node d[N][N] ���о����������Ƚ����
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
        if (now.x == homex && now.y == homey){return d[now.x][now.y].d;} // ����
        for (i=0 ; i<4 ; i++)
        {
            int nx = now.x +dx[i];
            int ny = now.y +dy[i];
            if (nx >=0 && nx <m && ny >=0 && ny <n)
            {
                if (g[nx][ny] == 'w')
                {
                    nt = now.res - 1;
                    if(nt == 0){continue;} // ���� ��ô����ڵ㲻�ܼ���
                }
                else
                {
                    nt = now.res;
                }
                if (d[nx][ny].d == 0 || (d[nx][ny].d != 0 && d[nx][ny].life < nt) )
                    // û���� ���ߵ��� ���������������ֵ�Ƚ�С ��ô����������Ľڵ�
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