// 未完成 但看后面的思考
#include <iostream>
#include <queue> 
using namespace std;
struct Node
{
	int x , y , res , time;
};  // 剩余生命 花费时间 这样的话就不单独用d了  time == 0 也可以看成是没到过
const int N = 210;
char g[N][N];
Node d[N][N]; // emm 感觉还是自己之前写的清楚
int m , n;
int t;
Node start ;
int dx[4] = {0 , -1 , 0 , 1};
int dy[4] = {1 , 0 , -1 , 0};
int ex , ey; // 终点
void input()
{
	cin >> m >> n >> t;
	int i , j ;
	for (i=0 ; i<m ; i++)
	{
		for (j=0 ; j<n ; j++)
		{
			cin >> g[i][j];
			if (g[i][j] == '!'){start.x = i; start.y = j;}
			if (g[i][j] == '+'){ex = i; ey = j;}
		}
	}
}

int bfs()
{
	Node now , next;
	queue <Node> q;
	start.res = t;
	start.time = 0;  // 自己的初始化一般都是在bfs最开头做的
	q.push(start);
	while (q.empty() == 0)
	{
		now = q.front();
		q.pop();
		if (now.x == ex && now.y == ey){return now.time;}
		int i ;
		for (i=0 ; i<4 ; i++)
		{
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if (next.x>=0 && next.x <m && next.y >=0 && next.y <n ) // 可以放
			{
				if (g[next.x][next.y] == '*'){next.res = now.res;}
				else {next.res = now.res - 1;}
			}
			
		}
	}
}

int main()
{
	input();
	
	cout << bfs()<< endl;
	return 0;
}