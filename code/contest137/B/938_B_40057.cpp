#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll a, b, c, d;
bool findans(ll x){
    return a*x*x*x + b*x + c > d;
}
int main()
{
    while(scanf("%lld%lld%lld%lld",&a, &b, &c, &d) == 4){
        ll l = -1000, r = 1000, mid=(l + r) / 2;
        while(l <= r){
            if(findans(mid)) r = mid - 1;
            else l = mid + 1;
            mid = (l + r) / 2;
        }
        printf("%lld\n",r + 1);
    }
    return 0;
}
