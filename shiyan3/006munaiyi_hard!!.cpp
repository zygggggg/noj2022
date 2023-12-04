#include <iostream>
#include <queue>
 
using namespace std;
 
int n;
 
int maze[6][6][2];  //存储迷宫的墙
 
struct node
{
    int mx,my;  //木乃伊位置
    int px,py;  //人位置
    bool useful;    //这个节点是否有效
};                  //无效条件：越界、重复、被抓
 
node start,target;
 
queue <node> q1;
 
int used[6][6][6][6];   //判重
 
int walk[4][2]=     //返回人走一格的新位置坐标
{
    0, -1,  //左
    +1, 0,  //下
    0, +1,  //右
    -1, 0   //上
};
 
void input();   //输入函数
 
bool bfs();
 
node moveto(node cur, int i);   //返回节点cur扩展的下一个节点next
 
bool isWall(int x, int y, int i);   //判断方格[x,y]方向是否是墙
 
int main()
{
    input();
 
    if(bfs())
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
 
void input()
{
    //第一行
    cin>>n;
 
    //第二行
    int i,j,x;
    for(int k=0; k<n; k++)
    {
        cin>>i>>j>>x;
        maze[i][j][x]=1;    //1代表是墙
    }
 
    //最后三行
    cin>>start.mx>>start.my;
    cin>>start.px>>start.py;
    cin>>target.px>>target.py;
 
    //初始节点标记并入队
    used[start.mx][start.my][start.px][start.px]=1;
    q1.push(start);
}

bool bfs()
{
    node cur,next;
    while(!q1.empty())
    {
        cur=q1.front();
        q1.pop();
 
        for(int i=0; i<4; i++)  //人要向四个方向试探
        {
            next=moveto(cur, i);    //获取扩展得到的下一个节点
            if(next.useful==true)   //若该节点有效
            {
                if(next.px==target.px&&next.py==target.py)  //若到达目标则返回true
                {
                    return true;
                }
                else    //未到达目标则入队
                {
                    q1.push(next);
                }
            }
        }
    }
    return false;   //所有情况都不能到达目标，返回false
}
 
//该函数返回节点cur扩展的新节点next
//人要向i方向走一步，木乃伊要向人靠近两步
//节点无效条件：人越界、人撞墙、人被木乃伊抓到、节点next重复
node moveto(node cur, int i)
{
    node next;
 
    //人向i方向走一步
    next.px=cur.px+walk[i][0];  //获取新坐标
    next.py=cur.py+walk[i][1];
 
    if((next.px<0||next.px>=6||next.py<0||next.py>=6)   //若人越界
       ||
       (isWall(cur.px, cur.py, i)))             //若撞墙
        {
            next.useful=false;  //该节点无效，直接返回
            return next;
        }
 
    //木乃伊走两步
    next.mx=cur.mx;
    next.my=cur.my;
 
    int step=2;
    while(step--)
    {
        //若列数不相等，则先到达同一列
        if(next.py>next.my&&!isWall(next.mx, next.my, 2))
        {
            next.my++;
        }
        else if(next.py<next.my&&!isWall(next.mx, next.my, 0))
        {
            next.my--;
        }
        //若列数相等，则再到达同一行
        else if(next.py==next.my)
        {
            if(next.px>next.mx&&!isWall(next.mx, next.my, 1))
            {
                next.mx++;
            }
            else if(next.px<next.mx&&!isWall(next.mx, next.my, 3))
            {
                next.mx--;
            }
            //若同行同列，则人被抓住，此节点无效，直接返回
            else if(next.px==next.mx)
            {
                //cout<<next.px<<' '<<next.py<<"catch"<<endl;
                next.useful=false;
                return next;
            }
        }
    }
 
    //人和木乃伊都走完了
    if(used[next.mx][next.my][next.px][next.py])    //若节点重复，则节点无效
    {
        //cout<<next.px<<' '<<next.py<<"used"<<endl;
        next.useful=false;
    }
    else
    {
        used[next.mx][next.my][next.px][next.py]=1; //否则标记该节点到达过
        next.useful=true;                           //标记该节点有效
    }
 
    return next;
}
 
//判断方格[x,y]方向是否是墙
bool isWall(int x, int y, int i)
{
    switch(i)
    {
        case 0:     //向左走
            return maze[x][y-1][1]; //判断左边的方格的右侧是否是墙
 
        case 1:     //向下走
            return maze[x][y][0];   //判断本格的下侧是否是墙
 
        case 2:     //向右走
            return maze[x][y][1];   //判断本格的右侧是否是墙
 
        case 3:     //向上走
            return maze[x-1][y][0]; //判断上边的方格的下侧是否是墙
    }
    return -1;  //返回-1代表i值错误
}