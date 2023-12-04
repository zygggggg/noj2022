/*
1、 y总没有加if (t.first == ed1 && t.second == ed2){break;}
我觉得加了更好！ 
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=210;
int g[N][N];
int n,st1,st2,ed1,ed2;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int d[N][N];
typedef pair <int , int > PII;
int bfs (int st1, int st2)
{
    queue <PII> q;
    d[st1][st2]=0;
    int i;
    q.push ({st1,st2});
    while (!q.empty())
    {
        PII t = q.front ();
        if (t.first == ed1 && t.second == ed2){break;}
        q.pop();
        for (i=0; i<8 ;i++)
        {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if (nx>=1 && nx <=200 && ny >=1 && ny<=200 && d[nx][ny] == -1)
            {
                d[nx][ny]=d[t.first][t.second]+1;
                q.push ({nx,ny});
            }
        }
    }
    return d[ed1][ed2];
}

int main()
{
    
    cin >>n;
    int i;
    for (i=0;i<n;i++)
    {
        memset (d, -1 , sizeof d);
        cin >> st1 >> st2 >> ed1 >>ed2 ;
        cout << bfs (st1 , st2 ) <<endl;
    }
    return 0;
}
/*
2
1 1 2 1
1 5 5 1

输出样例
3
4
*/
/*
6

1 1 2 1

200 200 199 199

33 33 6 95

51 15 15 51

1 1 100 100

20 99 87 12

预期输出 ——

3
4
31
24
66
52
*/