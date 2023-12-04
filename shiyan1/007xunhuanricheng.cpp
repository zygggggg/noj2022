#include <iostream>
#include <cmath>
using namespace std;
const int N=138;
int a[N][N];
int n;
void dfs(int t)
{
    if(t==n){return ;}
    int m=pow(2.0,t);
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            a[i+m][j+m]=a[i][j];//¸´ÖÆ
            a[i+m][j]=a[i][j]+m;
            a[i][j+m]=a[i][j]+m;
        }
    }
    dfs(t+1);
}
int main()
{
    cin>>n;
    a[1][1]=a[2][2]=1;
    a[1][2]=a[2][1]=2;
    dfs(1);
    int m=pow(2.0,n);
    int i,j;
    for(i=1;i<=m;i++)
    {
        for (j=1;j<=m;j++)
        {
            cout<<a[i][j];
            if(j!=m){cout<<' ';}
        }
        cout<<endl;
    }
    return 0;
}