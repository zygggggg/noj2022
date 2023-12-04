/*
1 2
1
1
2 3
2 2
3 4
0 0

 
输出样例
1
4
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
int c;
int max0=0;
void dfs(int t,int sum_p,int weight,int boat_left_weight,int box_left_weight)
{
    if(t>=n){if(sum_p>max0)max0=sum_p;return ;}
    // used[t]=0;
    if(boat_left_weight<box_left_weight)
    {
        dfs(t+1,sum_p,weight,boat_left_weight,box_left_weight-w[t]);
    }
    
    if(weight+w[t]<=c)
    {
        dfs(t+1,sum_p+p[t],weight+w[t],boat_left_weight-w[t],box_left_weight-w[t]);
    }
}

int main()
{
    int i;
    int box_left_weight=0;
    while(cin>>n>>c)
    {
        for(i=0;i<n;i++){cin>>w[i]>>p[i];box_left_weight+=w[i];}
        dfs(0,0,0,c,box_left_weight);
        cout<<max0;
        max0=0;
    }
    return 0;
}