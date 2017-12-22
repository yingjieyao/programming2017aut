#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
const ll inf = pow(10,18);
ll a[N];
int T,n;
ll ans;
ll gcd(ll x, ll y){
	if(x < y) swap(x, y);
	if(y == 0) return x;
	return gcd(y, x % y);
}
int main(){
	scanf("%d", &T);
	while(T--){
		ans = inf;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				ans = min(ans, (ll) a[i] * a[j] / gcd(a[i], a[j]));
		printf("%lld\n", ans);
	}
}
