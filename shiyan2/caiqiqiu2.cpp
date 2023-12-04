
/*
1、 sb 一个mult1 mult2 找了一个小时！！ 
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int mult1=1,mult2=1;
bool real2=0;
bool real=0;
void dfs(int a,int b,int t)
{
    if (t==101)
    {
        if (mult1 == a && mult2 == b){real = real2 = true;}
        else if (mult2 == b){real2 = true;}
    return ;
    }
    if(a%t==0 && mult1 *t <=a )
    {
        mult1 *= t;
        dfs(a,b,t+1);
        mult1 /= t;
    }
    if(b%t==0 && mult2 *t <=b )
    {
        mult2 *= t;
        dfs(a,b,t+1);
        mult2 /= t;
    }
    dfs(a,b,t+1);
}


int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if (a==0&&b==0 ){break;}
        if(a<b){swap(a,b);}
        mult1=1,mult2=1;
         real=0,real2=0;
        dfs(a,b,2);
         if (real && real2)
            cout << a << endl;
        else if (real2)
            cout << b << endl;
        else
            cout << a << endl;
    }
	 
    return 0;
}
/*
36 62 49 343 0 0
*/