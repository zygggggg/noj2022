#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
unordered_map <int , char> col;
unordered_map<char, int> direction;
struct Node
{
    int x , y;
    char colour ;
    char dir;
};
struct D
{
	char colour;
	char dir;
	int dis;
};
int dir0[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int N = 110;
D d[N][N];  // 代表了在这个点到过的颜色 方向以及距离  比僵尸来了的life多了一维
char g[N][N] ;
Node start;
int tx , ty ;
char tc ; //终点位置 颜色
void input()
{
	int x , y ;
	char c , d;
	cin >> x >> y >> c >> d;
	start.x = x; start.y = y; start.colour = c; start.dir =d;
	cin >> tx >> ty >> tc;
	int i , j;
	for (i=0 ; i<20 ; i++)
	{
		for (j=0 ; j<20 ; j++)
		{
			cin >> g[i][j];
		}
	}
	col['R'] = 0;
    col['Y'] = 1;
    col['B'] = 2;
    col['W'] = 3;
    col['G'] = 4;

	
    direction['E'] = 0;
    direction['S'] = 1;
    direction['W'] = 2;
    direction['N'] = 3;
}

int bfs()
{
	Node now , next;
	queue <Node> q;
	q.push (start);
	d[start.x][start.y].colour = start.colour ; 
	d[start.x][start.y].dir = start.dir ;
	d[start.x][start.y].dis = 0;
	while (q.empty() == 0)
	{
		now = q.front();
		q.pop();
		if (now.x == tx && now.y == ty && now.colour == tc)
		{
			return d[tx][ty].dis;
		}
		int i;
		for (i=0 ; i<3 ; i++)
		{
			 if(i == 0) // 左转
            {
                next.x = now.x;
                next.y = now.y;
                next.colour = now.colour;
                next.dir = (direction[now.dir] + 1) % 4;
            }
            if(i == 1)
            {
                next.x = now.x;
                next.y = now.y;
                next.colour = now.colour;
                next.dir  = (now.dir + 3) % 4;
            }
            if(i == 2)
            {
                next.x = now.x += dir0[now.dir ][0];
                next.y = now.y += dir0[now.dir ][1];
                next.colour = (now.colour + 1) % 5;
                next.dir  = now.dir ;
            }
		}
	}
}
int main()
{
	input();
	cout << bfs() << endl;
    return 0;
}