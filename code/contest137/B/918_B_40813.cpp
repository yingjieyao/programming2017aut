#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

double f(double x,int a, int b, int c, int d)
{
    return  a*x*x*x + b*x + c - d;
}
int main()
{
    int a,b,c,d;
    double l,r,mid,e;
    while(scanf("%d %d %d %d",&a, &b, &c, &d) != EOF)
    {
        l = -1e10;
        r = 1e10;
        while( r-l > 1e-9)
        {
            mid = (r+l)/2;
            if(f(mid,a,b,c,d) > 0)
                r = mid;
            else
                l = mid;
        }
        int g = r;
        if(f(g,a,b,c,d)>0)
        {
            printf("%d\n", g);
        }
        else
        {
            g++;
            if(f(g,a,b,c,d)> 0)
            printf("%d\n", g);
            else
                printf("%d\n", g+1);
        }

    }
    return 0;
}
