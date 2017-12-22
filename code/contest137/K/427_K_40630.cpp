#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define N 100005
struct A{
	int col;
	ll p;
}a[N];
struct B{
	int l,r;
	ll dis;
}b[N];
bool operator < (const A &la, const A &ra){
	return la.p < ra.p;
}
bool operator < (const B &la, const B &ra){
	return la.dis < ra.dis;
}
int fa[N],dis[N];
int T,n;
ll ans;
int f(int x){return x == fa[x] ? x : f(fa[x]);}
int main(){
	scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		scanf("%d", &n);
		ans = 0;
		int jud = 0;
		for(int i = 1; i <= n; i++)
			fa[i] = i;
		for(int i = 1; i <= n; i++)
			scanf("%lld",&a[i].p);
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i].col);
			jud += a[i].col;
		}
		if(jud == 0){
			printf("Case #%d: -1\n", k);
			break;
		}
		sort(a + 1, a + 1 + n);
		for(int i = 2; i <= n; i++){
			b[i - 1].dis = a[i].p - a[i - 1].p;
			b[i - 1].l = i - 1;
			b[i - 1].r = i;
		}
		sort(b + 1, b + n);
		for(int i = 1; i < n; i++){
			int x = b[i].l,y = b[i].r;
			int fx =f(x), fy = f(y);
			if(fx == fy) continue;
			//printf("%d %d %d %d\n", x, y, fx, fy);
			if((a[fx].col ^ a[fy].col) == 1){
				ans += b[i].dis;
				a[fx].col = 1;
				a[fy].col = 1;
				fa[fx] = fy;
			}
			if((a[fx].col && a[fy].col) == 0){
				ans += b[i].dis;
				fa[fx] = fy;
			}
		}
		printf("Case #%d: %d\n", k, ans);
	}
	return 0;
}
