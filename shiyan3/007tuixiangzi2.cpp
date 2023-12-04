#include <iostream> // 还有一个 真正能推箱子的条件没弄 明天弄！
#include <queue> // 这几个题型都一样！！ 一定要弄懂 
#include <cstring>
using namespace std;
int g[10][10]; // 迷宫
int d[10][10][10][10]; //回想前面几个题 都是多维 
//这里 前两个是玩家 后两个是箱子
struct Node 
{
    int px , py;
    int bx , by;
};
Node now ;
queue <Node> q;
int tx , ty; //目标位置
int dx[4] = {0 , 1 , 0 , -1};
int dy[4] = {1 , 0 , -1 , 0};
void input()
{
    int i ,j;
    char c;
    for (i=0 ; i<10 ; i++)
    {
        for (j=0 ; j<10 ; j++)
        {
            cin >> c;
            g[i][j] = c - '0'; // 这样输入 方便又nb！
            if (g[i][j] == 4) { // 找到玩家的初始位置
                now.px = i;
                now.py = j;
                g[i][j] = 0;
            }
            if (g[i][j] == 3) { // 找到目标位置
                tx = i;
                ty = j;
                g[i][j] = 0;
            }
            if (g[i][j] == 2) { // 找到箱子的初始位置
                now.bx = i;
                now.by = j;
                g[i][j] = 0;
            }
        }
    }
}
bool pending (int px , int py , int bx , int by)
{
    if (px < 0 || px >=10 || py <0 || py >=10 ){return 0;}
    else if (d[px][py][bx][by] != -1) {return 0;}
    else if ( g[px][py] == 1){return 0;} 
    //要这以上都不满足！！ 如果只放在一个if里面 那么后面处理麻烦
    return 1; 
}
bool pending_box(int px , int py , int bx , int by)
{
    if (bx < 0 || bx >= 10 || by < 0 || by >= 10) { // 箱子越界
            return 0;
        }
    if (d[px][py][bx][by] != -1) { // 重复状态
        return 0;
    }
    if (g[bx][by] == 1) { // 撞墙
        return 0;
    }
    return 1;
}
int bfs()
{
    Node next;
    d[now.px][now.py][now.bx][now.by] = 0; 
    q.push(now);
    while (q.empty() == 0)
    {
        now = q.front();
        q.pop();
        int i;
        int dis = d[now.px][now.py][now.bx][now.by];
        for (i=0 ; i<4 ; i++)
        {
            next.px = now.px + dx[i];
            next.py = now.py + dy[i];
            next.bx = now.bx;
            next.by = now.by;
            if (pending(next.px , next.py , next.bx , next.by)==0){continue;}// 单独pending会好很多！
            else
            {
                if (next.px != next.bx || next.py != next.by)//没碰到箱子 只人走  
                // 思考：就算人已经在箱子旁边了 人还是四周探索 实际上可以剪枝 但直接无脑这样比较方便
                {
                    d[next.px][next.py][next.bx][next.by] = dis + 1;  //已经访问 更新距离
                    q.push(next);
                }
                else //走箱子
                {
                    next.bx += dx[i];
                    next.by += dy[i];// 人怎么动 箱子就怎么动
                    if (pending_box(next.px , next.py , next.bx , next.by) ==0){continue;} // 这个不用单独pending_box 
                    else
                    {
                        if (next.bx == tx && next.by == ty) { // 推到目标位置
                        return d[now.px][now.py][now.bx][now.by] + 1; // 返回步数
                        }
                        else
                        {
                            d[next.px][next.py][next.bx][next.by] = d[now.px][now.py][now.bx][now.by] + 1; // 更新步数
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
    return -1 ; //否则无法到达

}
int main()
{
    input();
    memset (d, -1 , sizeof (d)); // 判断是否到过就能用d
    cout << bfs() << endl;
    return 0;
}