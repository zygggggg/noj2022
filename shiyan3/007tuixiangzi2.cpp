#include <iostream> // ����һ�� �����������ӵ�����ûŪ ����Ū��
#include <queue> // �⼸�����Ͷ�һ������ һ��ҪŪ�� 
#include <cstring>
using namespace std;
int g[10][10]; // �Թ�
int d[10][10][10][10]; //����ǰ�漸���� ���Ƕ�ά 
//���� ǰ��������� ������������
struct Node 
{
    int px , py;
    int bx , by;
};
Node now ;
queue <Node> q;
int tx , ty; //Ŀ��λ��
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
            g[i][j] = c - '0'; // �������� ������nb��
            if (g[i][j] == 4) { // �ҵ���ҵĳ�ʼλ��
                now.px = i;
                now.py = j;
                g[i][j] = 0;
            }
            if (g[i][j] == 3) { // �ҵ�Ŀ��λ��
                tx = i;
                ty = j;
                g[i][j] = 0;
            }
            if (g[i][j] == 2) { // �ҵ����ӵĳ�ʼλ��
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
    //Ҫ�����϶������㣡�� ���ֻ����һ��if���� ��ô���洦���鷳
    return 1; 
}
bool pending_box(int px , int py , int bx , int by)
{
    if (bx < 0 || bx >= 10 || by < 0 || by >= 10) { // ����Խ��
            return 0;
        }
    if (d[px][py][bx][by] != -1) { // �ظ�״̬
        return 0;
    }
    if (g[bx][by] == 1) { // ײǽ
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
            if (pending(next.px , next.py , next.bx , next.by)==0){continue;}// ����pending��úܶ࣡
            else
            {
                if (next.px != next.bx || next.py != next.by)//û�������� ֻ����  
                // ˼�����������Ѿ��������Ա��� �˻�������̽�� ʵ���Ͽ��Լ�֦ ��ֱ�����������ȽϷ���
                {
                    d[next.px][next.py][next.bx][next.by] = dis + 1;  //�Ѿ����� ���¾���
                    q.push(next);
                }
                else //������
                {
                    next.bx += dx[i];
                    next.by += dy[i];// ����ô�� ���Ӿ���ô��
                    if (pending_box(next.px , next.py , next.bx , next.by) ==0){continue;} // ������õ���pending_box 
                    else
                    {
                        if (next.bx == tx && next.by == ty) { // �Ƶ�Ŀ��λ��
                        return d[now.px][now.py][now.bx][now.by] + 1; // ���ز���
                        }
                        else
                        {
                            d[next.px][next.py][next.bx][next.by] = d[now.px][now.py][now.bx][now.by] + 1; // ���²���
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
    return -1 ; //�����޷�����

}
int main()
{
    input();
    memset (d, -1 , sizeof (d)); // �ж��Ƿ񵽹�������d
    cout << bfs() << endl;
    return 0;
}