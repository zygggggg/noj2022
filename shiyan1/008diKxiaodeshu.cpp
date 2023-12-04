/*
1��ע��search(0,n-1,k); �ҵ�kС  search����Ҳ��k ������k-1��
��Ϊ�����ע���Ǹ��� 
2��ע�ػ��� ע�ش���ģ��
3��ע��left_len=j-left+1;  ����ֱ����j ��Ϊ�����ע���Ǹ��� �������±�
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
   else {return a[left + k-1];} // ��ѩ�˸İ� �����ģ��Ļ� ��ѩ�˵ıȽ�����
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
���������
3
*/