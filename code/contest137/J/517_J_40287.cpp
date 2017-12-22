#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,1,0,-1,-1,1,1,-1};

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') {if(a == '-') flag = 1; a = getchar();}
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;

char a[110][110],b[110][110],s[110];
char hh[] = "What are you saying?";

bool isque(char a,char b)
{
    if(a == b) return true;
    if(a > b) swap(a,b);
    if(a >= 'A' && a <= 'Z' && b >= 'a' && b <= 'z' && a + 'a' - 'A' == b) return true;
    return false;
}

char* get_ans()
{
    int len = strlen(s);
    for(int i = 1;i <= n;i ++)
    {
        int l = strlen(a[i]);
       // cout << s << " " << a[i] << endl;
        bool flag = 0;
        if(l != len) continue;
        for(int j = 0;j < l;j ++)
            if(!isque(a[i][j],s[j])) { flag = 1;  break; }
        if(flag) continue;
        return b[i];
    }
    return hh;
}

int main()
{
    while(~scanf("%d%d\n",&n,&m))
    {
        for(int i = 1;i <= n;i ++)
            gets(a[i]),gets(b[i]);
     //   for(int i = 1;i <= n;i ++) cout << a[i] << " " << b[i] <<endl;
        for(int i = 1;i <= m;i ++)
        {
            gets(s);
            printf("%s\n",get_ans());
        }
    }
    return 0;
}
/*

5 6
1 2 0
1 5 1
2 5 1
3 1 5
4 1 4
4 3 1
5 5
1 2 3
1 5 1
2 5 1
5 1 5
4 1 4

*/





