#include <iostream>
#include <cmath>
using namespace std;
const int N=10;
int g[N];//在第i行用了数g[i]
int used[N];//用过的数
int n;
int cnt=0;
bool pending(int row,int col)//(row,col) (i,g[i])
{
    int i;
    for(i=0;i<row;i++)
    {
        if(abs(row-i)==abs(col-g[i]))return 0;
    }
    return 1;
}
void dfs(int t)
{
    int i;
    if(t>=n){cnt++;return ;}
    for(i=0;i<n;i++)
    {
        if(used[i]==0&&pending(t,i))
        {
            used[i]=1;
            g[t]=i;
            dfs(t+1);
            used[i]=0;
            g[t]=0;
        }
    }
}


int main()
{
    cin>>n;
    dfs(0);
    cout<<cnt;
    return 0;
}