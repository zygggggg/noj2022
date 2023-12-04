/*
1、经常写解释很好！！ 
2、a[row][col]='#';//一定一定要注意标记！
3、dfs(t+1,num+1);//这种图 别直接row col 而是用t  后面再转成row col会好很多
4、a[row][col]='.';//一定要注意跟那个对称 返回！ 放到if里面返回最好
5、cout<<max0<<endl;//别急着编译 一定要检查！！
6、max0=0;// 这种实验题一定要重置 别忘了
*/
#include <iostream>

using namespace std;
const int N=10;
char a[N][N];
int n;
int max0;//放堡垒
bool pending (int row, int col)
{
    int i=row-1,j=col-1;
    while(i>=0 && a[i][col]=='.'){i--;}
    if(i>=0 && a[i][col]=='#'){return 0;} 
    while(j>=0 && a[row][j]=='.'){j--;}
    if(j>=0 && a[row][j]=='#'){return 0;}
    return 1; //否则要么出界要么碰到X 这些都是可以放的
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
            a[row][col]='#';//一定一定要注意标记！
            dfs(t+1,num+1);//这种图 别直接row col 而是用t  后面再转成row col会好很多
            a[row][col]='.';//一定要注意跟那个对称 返回！ 放到if里面返回最好
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
        cout<<max0<<endl;//别急着编译 一定要检查！！
        max0=0;// 这种实验题一定要重置 别忘了
    }
    
    return 0;
}
/*
输入样例
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

输出样例
5
1
5
2
4
*/