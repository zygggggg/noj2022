// #include<cstdio>
// #include<cstring>
// #include<iostream>
// #include<algorithm>
// using namespace std;
// const int maxn=25;
// int n;
// char a[maxn];
// void dfs(int t){
// 	int i;
// 	if(t==n+1){
// 		for(i=1;i<=n;i++)cout<<a[i];
//         cout<<endl;
// 		return ;
// 	}
// 	for(i=t;i<=n;i++){
// 		swap(a[i],a[t]);
// 		dfs(t+1);
// 		swap(a[i],a[t]);
// 	}
// }
// int main(){
// 	int i;
// 	cin>>n;
// 	for(i=1;i<=n;i++)a[i]='a'+i-1;
// 	dfs(1);
// 	return 0;
// }

 // 排列树
#include <iostream>

using namespace std;
const int N = 110;
int n;
char a[N];
void output()
{
	int i;
	for(i=0 ; i<n ;i++){cout << a[i] << ' ';}
	cout << endl;
}
void dfs(int t)
{
	if (t == n){output(); return ;} // 别忘这个return ！
	int i;
	for (i=t ; i<n ; i++)
	{
		swap(a[i] , a[t]);
		dfs(t+1);
		swap(a[i] , a[t]);
	}
}

int main()
{
	int i ;
	cin >> n;
	for (i=0 ; i<n ; i++){a[i] = 'a' + i;}
	dfs(0);
	return 0 ;
}