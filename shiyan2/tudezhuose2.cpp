/*
3 2 2
0 1
1 2
*/
/*
5 8 4
1 2
1 3
1 4
2 3
2 4
2 5
3 4
4 5

���  48 �� 96�� 
*/
/*
1��ע����r���� ������n sb!!
2���Բۣ��� �ư����� Ҫ��dfs1  ע����5��λ   ���ⲻ�����dfs0
*/
#include <iostream>
#include <cstring>
using namespace std;
int n,r,m; //n������ r���� m����ɫ 
const int N=110;
int g[N][N];  //��
int colour [N]; //��i����
int cnt=0;
bool pending (int t,int col)//  ��t���� ������ĵ�ûɫ col����ɫ��
{
    int i;
    for(i=0;i<t;i++)
    {
        if (g[t][i]==1 && col == colour [i]){return 0;}
    }
    return 1;
}

void dfs(int t )
{
    if (t==n ){cnt ++; return ;}
    int i;
    for(i=1;i<=m;i++) //��t���� ��i��ɫ
    {
        if (pending (t,i))
        {
            colour [t]=i; //���ԵĻ� ��ô�ͷ������ɫ ��һ��
            dfs (t+1);
            colour [t]=0;
        }
    }
}

int main()
{
    int i;
    cin>>n>>r>>m;
    int u,v;
    for(i=0;i<r;i++)
    {
        cin >>u >> v;
        g[u][v]=g[v][u]=1;
    }
    dfs (0);
    cout <<cnt <<endl;
    return 0;
}