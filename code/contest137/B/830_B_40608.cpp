#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    long long a, b, c, d, x,right = 1001, left = -1001, mid, ans, m;
    while((scanf("%lld %lld %lld %lld", &a, &b, &c, &d)) != EOF)
    {
        right = 1001, left = -1001;
        while(right > left && right - left > 1)
        {
            mid = (right + left) / 2;
            if(a * mid * mid * mid + b * mid + c > d)
            {
                right = mid;
            }
            else
                left = mid;
        }
            m = mid;
        if(a * m * m * m + b * m + c > d)
            ans = m;
        else
            ans = m + 1;
        printf("%lld\n", ans);
    }
    return 0;
}
