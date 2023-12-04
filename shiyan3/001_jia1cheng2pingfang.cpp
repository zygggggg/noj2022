/*
1、普通dfs超时！ 而且这种题目 想dp！！！
2、 最少、最短 想想用bfs
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
1、牛逼！ 如果数据量大 不要用dfs 想想bfs也能做！ 学习分支限界法
为什么这个是bfs  最关键因素 ： 要找最短的路径 最短路径 bfs  那么好像不用min 直接没有使用过的更新
2、vector <int> d(10010,0x3f3f3f); //表示距离 就是走到这一步的次数 vector的初始化
3、if (i==0 && now+1<=n && d[now+1]==0x3f3f3f) 注意剪枝 如果这个点之前走过 那么没必要再走（其实没必要）
因为再走的话这次走的肯定距离更远 而bfs找的就是最短距离
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10010;
int d[N]; // 次数
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