// δ��� ���������˼��
#include <iostream>
#include <queue> 
using namespace std;
struct Node
{
	int x , y , res , time;
};  // ʣ������ ����ʱ�� �����Ļ��Ͳ�������d��  time == 0 Ҳ���Կ�����û����
const int N = 210;
char g[N][N];
Node d[N][N]; // emm �о������Լ�֮ǰд�����
int m , n;
int t;
Node start ;
int dx[4] = {0 , -1 , 0 , 1};
int dy[4] = {1 , 0 , -1 , 0};
int ex , ey; // �յ�
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
	start.time = 0;  // �Լ��ĳ�ʼ��һ�㶼����bfs�ͷ����
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
			if (next.x>=0 && next.x <m && next.y >=0 && next.y <n ) // ���Է�
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