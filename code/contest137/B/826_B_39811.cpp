#include <stdio.h>

long long func(long long a, long long b, long long c, long long x);

long long main()
{
	long long a, b, c, d;
	while(scanf("%lld%lld%lld%lld", &a, &b, &c, &d) == 4)
	{
		long long left = -1000, right = 1000;
		while(left < right)
		{
			long long middle = left + (right - left) / 2;
			long long value = func(a, b, c, middle);
			if(value > d) right = middle; else left = middle + 1;
		}
		printf("%lld\n", left);
	}
	return 0;
}

long long func(long long a, long long b, long long c, long long x)
{
	return a * x * x * x + b * x + c;
}
