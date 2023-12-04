/*
1����ͨdfs��ʱ�� ����������Ŀ ��dp������
2�� ���١���� ������bfs
*/
/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=10010;
int dp [N];
int m,n;
int main()
{
    memset (dp , 0x3f3f3f , sizeof dp);
    
    cin >> m >> n;
    dp[m]=0;
    int i;
    for (i=m;i<=n;i++)
    {
        if (dp[i]==0x3f3f3f ){continue ;}
        if (i+1 <=n)
        {
            dp [i+1]=min (dp[i+1], dp[i]+1);
        }
        if (i*2 <=n)
        {
            dp [i*2]= min (dp [i*2], dp[i]+1);
        }
        if (i*i<=n) 
        {
            dp [i*i] = min (dp [i*i], dp[i]+1);
        }
    }
    cout << dp[n];
    return 0;
}*/

/*
1��ţ�ƣ� ����������� ��Ҫ��dfs ����bfsҲ������ ѧϰ��֧�޽編
Ϊʲô�����bfs  ��ؼ����� �� Ҫ����̵�·�� ���·�� bfs  ��ô������min ֱ��û��ʹ�ù��ĸ���
2��vector <int> d(10010,0x3f3f3f); //��ʾ���� �����ߵ���һ���Ĵ��� vector�ĳ�ʼ��
3��if (i==0 && now+1<=n && d[now+1]==0x3f3f3f) ע���֦ ��������֮ǰ�߹� ��ôû��Ҫ���ߣ���ʵû��Ҫ��
��Ϊ���ߵĻ�����ߵĿ϶������Զ ��bfs�ҵľ�����̾���
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10010;
int d[N]; // ����
int n , m;
queue <int> q;
int bfs ()
{
    d[n] = 0;
    q.push(n);
    while (q.empty() == 0)
    {
        int t = q.front();
        if (t == m){return d[m];}
        q.pop();    
        int i ;
        for (i= 0 ; i<3 ; i++)
        {
            if (i == 0 && t + 1 <= m)
            {
                d[t+1] = min(d[t+1] , d[t] + 1);
                q.push(t+1);
            }
            if (i == 1 && t*2 <= m)
            {
                d[t*2] = min(d[t*2] , d[t] + 1);
                q.push(t*2);
            }
            if (i == 2 && t*t <=m)
            {
                d[t*t] = min(d[t*t] , d[t] + 1);
                q.push(t*t);
            }
        }
    } 
return -1;  
}

int main()
{
    memset (d, 0x3f3f3f3f , sizeof (d));
    cin >> n >> m;
    cout << bfs();
    return 0;
}