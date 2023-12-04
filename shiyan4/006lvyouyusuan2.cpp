#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;

int length , capa , len_capa , num;
double cost ;
typedef pair <int , int> PII; // 距离 单价

int dp[N]; // 从i开始到终点的最小花费
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
    if (dp[t] != 0x3f3f3f3f) { return dp[t];} // 已经存在最小
    int j ;
    double fuel_j;      //从加油站i到达加油站j耗费的油量
    double fuel_remain; //从加油站i到达加油站j后，剩下的油量
    double cost_j;      //从加油站i到达加油站j，并在加油站j加满油的费用
    double cost_j_n;    //从加油站i，经过加油站j加油并到达终点的总费用
    for (j = t+1 ; space[j].first - space[t].first >= capa*len_capa ; j++) // 肯定满油 因为只有满油才能扩展
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