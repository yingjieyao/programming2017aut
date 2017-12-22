#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxl = 105;
const int maxm = 105;
char qu[maxm][maxl];
char ans[maxm][maxl];
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	getchar();
	for(int i = 0; i < m; i++)
	{
		char c;
		int len = 0;
		while((c = getchar()) != '\n')
		{
			if(c >= 'A' && c <= 'Z')
				c += 32;
			qu[i][len++] = c;
		}
		qu[i][len] = '\0';
		
		len = 0;
		while((c = getchar()) != '\n')
		{
			ans[i][len++] = c;
		}	
		ans[i][len] = '\0';		
//		printf("%s\n%s\n", qu[i], ans[i]);
	}
	char q[maxl];	
	for(int i = 0; i < n; i++)
	{
		char c;
		int len = 0;
		while((c = getchar()) != '\n')
		{
			if(c >= 'A' && c <= 'Z')
				c += 32;
			q[len++] = c;
		}
		q[len] = '\0';
//		printf("%s\n", q);
		int flag = 0;
		for(int j = 0; j < m; j++)
		{
			if(strcmp(q, qu[j]) == 0)
			{
				printf("%s\n", ans[j]);
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			printf("What are you saying?\n");
		}
	}
	return 0;
}