#include<cstdio>
#include<algorithm>
using namespace std;

struct poi
{
    int x,a;
} a[110000];
int cmp(poi a,poi b)
{
    if (a.x<b.x) return 1; return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int www=1;www<=T;www++)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i].x);
        int flg=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].a);
            flg+=a[i].a;
        }
        if (flg==0)
        {
            printf("Case #%d: %d\n",www,-1);
            continue;
        }
        sort(a+1,a+n+1,cmp);
        int l=1;
        while (a[l].a!=1) l++;
        int r=n;
        while (a[r].a!=1) r--;
        int mans=0;
        int tmp=0;
        for (int i=l+1;i<=r;i++)
        {
            tmp=max(a[i].x-a[i-1].x,tmp);
            if (a[i].a==1) {mans+=tmp;tmp=0;


            }
        }
        int ans=a[n].x-a[1].x-mans;
        printf("Case #%d: %d\n",www,ans);
    }
}
