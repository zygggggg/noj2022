/*
//�������Ϊc �ı�������װ�ء���n ����Ʒ��ѡȡװ�뱳������Ʒ��
//ÿ����Ʒi ������Ϊwi ����ֵΪpi �����ڿ��еı���װ�أ�
//��������Ʒ�����������ܳ������������������װ����ָ��װ�����Ʒ��ֵ��ߡ�
//1��while(cin>>n&&cin>>c) ��Ҫ�� ���Ƕ���00ʱ�Ѿ���ȥ�� Ҫif Ȼ��break
//*/
/*
//#include <iostream>
//
//using namespace std;
//int c,n;
//typedef struct object{
//int wi;
//int p1;
//};
//int putin[100];
//object thing[100];
//int max0=0;
//void dfs(int t,int sump,int sumw)//���nλ��������
//{
//    if(t>n)
//    {
//        if(sumw<=c&&sump>max0)
//        {
//            max0=sump;
//        }
//    }
//    else{
//    if(sumw+thing[t].wi<=c)
//    {
//        putin[t]=1;
//        dfs(t+1,sump+thing[t].p1,sumw+thing[t].wi);
//    }
//    putin[t]=0;
//    dfs(t+1,sump,sumw);}
//}
//
//int main()
//{
//    cin>>n>>c;
//    int i;
//    for(i=1;i<=n;i++){cin>>thing[i].wi;}
//    for(i=1;i<=n;i++){cin>>thing[i].p1;}
//    dfs(1,0,0);
//    cout<<max0;
//    return 0;
//}
//*/
/*
//5 12
//1 3 4 5 6
//2 5 6 7 8
//0 0
//*/
//
//#include <iostream>
//
//using namespace std;
//int c,n;
//typedef struct object{
//int wi;
//int p1;
//};
//int putin[100];
//object thing[100];
//int m[100];c
//int max0=0;
//��� �ബ
//void dfs(int t,int sump,int sumw,int left_boat,int left_thing,int k)//���nλ��������
//{
//    if(t>n)
//    {
//        if(sumw<=c&&sump>max0)
//        {
//            m[k]=sump;
//        }
//    }
//    else{
//    if(sumw+thing[t].wi<=c)
//    {
//        putin[t]=1;
//        dfs(t+1,sump+thing[t].p1,sumw+thing[t].wi,left_boat-thing[t].wi,left_thing-thing[t].wi,k);
//    }
//    if(left_boat<left_thing)
//    {
//    putin[t]=0;
//    dfs(t+1,sump,sumw,left_boat,left_thing,k);
//    }
//}
//}
//
//int main()
//{
//
//    int i;
//    int left_thing=0;
//    int k=0;
//
//    while(cin>>n&&cin>>c){
//            if(n==0&&c==0)break;
//    for(i=1;i<=n;i++){cin>>thing[i].wi;left_thing+=thing[i].wi;}
//    for(i=1;i<=n;i++){cin>>thing[i].p1;}
//
//    dfs(1,0,0,c,left_thing,k);
//    k++;
//    }
//    for(i=0;i<k;i++){cout<<m[i]<<endl;}
//    return 0;
//}
/*
1 2
1
1
2 3
2 2
3 4
0 0
*/
// #include <iostream>
// #define N 10010
// using namespace std;
// int n,c;
// int p[N];
// int w[N];
// int max0=0;
// void dfs(int t,int sum_weight,int sum_p,int left_thing,int left_boat)
// {
//     if(t>=n){if(sum_p>max0)max0=sum_p;return ;}
//     else
//     {
//         if(sum_weight+w[t]<=c)
//             dfs(t+1,sum_weight+w[t],sum_p+p[t],left_thing-w[t],left_boat-w[t]);
//         if(left_boat<left_thing)
//         dfs(t+1,sum_weight,sum_p,left_thing,left_boat);
//     }
// }


// int main()
// {
//     int i;
//     while(cin>>n>>c)
//     {
//         max0=0;
//         int left=0;
//         if(n==0&&c==0){break;}
//         for(i=0;i<n;i++){cin>>w[i];left+=w[i];}
//         for(i=0;i<n;i++){cin>>p[i];}
//         dfs(0,0,0,left,c);
//         cout<<max0<<endl;
//     }

//     return 0;
// }
#include <iostream>

using namespace std;
const int N = 10010;
int n ;
typedef pair<int , int > PII;  //first ��� second ��ֵ
PII thing[N];
int maxV = 0 , c;
int tempV;
int tempC;
void dfs(int t)
{
    if (t >= n)
    {
        if (tempV > maxV){maxV = tempV; return;}
    }
    else
    {
        if (thing[t].first + tempC <=c )
        {
            tempC += thing[t].first;
            tempV += thing[t].second; //value ��ֵ
            dfs(t+1);
            tempC -= thing[t].first;
            tempV -= thing[t].second; //�ָ�
           
        }
        dfs(t+1);  //���ܷ�  ���ж�Ҫ������· ��������if���� 
        // ���û��ģ�� Ҫ��⣡
    }
}

int main()
{
    cin >> n;
    cin >> c;
    int i ;
    for (i=0 ; i<n ; i++){cin >> thing[i].first ;}
    for (i=0 ; i<n ; i++){cin >> thing[i].second;}
    dfs (0);
    cout << maxV << endl;
    return 0 ;
}

