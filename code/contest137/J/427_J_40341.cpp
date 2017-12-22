#include <bits/stdc++.h>
#define N 105
using namespace std;
char a[N][N],b[N][N],s[N];
int n,m;
int main(){
	scanf("%d%d", &n, &m);
	getchar();
	for(int i = 1; i <= n; i++){
		gets(a[i]);
		gets(b[i]);
	}

	for(int i = 1; i <= m; i++){
		gets(s);
		bool fl = 0;
		for(int j = 1; j <= n; j++){
			int l1 = strlen(s);
			int l2 = strlen(a[j]);
			//printf("%d\n",l2);
			if(l1 != l2) continue;

			int cnt = 0;
			for(int k = 0; k < l1; k++)
				if(s[k] == a[j][k] || abs(s[k] - a[j][k]) == 'a'-'A')
					cnt++;
			if(cnt == l1){
				fl = 1;
				printf("%s\n", b[j]);
				break;
			}
		}
		if(fl == 0)
			printf("What are you saying?\n");
	}
}
