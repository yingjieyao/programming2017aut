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
ll tim[1000];
bool mmp(ll  a, ll b){
    return a < b;
}
ll findans(ll a,ll b){
    ll c = b % a;
    ll d = a, e = b;
    while(c){
        b = a;
        a = c;
        c = b % a;
    }
    return e * d / a;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            scanf("%lld",&tim[i]);
        sort(tim + 1, tim + 1 + n, mmp);
        ll ans = 2222222222222222;
        for(int i = 1; i <= n - 1; i++)
            for(int j = i + 1; j <= n; j++){
                ll tmp = findans(tim[i], tim[j]);
                if(ans > tmp) ans = tmp;
            }
        printf("%lld\n",ans);
    }
    return 0;
}
