/*
1��ͼ������ ������ ������ǣ�
2��ͼ����������߽磡
3��ע��߽紦���� �Լ�����
int nx = x + change[i][0];
        int ny = y + change[i][1];
        if(nx>=0 && nx<m && ny>=0 && ny<n
            ��������֮�����жϣ�
            �ȼ� ���ж� ������ 
4��ע����������� �ж��ܳ�ʱֱ���ж����ܾͺã�
5��ע��dfs(x-1,y-1);
6��ͼ������ ����
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
7�� ������Ҫ���ǵľ���ʲôʱ�����
֮ǰ����if(t>n)
��β��ã� ���ֱ�ӵ���ȫ�������Լ��˳�
�����Թ����˳�
8����dfs�����У��жϱ߽�ʱʹ����farm[x+change[i][0]][y+change[i][1]]��
��û�����ж�x+change[i][0]��y+change[i][1]�Ƿ�Խ�磬���ܻᵼ������Խ����ʴ��󡣴�����Ҫ�жϣ�
9��ע��ȫ����Ҫ���س�ʼֵ�� ��Ҫ���£� �Լ�������flag
for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        result+=res[i][j];
        farm[i][j]=0;
        str[i][j]=0;
        res[i][j]=0;
        flag[i][j]=false;����
    }
    cout<<result<<endl;
10 ����������Ĵ��� res[x][y]=4;Ҫ����dfs����  ��Ϊ������Լ�res �п��ܰѲ���ͨ��ʲôȫ�ӽ�ȥ��
*/

#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int m,n,x,y;
char a[N][N];
int res[N][N];
bool flag[N][N];
int d_row[8]={0,-1,0,1,1,-1,-1,1};
int d_col[8]={-1,0,1,0,-1,-1,1,1};
void dfs(int x,int y)
{
    if(a[x][y]=='.'){return ;}
    res[x][y]=4;
    int i;
    flag[x][y]=1;
    for(i=0;i<=3;i++)
    {
        int dx=x+d_row[i],dy=y+d_col[i];
    if(dx>=1&&dx<=m&&dy>=1&&dy<=n&&a[dx][dy]=='X'){res[x][y]--;}
    }
    for(i=0;i<8;i++)
    {
        int dx=x+d_row[i],dy=y+d_col[i];
        if(dx>=1&&dx<=m&&dy>=1&&dy<=n&&a[dx][dy]=='X'&&flag[dx][dy]==0){dfs(dx,dy);}
    }
    
}
int main()
{
    while(cin>>m>>n>>x>>y)
    {
        if(m==0){break;}
        int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];       
        }
    }
    dfs(x,y);
    int cnt=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cnt+=res[i][j];
        }
    }
    cout<<cnt<<endl;
    cnt=0;
    memset(res,0,sizeof(res));
    memset(a,0,sizeof(a));
    memset(flag,0,sizeof(a));
    }
    return 0;
}