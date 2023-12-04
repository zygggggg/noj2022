/*
1、在主函数 main 中，你使用 cin 读取字符并拼接到字符串 s 中，这样会将空格也读取进去。
2、牛逼 ！！！ void change (string &now , int i) 注意用引用！！
3、注意弄个now的副本 chan
4、初始化string s  
 s = "";
*/
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

void change (string &now , int i)
{
    if (i==0)
    {
        swap (now[0] , now[1]);
        swap (now[0] , now[4]);
        swap (now[0] , now[3]);    
    }
    else 
    {
        swap (now[1] , now[2]);
        swap (now[1] , now[5]);
        swap (now[1] , now[4]);
    }
}

int bfs (string s)
{
    string end ="123456";
    queue <string> q;
    unordered_map <string , int> d; //这个状态下 要花的距离d 
    d[s]=0;
    q.push (s);
    while (!q.empty ())
    {
        string now = q.front();
        if (now == end) {return 1;}
        q.pop ();
        int i;
        
        for (i=0;i<=1;i++)
        {
            string chan = now;  // chan就是个临时的 所以不用还原 now才是本质  
            change (chan,i);    
            if (d[chan]==0) {d[chan] = d[now]+1;q.push(chan);}
            
        }
    }
    return 0;
    
}


int main()
{   
    string s;
    char m;
        
    while (cin >> m)
    {
        if (m == '0') break;
        if (m != ' ') s += m;
        if (s.size() == 6)
        {
            if (bfs(s) == 0) { cout << "No" << endl; }
            else { cout << "Yes" << endl; }
            s = "";
        }
    }
    
    return 0;
}
/*
1 3 5 2 4 6
2 5 6 4 3 1
输出 No 
Yes
*/