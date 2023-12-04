#include <iostream>

using namespace std;
int A , B , C;
int aa , bb , cc;
int cnt = 0;
int main()
{   
    cin >> A >> B >> C;
    int aa = A , bb = 0 , cc = 0;
    int n = A / 2;
    while (1)
    {
        if (bb == 0)
        {
            if (aa >= B){aa -= B;bb = B;}
            else {aa = 0; bb = aa;}
            cnt ++;
            if (aa == n && bb == n){cout << cnt ; break;}
        }
        
    
    if (cc < C)
    {
        int m = C - cc;
        if (bb >= m){cc =C ; bb -= m;}
        else {cc += bb; bb = 0;}
        cnt ++;
        if (aa == n && bb == n){cout << cnt ; break;}
    }
    if (cc == C)
    {
        int m = A - aa;
        if (m >= cc){aa += cc; cc = 0;}
        else {aa += cc; cc -= m;}
        cnt ++;
        if (aa == n && bb == n){cout << cnt ; break;}
    }
    }
    return 0;
}