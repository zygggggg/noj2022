// #include<iostream>

// using namespace std;
// const int N = 110;
// typedef pair <int , int> PII;
// int dis = 0;
// int full , pd , cost , num; //pd ÿ�����Ϳ�����ʻ�ľ���
// bool path[N]; //��¼����վ��
// int res = 0x3f3f3f3f;
// double half_drive ;
// int res0[N] ; //������㻹���ܶ�Զ
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
// 	//��֦
// 	if (res0[t-1]-(charge[t].first - charge[t-1].first)*pd < half_drive || ((res0[t-1]-(charge[t].first - charge[t-1].first)*pd >= half_drive)&& (res0[t-1] <= (charge[t+1].first - charge[t-1].first )*pd)))
// 	{
// 		//һ����Ҫͣ��
// 		res0[t] = half_drive * 2;
// 		cost = cost + 2 + (res0[t] - res0[t-1]) * charge[t].second ;
// 		dfs (t + 1);

// 	}
	
// 	// ����Ҫͣ��
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
// 	for (i=1 ; i<=num ; i++){cin >> charge[i].first >> charge[i].second;}  //�������ľ���   ÿ�����͵ļ۸�
// 	dfs(1);
// 	cout << res;
	
// 	return 0;
// }
#include <iostream>
#include <stdio.h>
#include <float.h>
 
using namespace std;
 
/********�������ݲ���*******/
double length;
double capa,mile,cost;
int n;
 
double dis[51];
double price[50];
/****************************/
 
/****�㷨���õ�����������***/
bool isAdd[50];     //�ڵ�i������վ�Ƿ����
 
double min_cost[50];    //����¼  ����㵽�յ�Ҫ���ѵ�����Ǯ

int cnt;
 
double maxdis;      //�����ͺ����ߵ�������
/****************************/
 
/**********��������*********/
double dp(int i);   //���ء��ӵ�i������վ���ͳ����������յ����С���á�
 
void input();   //��������
void init();    //������ʼ��
void output(double mincost);   //�������
/****************************/
 
int main()
{
    input();    //��������
 
    init();     //������ʼ��
 
    double mincost=dp(0);  //����õ���С����
 
    output(mincost);    //�������
 
    return 0;
}
 
void input()    //��������
{
    //��һ��
    cin>>length;
 
    //�ڶ���
    cin>>capa>>mile>>cost>>n;
 
    //����ȥ��n��
    for(int i=1; i<=n; i++)   //����վ��1��ʼ���
    {
        cin>>dis[i]>>price[i];  //���������ͼ�
    }
 
    dis[0]=0;           //�������Ϊ��0������վ��ʵ����û�У�
    dis[n+1]=length;    //�����յ�Ϊ��n+1������վ��ʵ����û�У�
}
 
void init()     //������ʼ��
{
    for(int i=1; i<=n+1; i++)
    {
        isAdd[i]=false; //ÿ������վ��ʼ��Ϊ������
        min_cost[i]=DBL_MAX;    //�Ӽ���վi���յ�ķ�����Ϊ���ֵ
    }
    min_cost[0]=DBL_MAX;    //����㵽�յ�ķ�����Ϊ���ֵ
 
    cnt=0;  //��Ҫ���͵ļ���վ����
 
    maxdis=capa*mile;   //�����ͺ��ܵ����������
}
 
double dp(int i)    //����״̬�Ӽ���վi���յ����С����
{
    if(i==n+1)      //�����յ�
    {
        return cost;    //���ϡ����������͵ķ��á�
    }
 
    else if(min_cost[i]!=DBL_MAX)   //����¼���м�¼
    {
        return min_cost[i]; //ֱ�ӷ���
    }
 
    else    //������¼���޼�¼������Ҫ������д
    {
        double fuel_j;      //�Ӽ���վi�������վj�ķѵ�����
        double fuel_remain; //�Ӽ���վi�������վj��ʣ�µ�����
        double cost_j;      //�Ӽ���վi�������վj�����ڼ���վj�����͵ķ���
        double cost_j_n;    //�Ӽ���վi����������վj���Ͳ������յ���ܷ���
 
        int min_j=-1;   //��¼��Ҫ���͵ļ���վ�±�
 
        for(int j=i+1; j<=n+1&&(dis[j]-dis[i])<=maxdis; j++)   //�����Ӽ���վi�������ܹ�����ļ���վj
        {
            fuel_j=(dis[j]-dis[i])/mile;    //����Ӽ���վi�������վj�ķѵ�����
 
            fuel_remain=capa-fuel_j;    //���㵽�����վj��ʣ�µ�����
            if(fuel_remain>capa/2       //���ʣ�µ��ͳ���һ��
               &&fuel_remain*mile>=(dis[j+1]-dis[j]))   //����ʣ�µ����ܹ������j+1������վ
            {
                continue;   //��ô�����������
            }
 
            if(j==n+1)      //�����ֱ�ӵ����յ�
            {
                cost_j=0;   //�����յ㲻�ü��ͣ�Ҳ�������ͷ���
            }
            else            //������Ҫ�ڼ���վj������
            {
                cost_j=2;   //��˾�����ǳ�
                cost_j+=fuel_j*price[j];    //�����͵ķ���=�ķѵ���*�ͼ�
            }
 
            cost_j_n=cost_j+dp(j);  //��i�����յ�ķ���=��i����j�ķ���+��j�����յ�ķ���
 
            if(min_cost[i]>cost_j_n)    //����jʱ��ȡ��С�ġ���i�����յ�ķ��á�
            {
                min_cost[i]=cost_j_n;   //��¼��i���յ����С����
                min_j=j;    //��¼��i���յ��;�����ڼ���վj�ӹ���
            }
        }
 
        if(min_j!=-1)   //���min_j�����ڳ�ʼֵ��֤��;�мӹ���
        {
            isAdd[min_j]=true;  //��¼��i���յ��;�����ڵ�min_j���շ�վ�ӹ���
        }
 
        return min_cost[i]; //���ش�i���յ����С����
    }
}

void output(double mincost)
{
    //�����һ��
    printf("%.2f ",mincost);
 
    //���㲢������ʹ���
    for(int i=1; i<=n; i++)
    {
        if(isAdd[i])
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
 
    //����ڶ���
    for(int i=1; i<=n; i++)
    {
        if(isAdd[i])
        {
            cout<<i<<' ';
        }
    }
    cout<<endl;
}
