#include <iostream>
#include <cmath>
using namespace std;
const int N = 30;
int a[N];
int used[N];
bool pending(int a , int b)
{
    int i ;
    int m = a + b;
    int n = sqrt(m);
    for (i=2 ; i<= n ; i++)
    {
        if (m % i == 0){return 0;}
    }
    return 1;
}
void output()
{
    int i ;
    for (i=1 ; i<=20 ; i++){cout << a[i] << ' ';}
}

bool dfs(int t)
{
    if (t == 21)
    {
        if (pending (a[20] , a[1])){output() ; return 1;}
        else {return 0;}
    }
    else
    {
        int i ;
        for (i=1 ; i<=20 ; i++)
        {
            if (used[i] == 0 && pending(i , a[t-1])) // 这个地方可以放i
            {
                a[t] = i;
                used[i] = 1;
                if (dfs (t+1)) {return 1;};
                a[t] = 0;
                used[i] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    dfs(1);
    return 0;
}