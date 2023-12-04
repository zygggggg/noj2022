// #include<iostream>
// #include<cstdio>
// #include<cmath>
// using namespace std;
 
// int main()
// {
// 	int n,m;
//     double arr1[2000];
// 	double arr2[2000];
// 	int i,j;
// 	double ans,minn;
// 	while(~scanf("%d%d",&n, &m))
// 	{
// 		for(i=0;i<n;i++)
// 		{
// 		    arr1[i]=i*(10000.0/n);
// 		}
// 		for(i=0;i<(m+n);i++)
// 		{
// 		    arr2[i]=i*(10000.0/(m+n));
// 		}
// 		ans=0;
// 		for(i=0;i<n;i++)
// 		{
// 			minn=10000;
// 			for(j=0;j<(m+n);j++)
// 			{
// 			    minn=min(minn,fabs(arr1[i]-arr2[j]));
// 			}
// 			ans+=minn;
// 		}
// 		printf("%.4lf\n",ans);
// 	}
// }
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 2000;
double arr1[N] , arr2[N];
int n , m;
double res = 0;
int main()
{
    cin >> n >> m;
    int i ;
    for (i=0 ; i<n ; i++){arr1[i] = i * (10000.0 / n);}
    for (i=0 ; i<m+n ; i++){arr2[i] = i * (10000.0 / (n+m));} // 这个是绝对正确的
    int j ;
    for (i=0 ; i<n ; i++)
    {
        double k = 10000.0;
        for (j=0 ; j<(m+n) ; j++)
        {
            k = min(k , abs(arr1[i] - arr2[j]));
        }
        res += k ;
    }
    cout << fixed << setprecision(4) << res ;
    return 0;
}