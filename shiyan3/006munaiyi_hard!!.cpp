#include <iostream>
#include <queue>
 
using namespace std;
 
int n;
 
int maze[6][6][2];  //�洢�Թ���ǽ
 
struct node
{
    int mx,my;  //ľ����λ��
    int px,py;  //��λ��
    bool useful;    //����ڵ��Ƿ���Ч
};                  //��Ч������Խ�硢�ظ�����ץ
 
node start,target;
 
queue <node> q1;
 
int used[6][6][6][6];   //����
 
int walk[4][2]=     //��������һ�����λ������
{
    0, -1,  //��
    +1, 0,  //��
    0, +1,  //��
    -1, 0   //��
};
 
void input();   //���뺯��
 
bool bfs();
 
node moveto(node cur, int i);   //���ؽڵ�cur��չ����һ���ڵ�next
 
bool isWall(int x, int y, int i);   //�жϷ���[x,y]�����Ƿ���ǽ
 
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
    //��һ��
    cin>>n;
 
    //�ڶ���
    int i,j,x;
    for(int k=0; k<n; k++)
    {
        cin>>i>>j>>x;
        maze[i][j][x]=1;    //1������ǽ
    }
 
    //�������
    cin>>start.mx>>start.my;
    cin>>start.px>>start.py;
    cin>>target.px>>target.py;
 
    //��ʼ�ڵ��ǲ����
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
 
        for(int i=0; i<4; i++)  //��Ҫ���ĸ�������̽
        {
            next=moveto(cur, i);    //��ȡ��չ�õ�����һ���ڵ�
            if(next.useful==true)   //���ýڵ���Ч
            {
                if(next.px==target.px&&next.py==target.py)  //������Ŀ���򷵻�true
                {
                    return true;
                }
                else    //δ����Ŀ�������
                {
                    q1.push(next);
                }
            }
        }
    }
    return false;   //������������ܵ���Ŀ�꣬����false
}
 
//�ú������ؽڵ�cur��չ���½ڵ�next
//��Ҫ��i������һ����ľ����Ҫ���˿�������
//�ڵ���Ч��������Խ�硢��ײǽ���˱�ľ����ץ�����ڵ�next�ظ�
node moveto(node cur, int i)
{
    node next;
 
    //����i������һ��
    next.px=cur.px+walk[i][0];  //��ȡ������
    next.py=cur.py+walk[i][1];
 
    if((next.px<0||next.px>=6||next.py<0||next.py>=6)   //����Խ��
       ||
       (isWall(cur.px, cur.py, i)))             //��ײǽ
        {
            next.useful=false;  //�ýڵ���Ч��ֱ�ӷ���
            return next;
        }
 
    //ľ����������
    next.mx=cur.mx;
    next.my=cur.my;
 
    int step=2;
    while(step--)
    {
        //����������ȣ����ȵ���ͬһ��
        if(next.py>next.my&&!isWall(next.mx, next.my, 2))
        {
            next.my++;
        }
        else if(next.py<next.my&&!isWall(next.mx, next.my, 0))
        {
            next.my--;
        }
        //��������ȣ����ٵ���ͬһ��
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
            //��ͬ��ͬ�У����˱�ץס���˽ڵ���Ч��ֱ�ӷ���
            else if(next.px==next.mx)
            {
                //cout<<next.px<<' '<<next.py<<"catch"<<endl;
                next.useful=false;
                return next;
            }
        }
    }
 
    //�˺�ľ������������
    if(used[next.mx][next.my][next.px][next.py])    //���ڵ��ظ�����ڵ���Ч
    {
        //cout<<next.px<<' '<<next.py<<"used"<<endl;
        next.useful=false;
    }
    else
    {
        used[next.mx][next.my][next.px][next.py]=1; //�����Ǹýڵ㵽���
        next.useful=true;                           //��Ǹýڵ���Ч
    }
 
    return next;
}
 
//�жϷ���[x,y]�����Ƿ���ǽ
bool isWall(int x, int y, int i)
{
    switch(i)
    {
        case 0:     //������
            return maze[x][y-1][1]; //�ж���ߵķ�����Ҳ��Ƿ���ǽ
 
        case 1:     //������
            return maze[x][y][0];   //�жϱ�����²��Ƿ���ǽ
 
        case 2:     //������
            return maze[x][y][1];   //�жϱ�����Ҳ��Ƿ���ǽ
 
        case 3:     //������
            return maze[x-1][y][0]; //�ж��ϱߵķ�����²��Ƿ���ǽ
    }
    return -1;  //����-1����iֵ����
}