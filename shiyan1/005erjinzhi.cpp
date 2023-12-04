// #include <iostream>
// #include <cstring>
// using namespace std;
// int n;
// int a[21];
// void output()
// {
//     int i=0;
//     for(i=n-1;i>=0;i--){cout<<a[i];}
//     cout<<endl;
// }


// int main()
// {
//     memset(a,0,sizeof a);
    
//     cin>>n;
    
//     while(a[n]==0)
//     {
//         output();
//         a[0]++;
//         int t=0;
//         while(a[t]==2)
//         {
//             a[t]=0;
//             a[++t]++;
//         }
//     }
//     return 0;
// }
#include <iostream>

using namespace std;
const int N = 110;
int a[N];
int n ;
void output()
{
    int i;
    for (i=1 ; i<=n ; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void dfs(int t)
{
    if (t == n+1) {output();return ;}
    a[t] = 0;
    dfs(t+1);
    a[t] = 1;
    dfs (t+1);
}
int main()
{
    cin >> n;
    dfs (1) ;
    return 0;
}