#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;

int length , capa , len_capa , num;
double cost ;
typedef pair <int , int> PII; // ���� ����

int dp[N]; // ��i��ʼ���յ����С����
PII space[N];
void input()
{
    cin >> length ;
    cin >>capa >> len_capa >> cost >> num ;
    int i ;
    for (i=0 ; i< num ; i++){cin >> space[i].first >> space[i].second ;}
}
void init()
{
    memset (dp , 0x3f3f3f3f , sizeof (dp));
}

int search(int t)
{
    if (t > num){return dp[0];}
    if (dp[t] != 0x3f3f3f3f) { return dp[t];} // �Ѿ�������С
    int j ;
    double fuel_j;      //�Ӽ���վi�������վj�ķѵ�����
    double fuel_remain; //�Ӽ���վi�������վj��ʣ�µ�����
    double cost_j;      //�Ӽ���վi�������վj�����ڼ���վj�����͵ķ���
    double cost_j_n;    //�Ӽ���վi����������վj���Ͳ������յ���ܷ���
    for (j = t+1 ; space[j].first - space[t].first >= capa*len_capa ; j++) // �϶����� ��Ϊֻ�����Ͳ�����չ
    {
        
    }
}

int main()
{
    input();
    init();
    search(0); 
    return 0;
}