#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
typedef long long LL;
const int maxn = 1005;
using namespace std;
LL GCD(LL x, LL y)
{
	if(x < y)
	{
		LL tp = x;
		x = y;
		y = tp;
	}
	LL tmp;
	while(y > 0)
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}
LL MIN(LL a, LL b)
{
	return a <= b ? a : b;
}
LL a[maxn];
int main()
{
	LL kase;
	scanf("%lld", &kase);
	while(kase--)
	{
		LL n;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);

		LL ans = a[1] * a[2] / GCD(a[1], a[2]);
		for(int i = 1; i <= n; i++)
		{
			for(int j = i+1; j <= n; j++)
			{	
				ans = MIN(ans, a[i]*a[j]/GCD(a[i], a[j]));
			}
		}
		printf("%lld\n", ans);	
	}
	return 0;
}