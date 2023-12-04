/*
7 8 2
8 7
7 9 2
8 8
0 0 0
*/
/*
1、别忘循环后 max0=0
*/
#include <iostream>

using namespace std;
const int N=10010;
int w[N];//重量
int p[N];//价值
// int used[N];
int n;
int c1,c2;
int max0=0;
void dfs(int t,int weight)
{
    if(t>=n){if(weight>max0)max0=weight;return ;}
    // used[t]=0;
    dfs(t+1,weight);
    if(weight+w[t]<=c1)
    {
        dfs(t+1,weight+w[t]);
    }
}

int main()
{
    int i;
    int sum_box=0;
    while(cin>>c1>>c2>>n &&n!=0)
    {
        for(i=0;i<n;i++){cin>>w[i];sum_box+=w[i];}
        dfs(0,0);
        if(sum_box-max0<=c2){cout<<"Yes"<<endl;}
        else{cout<<"No"<<endl;}
        max0=0;
        sum_box=0;
    }
    return 0;
}