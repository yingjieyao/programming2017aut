#include <stdio.h>

int main()
{
    int n, k, i;
    double ans = 0;
    scanf("%d", &n);
    k = 1;
    for (i = 1; i <= n; ++i)
    {
        ans += k * 1.0 / i;
        k *= -1;
    }
    printf("%lf\n", ans);

    return 0;
}
