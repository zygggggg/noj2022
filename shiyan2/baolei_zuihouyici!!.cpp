/*
1������д���ͺܺã��� 
2��a[row][col]='#';//һ��һ��Ҫע���ǣ�
3��dfs(t+1,num+1);//����ͼ ��ֱ��row col ������t  ������ת��row col��úܶ�
4��a[row][col]='.';//һ��Ҫע����Ǹ��Գ� ���أ� �ŵ�if���淵�����
5��cout<<max0<<endl;//���ű��� һ��Ҫ��飡��
6��max0=0;// ����ʵ����һ��Ҫ���� ������
*/
#include <iostream>

using namespace std;
const int N=10;
char a[N][N];
int n;
int max0;//�ű���
bool pending (int row, int col)
{
    int i=row-1,j=col-1;
    while(i>=0 && a[i][col]=='.'){i--;}
    if(i>=0 && a[i][col]=='#'){return 0;} 
    while(j>=0 && a[row][j]=='.'){j--;}
    if(j>=0 && a[row][j]=='#'){return 0;}
    return 1; //����Ҫô����Ҫô����X ��Щ���ǿ��Էŵ�
}
void dfs(int t,int num)
{
    if(t==n*n){if(num>max0)max0=num;return ;}
    int row =t/n;
    int col=t%n;
    if(a[row][col]=='X'){dfs(t+1,num);}
    else
    {
        if(pending(row,col))
        {
            a[row][col]='#';//һ��һ��Ҫע���ǣ�
            dfs(t+1,num+1);//����ͼ ��ֱ��row col ������t  ������ת��row col��úܶ�
            a[row][col]='.';//һ��Ҫע����Ǹ��Գ� ���أ� �ŵ�if���淵�����
        }    
        dfs(t+1,num);
    }
}

int main()
{
    
    int i,j;
    while(cin>>n)
    {
        if(n==0)break;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        dfs(0,0);
        cout<<max0<<endl;//���ű��� һ��Ҫ��飡��
        max0=0;// ����ʵ����һ��Ҫ���� ������
    }
    
    return 0;
}
/*
��������
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0

�������
5
1
5
2
4
*/