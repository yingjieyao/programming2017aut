#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define maxn 1100
#define maxm 1100

int h[maxn],q[maxn],dg[maxn],d[maxn];
bool f[maxn];
int nxt[maxm],poi[maxm],w[maxm];
int n,m,mm;
int intl()
{
    memset(h,0,sizeof(h));
    memset(nxt,0,sizeof(nxt));
    memset(dg,0,sizeof(dg));
    memset(d,0,sizeof(d));
    mm=0;
}
int ljb(int a,int b,int c)
{
    mm++;
    nxt[mm]=h[a];
    h[a]=mm;
    poi[mm]=b;
    w[mm]=c;
}
int main()
{
    while (scanf("%d%d",&n,&m)>-1&&m+n>0)
    {
        intl();
        for (int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            ljb(a,b,c);
            dg[b]++;
        }
        int head=0;
        int tail=0;
        for (int i=1;i<=n;i++)
            if (dg[i]==0) {tail++;q[tail]=i;}
        while (head<tail)
        {
            head++;
            int i=q[head];
            int p=h[i];
            while (p>0)
            {
                dg[poi[p]]--;
                if (dg[poi[p]]==0) {tail++;q[tail]=poi[p];}
                if (d[i]+w[p]>d[poi[p]]) d[poi[p]]=d[i]+w[p];
                p=nxt[p];
            }
        }
            if (tail<n) puts("NO SOLUTION");
            else
                for (int i=1;i<=n;i++)
                    printf("%d\n",d[i]);
    }
    return 0;
}
