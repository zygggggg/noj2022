#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 10;
int g[N][N][N];
int d[N][N][N][N];
struct Node
{
    int px , py;
    int mx , my;
};
Node start , next0 ;
queue <Node> q;
int dx[4] = {1 , 0 , -1 , 0}; // 下 左 上 右
int dy[4] = {0 , -1 , 0 , 1}; // 人可以根据这个任意走
int n; //墙的数量
int tx , ty; //最终目标
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
bool iswall(int x , int y, int i) // 牛逼！ 难想！
{
    switch(i)
    {
        case 1:     //向左走
            return g[x][y-1][1]; //判断左边的方格的右侧是否是墙
 
        case 0:     //向下走
            return g[x][y][0];   //判断本格的下侧是否是墙
 
        case 3:     //向右走
            return g[x][y][1];   //判断本格的右侧是否是墙
 
        case 2:     //向上走
            return g[x-1][y][0]; //判断上边的方格的下侧是否是墙
    }
    return -1;  //返回-1代表i值错误
}
bool pending_person(int px , int py , int mx , int my , int i )
{
    if (px < 0 || px >= 6 || py < 0 || py >=6)
    {
        return 0;
    }
    else if (d[px][py][mx][my] != -1)// 用过
    {
        return 0;
    }
    else if (iswall(px , py , i))
    {
        return 0;
    }
    return 1;
}
bool bfs()
{
    d[start.mx][start.my][start.px][start.px]=0;
    q.push(start);
    while (q.empty() == 0)
    {
        Node now = q.front();
        q.pop();
        int i;
        for (i=0 ; i<4 ; i++)
        {
            next0.px = now.px + dx[i];
            next0.py = now.py + dy[i];
            if (pending_person(next0.px , next0.py , now.mx , now.my , i) == 0)
            {
                continue ;
            }
             else
            {
                if (next0.px== tx &&next0.py == ty){return 1;} // 逃走
                //否则木乃伊走
                next0.mx = now.mx;
                next0.my = now.my;
                int step = 2;
                while (step--)
                {
                    if (next0.py > now.my && iswall){}
                }
                
            }
        }
    }
}

int main()
{
    memset (d , -1 , sizeof (d));// 标记是否走过+第几步
    input();
    if (bfs() == 1)
    {
        cout << "Yes"<< endl;
    }
    else 
    {
        cout << "No" << endl;
    }
    return 0;
}