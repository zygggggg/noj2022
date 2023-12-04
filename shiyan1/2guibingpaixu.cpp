/*
又是这里错！ 
 for (i=left ; i<=right ; i++)
    {
        a[i] = b[k++];
    }  而不是a[i++] =b[k++] 已经加过一次了！

*/
#include <iostream>

using namespace std;
const int N =  10010;
int a[N];
int b[N];
int n;
void sort0(int left , int right)
{
    if (left == right){return ;}
    int mid = (left + right) / 2;
    sort0(left , mid);
    sort0(mid+1 , right);
    int i = left , j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (a[i] < a[j]){b[k++] = a[i++];}
        else {b[k++] = a[j++];}
    }
    while (i <= mid){b[k++] = a[i++];}
    while (j <= right){b[k++] = a[j++];}
    k = 0;
    for (i=left ; i<=right ; i++)
    {
        a[i] = b[k++]; //而不是a[i++] =b[k++] 已经加过一次了！
    }
}
void output ()
{
    int i;
    for (i=0 ; i<n ; i++)
    {
        cout << a[i] << ' ';
    }
}
int main()
{
    cin >> n;
    int i;
    for (i=0; i<n ; i++){cin >> a[i];}
    sort0(0 , n-1);
    output();
    return 0;
}
/*
5
3 2 1 4 5
*/