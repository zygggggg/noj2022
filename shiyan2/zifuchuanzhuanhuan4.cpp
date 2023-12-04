#include <iostream>
#include <string>
#include <stack>

using namespace std; 
string org , targ;
int n;
int i_num , o_num ; //记录进出个数
char sign[20]; //记录哪里进 哪里出
stack <char> str; // 记录栈 用于pending
char pend[20] ;
void output()
{
	int i ;
	for (i=1 ; i<= 2*n - 1 ; i++)
	{
		cout << sign[i] << ' ';
	}
    cout << sign[i];
	cout << endl;
}
bool pending()
{
    int i;
    int cnt=0;
    int j=0;
    for (i=1;i <= 2*n; i++)
    {
        if (sign[i]=='i'){str.push(org[j++]);}
        else 
        {
            pend[cnt++]=str.top();
            str.pop();
        }
    }
    for (i=0;i<n;i++)
    {
        if (pend[i]!= targ[i]){return 0;}
    }
    return 1;
}
void dfs(int t)
{
	if (t > 2*n )
	{
		if (pending())
		{
			output();
		}
		return ;
	}
	if (i_num < n )
	{
		sign[t] = 'i';
		i_num ++ ;
		dfs(t+1);
		sign[t] = ' ';
		i_num -- ;
	}
	if (o_num < i_num)
	{
		sign[t] = 'o';
		o_num ++ ;
		dfs(t+1);
		sign[t] = ' ';
		o_num -- ;
	}
}

int main()
{
	while (cin >> org >> targ)
	{
		
		int len1 = org.length(); 
		int len2 = targ.length();
        n = len1;
		cout << '[' << endl;
		if (len1 == len2) dfs(1);
		cout << ']' << endl;
		i_num = 0;
		o_num = 0;
	}
	return 0;
}