#include <iostream>

using namespace std;
const int N = 1010;
int a[N];
int n ,c;
int f[N];
int load0 = 0, max0 = 0;
void dfs(int t)
{
	if (t == n)
	{
		if (load0 >= max0){max0 = load0 ;}
		return ;
	}
	if (load0 + a[t] <= c)
	{
		load0 += a[t];
		dfs(t+1);
		load0 -= a[t];
	}
	dfs(t+1); //一定别忘了这个情况！
}
int main()
{
	int i;
	cin >> n >> c;
	for (i=0 ; i<n ; i++){cin >> a[i];}
	dfs(0);
	cout << max0 ;
	return 0;
}