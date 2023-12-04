/*
1、注意search(0,n-1,k); 找第k小  search这里也是k 而不是k-1！
因为这里关注的是个数 
2、注重基础 注重代码模板
3、注意left_len=j-left+1;  不是直接用j 因为这里关注的是个数 而不是下标
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=10010;
int a[N];
int k;
int search(int left,int right,int k)
{
    if(left==right){return a[right];}
    int i=left-1,j=right+1;
    int x=a[left];
    while(i<j)
    {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j){swap(a[i],a[j]);}
   }
   int left_len=j-left+1;
   if(k<left_len){return search(left,j,k);}
   else if (k>left_len){return search (j+1 ,right , k-left_len);}
   else {return a[left + k-1];} // 大雪菜改版 如果看模板的话 大雪菜的比较清晰
}
int main()
{
    int i;
    int n;
    cin>>n;
    for(i=0;i<n;i++){cin>>a[i];}
    
    cin>>k;
    cout<< search(0,n-1,k);
    
    return 0;
}
/*
5
2 98 34512 8492 1000
4
*/
/*
5 3
2 4 1 5 3
输出样例：
3
*/