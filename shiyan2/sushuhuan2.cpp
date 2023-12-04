/*
1、找到一个就输出 用bool 和return 牛逼！
2、 学会 一找到就直接润 就是 if (dfs ..)  return 
if (dfs(t+1)) return true ;  而不可 return dfs(t+1)
3、if(t==20 && isprime(a[0]+a[19])){output();return 1;}
    if(t==20 && isprime(a[0]+a[19]==0)){return 0;} 牛逼！
4、字符串问题是直接放 这题是先剪枝、先判断再放    直接放再判断的好处是思维简单代码简单
字符串先剪枝太烦了！！！ 
5、 if (dfs(t+1)) return true ; 如果有1的话 这句话就疯狂return 就直接结束 好像是这样
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 10010;
int a[N] ;
bool used[N]; //这个数被用过？ 
void output()
{
    int i;
    for (i=0 ; i<=19 ; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
bool pending(int n)
{
    int m = sqrt (n);
    int i ;
    for (i=2 ; i<= m ; i++){if (n % i == 0)return 0;}
    return 1;
}
bool dfs(int t)
{
    int i ;
    if (t == 20)
    {
        if (pending(a[0] + a[19])){output() ; return 1;}
        else {return 0;}
    }
    else
    {
        for (i=1 ; i<=20 ; i++)
        {
            if (used[i] == 0 && pending (a[t-1] + i))
            {
                a[t] = i;
                used[i] = 1;
                if (dfs(t+1)) return 1;
                a[t] = 0;
                used[i] = 0;
            }
        }
    }
    return 0;
}
int main()
{
    int i;
    a[0] = 1;
    used[1] = 1;
    dfs(1);
    return 0;
}
