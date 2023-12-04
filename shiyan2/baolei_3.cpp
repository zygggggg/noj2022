/*
1��if(pending())
a[row][col]='#';
dfs(t+1,num+1);

a[row][col]='.';
dfs(t+1,num);
��һ���Ǳ���Ҫ�е�  (�ǵڶ���״̬ ���ݣ� ) 
�����˵ڶ���ѡ���ʱ��ҲҪdfsһ�Σ���  ���ж����Բ��� dfs(t+1, sum)
2��if(a[row][col]=='X'){dfs(t+1,num);return;} �����������return�� ţ�ƣ�
3������ͼ�����ⶼҪ���߹���¼ ���ﲻ��
*/

#include <iostream>

using namespace std;
const int N=5;
char a[N][N];
int n;
int max0=0;
bool pending(int row,int col)
{
    int i=row-1,j=col-1;
    while(i>=0&&a[i][col]=='.'){i--;}
    if(i>=0 && a[i][col]=='#'){return 0;}
    while(j>=0 && a[row][j]=='.'){j--;}
    if(j>=0 && a[row][j]=='#'){return 0;}
    return 1;
}

void dfs(int t,int num)
{
    if(t == n*n){if(max0<num)max0=num;return ;}
    int row=t/n;
    int col=t%n;
    if(a[row][col]=='X'){dfs(t+1,num);return;}
    if(pending(row,col))
    {
        a[row][col]='#';
        dfs(t+1,num+1) ;
        a[row][col]='.';
    }
        dfs(t+1,num); //���ж����Բ��� 
}


int main()
{
    int i,j;
    while(1)
    {
        cin>>n;
        if(n<=0)break;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    dfs(0,0);
    cout<<max0<<endl;
    max0=0;
    }
    
    return 0;
}
/*
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