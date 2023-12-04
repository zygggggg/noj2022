// #include <iostream>

// using namespace std;
// const int N=10010;
// int a[N];
// int n,m;
// bool search(int t)
// {
//     int i=0,j=n-1;
//     while(i<j)
//     {
//         int mid=(i+j)/2;
//         if(a[mid]<t){i=mid+1;}
//         else{j=mid;}
//     }
//     if(a[i]==t){return 1;}
//     else {return 0;}
    
    
// }

// int main()
// {
//     cin>>n;
//     int i;
//     for(i=0;i<n;i++){cin>>a[i];}
//     cin>>m;
//     int k;
//     for(i=0;i<m;i++)
//     {
//         cin>>k;
//         if(search(k)){cout<<"Yes"<<endl;}
//         else{cout<<"No"<<endl;}
//     }
//     return 0;
// }
// /*

// */
/* 5
1 3 4 7 11
3
3
6
9 */
#include <iostream>

using namespace std;
const int N = 100010;
int a[N];
int n;
int k;
bool search (int left , int right)
{
    if (left == right)
    {
        if (a[left] == k){return 1;}
        else {return 0;}
        
    }
    int mid = (left + right) / 2;
    if (a[mid] < k){if (search (mid + 1 , right)) return 1;}
    else {if (search (left , mid)) return 1;}
    return 0;
}

int main()
{
    cin >> n;
    int i;
    for (i=0 ; i < n ; i++){cin >> a[i];}
    int m;
    cin >> m;
    for (i=0 ; i<m ; i++)
    {
        cin >> k;
        if (search (0 , n-1)) {cout << "Yes" << endl;}
        else {cout << "No"<< endl;}
    }
    return 0;
}