#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const LL INF = 1e18;
const int mod = 1e9 + 7;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,1,0,-1,-1,1,1,-1};
const double eps = 1e-8;

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

struct haha
{
    LL x;
    int a;
}l[SZ];

bool cmp(haha a,haha b) { return a.x < b.x; }

/*
int st[SZ][22],lg[SZ];

void get_st(int a[],int n)
{
    memset(st,0,sizeof(st));
    for(int i = 1;i <= n;i ++) st[i][0] = a[i];
    for(int j = 1;j <= log2(n);j ++)
        for(int i = 1;i <= n;i ++)
            st[i][j] = max(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
}*/

int main()
{
    int T = read(),cc = 0;
  //  for(int i = 1;i <= 100000;i ++) lg[i] = log2(i);
    while(T --)
    {
        n = read();
        for(int i = 1;i <= n;i ++) l[i].x = read();
        for(int i = 1;i <= n;i ++) l[i].a = read();
        l[++ n] = (haha){-INF,1};
        l[++ n] = (haha){INF,1};
        sort(l + 1,l + 1 + n,cmp);
        //for(int i = 1;i <= n;i ++) cout << l[i].x << " "<< l[i].a << endl;
        LL ans = 0;
        for(int i = 1,r;i <= n;i = r)
        {
            r = i + 1;
            LL Max = l[r].x - l[r - 1].x;
            while(r <= n && !l[r].a) r ++,Max = max(Max,l[r].x - l[r - 1].x);
            ans += l[r].x - l[i].x - Max;
          //  cout << r << " " << Max << " " << ans<< endl;
        }
        if(ans >= 1e10) ans = -1;
      //  cout << ans << endl;
        printf("Case #%d: %lld\n",++ cc,ans);
    }
    return 0;
}


/*
233
2
0 2147483647
1 0
*/

