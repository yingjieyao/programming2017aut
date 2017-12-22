#include<cstdio>

long long a[550];

long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{

    int T;
    int n;
    scanf("%d",&T);
    while (T--)
    {
        long long ans=10000000000000000;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for (int i=1;i<n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                long long k=a[i];
                k*=a[j];
                k/=gcd(a[i],a[j]);
                if (ans>k) ans=k;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
