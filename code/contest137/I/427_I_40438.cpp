#include <bits/stdc++.h>
#define eps 1e-10
#define N 105
using namespace std;
double a[N],ans[N],t;
int nw,cnt,T,n;
int main(){
	scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		t = 0;
		cnt = 0;
		nw = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lf", &a[i]);
		while(cnt != n){
			nw++;if(nw == n + 1) nw = 1;
			if(a[nw] - 0.0 < eps) continue;
			if(a[nw] - 1.0 > eps){
				t = t + 1.0;
				a[nw] -= 1.0;
				continue;
			}
			else{
				t += a[nw] + 1.0;
				a[nw] = 0;
				ans[nw] = t - 1.0;
				cnt++;
				//printf("%d\n",nw);
			}
		}
		printf("Case %d:", k);
		for(int i = 1; i < n; i++)
			printf("%.2lf ",ans[i]);
		printf("%.2lf\n",ans[n]);
	}
}
