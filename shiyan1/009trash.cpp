#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std; 
const int N = 1010;

int n;
typedef pair<int , int > PII;
bool cmp(const PII &a , const PII &b )
{
	return a.second < b.second ;
}
int main()
{
	int i ;
	cin >> n;
	PII act[25];
	for (i=1 ; i<=n ; i++){cin >> act[i].first >> act[i].second;}
	sort(act , act + n , cmp); 
	int ed = -1 ;
	int cnt = 0;
	for (i=1 ; i<=n ; i++)
	{
		if (act[i].first >= ed)
		{
			ed = act[i].second;
			cnt ++ ;
		}
	}
	cout << cnt << endl;
	return 0;
}