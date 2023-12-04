/*
字符转换 回溯 思路：弄一个长度为2n的数组 牛逼！！
*/
/*
TROT 到 TORT:
[
i i i i o o o o
i o i i o o i o
]
*/
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
const int N=110;
using namespace std;
stack <char> s;  //记录字母
vector <char> v(N); //记录 i和o
vector <char> pend(N);
int n,n2;
string org,tag;
int in_num,out_num;
bool pending ()
{
    int i;
    int cnt=0;
    int j=0;
    for (i=0;i<2*n; i++)
    {
        if (v[i]=='i'){s.push(org[j++]);}
        else 
        {
            pend[cnt++]=s.top();
            s.pop();
        }
    }
    for (i=0;i<n;i++)
    {
        if (pend[i]!= tag[i]){return 0;}
    }
    return 1;
}

void output()
{
    int i;
    for (i=0;i<2*n-1 ;i++ )
    {
        cout <<v[i]<<' ';
    }
    cout <<v[i] << endl;
}

void dfs (int t)
{
    if (t==2*n)
    {
        if (pending ())
        {
            output(); 
        }
        return ;
    }
    if (in_num <n)
    {
        in_num ++;
        v[t]='i';
        dfs (t+1);
        in_num --;
        v[t]=' ';
    }
    if (out_num<in_num )
    {
        out_num ++;
        v[t]='o';
        dfs (t+1);
        out_num --;
        v[t]=' ';
    }
    

}

int main()
{
    
    while(cin >> org >> tag)
    {
        
        n=org.length();
        n2=tag.length();
        
        cout <<'['<<endl ;
        if (n==n2){dfs(0);}
        cout <<']'<<endl ;
       
        in_num =0;
        out_num=0;
    }
    return 0;
}