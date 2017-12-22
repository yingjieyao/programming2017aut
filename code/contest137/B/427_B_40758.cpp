#include <bits/stdc++.h>
using namespace std;
const int inf = 1001;
int l,r,a,b,c,d;
#define ll long long
bool judge(ll x){
	return ((ll) ((ll)a * x * x * x + (ll)b * x + (ll)c) > (ll)d);
}
int main(){
	while(scanf("%d%d%d%d", &a, &b, &c, &d) == 4){
		l = -inf;r = inf;
		while(l < r){
			int mid = (l + r) >> 1;
			if(judge(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}
