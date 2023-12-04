#include <iostream>

using namespace std;
const int N = 10010;
int a[N];
int n;
int b[N]; // ��ʱ�洢
void merge(int left , int right , int &max1 , int &max2)  //ע��Ҫ���ã�
{
    if (left == right ){ max1 = a[left] ; max2 = a[left] ;return ;}
    else if (left == right - 1) {max1 = max(a[left] , a[right]);max2 = min(a[left] , a[right]);return;}
    else 
    {
        int lmax1 , lmax2 , rmax1 , rmax2;
        int mid = (left + right)/2;
        merge (left , mid , lmax1 , lmax2);
        merge (mid+1 , right , rmax1 , rmax2);
        if(lmax1 > rmax1){max1 = lmax1; max2 = max(lmax2 , rmax1);}
        else {max1 = rmax1 ; max2 = max(lmax1 , rmax2);}
        // int i = left;
        // int j = mid+1;
        // int k = 0;
        // while(i <= mid && j <= right)
        // {
        //     if (a[i] <= a[j]){b[k++] = a[i++];}
        //     else {b[k++] = a[j++] ;}
        // }
        // while (i <= mid) {b[k++] = a[i++];}
        // while (j <=right) {b[k++] = a[j++];}
        // //�Ż�ȥ
        // k = 0;
        // i = left;
        // while (i <= right){a[i++] = b[k++];}
    }
    
}

int main()
{
    int max1=0 , max2=0;
    int i ;
    cin >> n;
    for (i=0; i<n ; i++){cin >> a[i] ;}
    merge(0 , n-1 , max1 , max2); // ע�� ���������õĻ� ����Ҫmax1 max2 ������ֱ����0
    for (i=0 ; i<n; i++) { cout << a[i] << ' ' ;}
    cout << endl;
    cout << max1 << ' ' << max2;
    return 0;
}
/*
5
3 2 1 4 5
*/
/*
10
21 5 9 3 6 2 8 11 2 10
*/
//��ô�ҵ�һ���͵ڶ����������

