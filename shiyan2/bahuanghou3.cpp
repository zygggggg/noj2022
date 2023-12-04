/*
ע�ⲻһ����if����Ū��ȥ���� 
�����if����put \ use 
��ô����if����Ū��ȥ

��������if����Ū��ȥ
*/
#include <iostream>
#include <cmath>

using namespace std;
const int N=10;
int used[N];  //�����Ƿ����ù�
int put[N]; //��i�з����ĸ�λ��
int cnt=1;
bool pending (int row,int col)
{
    int i;
    for(i=0;i<row;i++)
    {
        if(abs(row-i)==abs(col-put[i])){return 0;}
    }
    return 1;
}

void output()
{
    int i,j;
    for(i=0;i<=7;i++)
    {
        for(j=0;j<=7;j++)
        {
            if(put[i]==j){cout<<'A';}
            else {cout<<'.';}
        }
        cout <<endl;
    }
}

void dfs(int t)
{
    if (t==8)
    {
        cout<<"No "<<cnt<<':'<<endl;
        cnt++;
        output();
        return ;
    }
    int i;
    for(i=0;i<=7;i++)  //��t�� ���ڵ�i��
    {
        if(used[i]==0)
        {
            put[t]=i;
            used[i]=1;
            if(pending(t,i))
            {
                dfs(t+1);
            }
            put[t]=0;
            used[i]=0; // ���ݣ� 
        }
    }
}

int main()
{
    dfs(0);
    return 0;
}