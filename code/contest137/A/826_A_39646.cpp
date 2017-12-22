#include <stdio.h>
#include <stdlib.h>

#define MAX_N		500

int compare_two_integers(const void *a, const void *b);
long long gcd(long long a, long long b);

int main()
{
	int t, n;
	long long a[MAX_N];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
		qsort(a, n, sizeof *a, &compare_two_integers);
		long long min = 0x7fffffffffffffff;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i == j) continue;
				long long k = gcd(a[i], a[j]);
				long long tmp = a[i] / k * a[j];
				if(tmp < min) min = tmp;
			}
		}
		printf("%lld\n", min);
	}
	
	return 0;
}

int compare_two_integers(const void *a, const void *b)
{
	return (int)(*((long long *)a) - *((long long *)b));
}

long long gcd(long long a, long long b)
{
	if(a < b)
	{
		long long tmp = a;
		a = b;
		b = tmp;
	}
	if(a % b == 0) return b; else return gcd(b, a % b);
}
