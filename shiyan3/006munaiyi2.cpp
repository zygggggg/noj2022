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
int dx[4] = {1 , 0 , -1 , 0}; // �� �� �� ��
int dy[4] = {0 , -1 , 0 , 1}; // �˿��Ը������������
int n; //ǽ������
int tx , ty; //����Ŀ��
void input()
{
    //��һ��
    cin>>n;
 
    //�ڶ���
    int i,j,x;
    for(int k=0; k<n; k++)
    {
        cin>>i>>j>>x;
        g[i][j][x]=1;    //1������ǽ
    }
    cin>>start.mx>>start.my;
    cin>>start.px>>start.py;
    cin>> tx >> ty; 
    //��ʼ�ڵ��ǲ����
}
bool iswall(int x , int y, int i) // ţ�ƣ� ���룡
{
    switch(i)
    {
        case 1:     //������
            return g[x][y-1][1]; //�ж���ߵķ�����Ҳ��Ƿ���ǽ
 
        case 0:     //������
            return g[x][y][0];   //�жϱ�����²��Ƿ���ǽ
 
        case 3:     //������
            return g[x][y][1];   //�жϱ�����Ҳ��Ƿ���ǽ
 
        case 2:     //������
            return g[x-1][y][0]; //�ж��ϱߵķ�����²��Ƿ���ǽ
    }
    return -1;  //����-1����iֵ����
}
bool pending_person(int px , int py , int mx , int my , int i )
{
    if (px < 0 || px >= 6 || py < 0 || py >=6)
    {
        return 0;
    }
    else if (d[px][py][mx][my] != -1)// �ù�
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
                if (next0.px== tx &&next0.py == ty){return 1;} // ����
                //����ľ������
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
    memset (d , -1 , sizeof (d));// ����Ƿ��߹�+�ڼ���
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