#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1001;
int l,r,a,b,c,d;
bool judge(ll x){
	return ((ll)a * x * x * x + (ll)b * x + c) > 0;
}
int main(){
	while(scanf("%d%d%d%d", &a, &b, &c, &d) == 4){
		c -= d;
		l = -inf;r = inf;
		while(l < r){
			ll mid = (l + r) >> 1;
			if(judge(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}
