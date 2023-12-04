#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int a , b;
int multa = 1 , multb = 1 ;bool real2=0;
bool real=0;
void dfs (int t)
{
    if (t == 101)
    {
        if (multa == a && multb == b){real = real2 = true;}
        else if(multb == b){real2 = true;}
    return ;}
    if (a % t == 0 && multa * t <= a)
    {
        multa *= t ;
        dfs (t+1) ;
        multa /= t;
    }
    if (b % t == 0 && multb * t <= b)
    {
        multb *= t ;
        dfs(t+1) ; 
        multb /= t;
    }
    dfs(t+1);
    
}

int main()
{
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0){break;}

        if (a < b){swap (a , b);}
        dfs (1);
        if (real && real2)
            cout << a << endl;
        else if (real2)
            cout << b << endl;
        else
            cout << a << endl;
        multa = 1;
        multb = 1;
        real=0,real2=0;
    }
    return 0;
}
/*36 62 49 343 0 0*/