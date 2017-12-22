#include <stdio.h>

int f(int m, int n);
int main(void)
{
    int Case, n, i, j;
    long long tmp, min;
    long long a[1000];

    scanf("%d", &Case);
    while (Case--){
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        min = 1e19;
        for (i = 0; i < n; i++){
            for (j = i + 1; j < n; j++){
                tmp = a[i] * a[j] / f(a[i], a[j]);
                if (min > tmp)
                    min = tmp;
            }
        }
        printf("%lld\n", min);
    }
    return 0;
}

int f(int m, int n)
{
    int tmp;
    while (m % n != 0){
            tmp = m % n;
            m = n;
            n = tmp;
        }
    return n;
}
