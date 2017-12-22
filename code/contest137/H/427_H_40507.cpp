#include <bits/stdc++.h>
using namespace std;
#define T 100005
#define P 25
#define inf 0x7fffffff
int p,t,w,n,tmax,pmax,ans;
int pie[T][P],dp[T][P];
int main(){
	while(~scanf("%d", &n) && n){
		tmax = 0;
		pmax = 0;
		ans = 0;
		memset(pie, 0, sizeof(pie));
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &p, &t, &w);
			pie[t][p] += w;
			tmax = max(tmax, t);
			pmax = max(pmax, p);
		}
		memset(dp, 255, sizeof(dp));
		dp[0][10] = 0;
		for(int i = 1; i <= tmax; i++)
			for(int j = 0; j <= pmax; j++){
				if(dp[i - 1][j] != -1)
					dp[i][j] = dp[i - 1][j] + pie[i][j];
				if(j > 0 && dp[i - 1][j - 1] != -1)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + pie[i][j]);
				if(j < pmax  && dp[i - 1][j + 1] != -1)
					dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + pie[i][j]);
			}
		for(int i = 0; i <= pmax; i++)
			ans = max(ans, dp[tmax][i]);
		printf("%d\n", ans);
	}
	return 0;
}
