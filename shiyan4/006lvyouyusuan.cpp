// #include<iostream>

// using namespace std;
// const int N = 110;
// typedef pair <int , int> PII;
// int dis = 0;
// int full , pd , cost , num; //pd 每升汽油可以行驶的距离
// bool path[N]; //记录加油站点
// int res = 0x3f3f3f3f;
// double half_drive ;
// int res0[N] ; //在这个点还能跑多远
// PII charge[N] ;
// void output()
// {
// 	int i ;
// 	for (i=1; i<=num ; i++)
// 	{
// 		if (path[i] == 1){cout << i << ' ';}
// 	}
// }

// void dfs(int t)
// {
// 	if (t == num+1)
// 	{
// 		if (cost < res) {res = cost ;}
// 		return ;
// 	}
// 	//剪枝
// 	if (res0[t-1]-(charge[t].first - charge[t-1].first)*pd < half_drive || ((res0[t-1]-(charge[t].first - charge[t-1].first)*pd >= half_drive)&& (res0[t-1] <= (charge[t+1].first - charge[t-1].first )*pd)))
// 	{
// 		//一定需要停车
// 		res0[t] = half_drive * 2;
// 		cost = cost + 2 + (res0[t] - res0[t-1]) * charge[t].second ;
// 		dfs (t + 1);

// 	}
	
// 	// 不需要停车
// 	res0[t] = res0[t-1]-(charge[t].first - charge[t-1].first);
// 	dfs (t+1) ;

// }

// int main()
// {
// 	cin >> dis;
// 	cin >> full >> pd >> cost >> num ;
// 	res0[0] = full * pd;
// 	half_drive = res0[0] / 2;
	
// 	int i ;
// 	for (i=1 ; i<=num ; i++){cin >> charge[i].first >> charge[i].second;}  //距离起点的距离   每升汽油的价格
// 	dfs(1);
// 	cout << res;
	
// 	return 0;
// }
#include <iostream>
#include <stdio.h>
#include <float.h>
 
using namespace std;
 
/********输入数据部分*******/
double length;
double capa,mile,cost;
int n;
 
double dis[51];
double price[50];
/****************************/
 
/****算法中用到的其他变量***/
bool isAdd[50];     //在第i个加油站是否加油
 
double min_cost[50];    //备忘录  这个点到终点要花费的最少钱

int cnt;
 
double maxdis;      //加满油后能走的最大距离
/****************************/
 
/**********函数声明*********/
double dp(int i);   //返回“从第i个加油站满油出发，到达终点的最小费用”
 
void input();   //输入数据
void init();    //变量初始化
void output(double mincost);   //输出数据
/****************************/
 
int main()
{
    input();    //输入数据
 
    init();     //变量初始化
 
    double mincost=dp(0);  //计算得到最小费用
 
    output(mincost);    //输出数据
 
    return 0;
}
 
void input()    //输入数据
{
    //第一行
    cin>>length;
 
    //第二行
    cin>>capa>>mile>>cost>>n;
 
    //接下去的n行
    for(int i=1; i<=n; i++)   //加油站从1开始编号
    {
        cin>>dis[i]>>price[i];  //输入距离和油价
    }
 
    dis[0]=0;           //假设起点为第0个加油站（实际上没有）
    dis[n+1]=length;    //假设终点为第n+1个加油站（实际上没有）
}
 
void init()     //变量初始化
{
    for(int i=1; i<=n+1; i++)
    {
        isAdd[i]=false; //每个加油站初始化为不加油
        min_cost[i]=DBL_MAX;    //从加油站i到终点的费用设为最大值
    }
    min_cost[0]=DBL_MAX;    //从起点到终点的费用设为最大值
 
    cnt=0;  //需要加油的加油站个数
 
    maxdis=capa*mile;   //加满油后能到达的最大距离
}
 
double dp(int i)    //满油状态从加油站i到终点的最小花费
{
    if(i==n+1)      //到达终点
    {
        return cost;    //算上“在起点加满油的费用”
    }
 
    else if(min_cost[i]!=DBL_MAX)   //备忘录中有记录
    {
        return min_cost[i]; //直接返回
    }
 
    else    //若备忘录中无记录，则需要计算填写
    {
        double fuel_j;      //从加油站i到达加油站j耗费的油量
        double fuel_remain; //从加油站i到达加油站j后，剩下的油量
        double cost_j;      //从加油站i到达加油站j，并在加油站j加满油的费用
        double cost_j_n;    //从加油站i，经过加油站j加油并到达终点的总费用
 
        int min_j=-1;   //记录需要加油的加油站下标
 
        for(int j=i+1; j<=n+1&&(dis[j]-dis[i])<=maxdis; j++)   //遍历从加油站i出发，能够到达的加油站j
        {
            fuel_j=(dis[j]-dis[i])/mile;    //计算从加油站i到达加油站j耗费的油量
 
            fuel_remain=capa-fuel_j;    //计算到达加油站j后剩下的油量
            if(fuel_remain>capa/2       //如果剩下的油超过一半
               &&fuel_remain*mile>=(dis[j+1]-dis[j]))   //而且剩下的油能够到达第j+1个加油站
            {
                continue;   //那么规则不允许加油
            }
 
            if(j==n+1)      //如果能直接到达终点
            {
                cost_j=0;   //到达终点不用加油，也不用算油费了
            }
            else            //否贼就要在加油站j加满油
            {
                cost_j=2;   //给司机买糖吃
                cost_j+=fuel_j*price[j];    //加满油的费用=耗费的油*油价
            }
 
            cost_j_n=cost_j+dp(j);  //从i到达终点的费用=从i到达j的费用+从j到达终点的费用
 
            if(min_cost[i]>cost_j_n)    //遍历j时，取最小的“从i到达终点的费用”
            {
                min_cost[i]=cost_j_n;   //记录从i到终点的最小费用
                min_j=j;    //记录从i到终点的途中曾在加油站j加过油
            }
        }
 
        if(min_j!=-1)   //如果min_j不等于初始值，证明途中加过油
        {
            isAdd[min_j]=true;  //记录从i到终点的途中曾在第min_j个收费站加过油
        }
 
        return min_cost[i]; //返回从i到终点的最小费用
    }
}

void output(double mincost)
{
    //输出第一行
    printf("%.2f ",mincost);
 
    //计算并输出加油次数
    for(int i=1; i<=n; i++)
    {
        if(isAdd[i])
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
 
    //输出第二行
    for(int i=1; i<=n; i++)
    {
        if(isAdd[i])
        {
            cout<<i<<' ';
        }
    }
    cout<<endl;
}
