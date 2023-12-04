#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {1 , 0 , -1 , 0}; // 下 左 上 右
int dy[4] = {0 , -1 , 0 , 1}; // 人可以根据这个任意走
struct Node
{
    int mx , my;
    int px , py;
};
const int N = 6;
char g[N][N][x];
int d[N][N][N][N];  // 4个情况都要记录 那么用4维 
//或者不要int d 而用struct的d
int n;
int tx , ty;
Node start;
void input()
{
     //第一行
    cin>>n;
    //第二行
    int i,j,x;
    for(int k=0; k<n; k++)
    {
        cin>>i>>j>>x;
        g[i][j][x]=1;    //1代表是墙
    }
    cin>>start.mx>>start.my;
    cin>>start.px>>start.py;
    cin>> tx >> ty; 
    //初始节点标记并入队
}
queue <Node> q;
bool pending_person(int px , int py , int mx , int my , int i)
{
    if (px < 0 || px >= 6 || py < 0 || py >=6)
    {
        return 0;
    }
    else if (d[px][py][mx][my] != -1)
    {
        return 0;
    }
    else if (iswall(px , py ,i))
    {
        return 0;
    }
    return 1;
}
bool bfs()
{
    q.push(start);
    Node now , next0;
    while (q.empty() == 0)
    {
        now = q.front();
        q.pop();
        int i ;
        for (i= 0 ; i<4 ; i++)
        {
            next0.px = now.px + dx[i];
            next0.py = now.py + dy[i];
            if(pending_person (next0.px , next0.py , now.mx , now.my , i))
        }
    }
}
int main()
{
    input();
    cout << bfs();
    return 0;
}