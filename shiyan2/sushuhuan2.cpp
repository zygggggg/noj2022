/*
1���ҵ�һ������� ��bool ��return ţ�ƣ�
2�� ѧ�� һ�ҵ���ֱ���� ���� if (dfs ..)  return 
if (dfs(t+1)) return true ;  ������ return dfs(t+1)
3��if(t==20 && isprime(a[0]+a[19])){output();return 1;}
    if(t==20 && isprime(a[0]+a[19]==0)){return 0;} ţ�ƣ�
4���ַ���������ֱ�ӷ� �������ȼ�֦�����ж��ٷ�    ֱ�ӷ����жϵĺô���˼ά�򵥴����
�ַ����ȼ�֦̫���ˣ����� 
5�� if (dfs(t+1)) return true ; �����1�Ļ� ��仰�ͷ��return ��ֱ�ӽ��� ����������
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 10010;
int a[N] ;
bool used[N]; //��������ù��� 
void output()
{
    int i;
    for (i=0 ; i<=19 ; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
bool pending(int n)
{
    int m = sqrt (n);
    int i ;
    for (i=2 ; i<= m ; i++){if (n % i == 0)return 0;}
    return 1;
}
bool dfs(int t)
{
    int i ;
    if (t == 20)
    {
        if (pending(a[0] + a[19])){output() ; return 1;}
        else {return 0;}
    }
    else
    {
        for (i=1 ; i<=20 ; i++)
        {
            if (used[i] == 0 && pending (a[t-1] + i))
            {
                a[t] = i;
                used[i] = 1;
                if (dfs(t+1)) return 1;
                a[t] = 0;
                used[i] = 0;
            }
        }
    }
    return 0;
}
int main()
{
    int i;
    a[0] = 1;
    used[1] = 1;
    dfs(1);
    return 0;
}
