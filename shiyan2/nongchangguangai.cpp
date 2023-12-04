/*
1、 不用回溯 因为情况已经定了
2、图的问题 一定要注意判断不越界！   y-1>=1
3、非连通图问题！ 
if(vis[i][j])continue;
				ans++;
				dfs(i,j);
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100+5;
struct Node{
	int l,r,u,d;
}t[maxn],a[maxn][maxn];
int n,m,vis[maxn][maxn]; 
void dfs(int x,int y){
	if(vis[x][y])return ;
	vis[x][y]=1;
	if(a[x][y].l&&y-1>=1&&a[x][y-1].r)dfs(x,y-1);
	if(a[x][y].r&&y+1<=m&&a[x][y+1].l)dfs(x,y+1);
	if(a[x][y].d&&x+1<=n&&a[x+1][y].u)dfs(x+1,y);
	if(a[x][y].u&&x-1>=1&&a[x-1][y].d)dfs(x-1,y);
}
void init()
{
	t[1].l=t[1].u=1;
	t[2].r=t[2].u=1;
	t[3].l=t[3].d=1;
	t[4].r=t[4].d=1;
	t[5].u=t[5].d=1;
	t[6].l=t[6].r=1;
	t[7].u=t[7].l=t[7].r=1;
	t[8].l=t[8].u=t[8].d=1;
	t[9].l=t[9].r=t[9].d=1;
	t[10].u=t[10].d=t[10].r=1;
	t[11].l=t[11].r=t[11].u=t[11].d=1;
}

int main(){
	int i,j;
	init();
	while(1){
		char x;
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		if(n==-1&&m==-1)break;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>x;
				a[i][j]=t[x-'A'+1];
			}
		}
		int ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(vis[i][j])continue;
				ans++;
				dfs(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
