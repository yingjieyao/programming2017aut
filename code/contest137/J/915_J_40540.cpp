#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ask[101][101];
char ans[101][101];
char qu[101];
char use[1001];
int f(char a[],char b[],int len)
{
    int i;
    len = len > 3 ? 3 : len;
    for (i = 0;i < len;i ++)
    {
        if(abs(a[i] - b[i]) != abs('A' - 'a') && a[i] != b[i]) break;
    }
    if (i == len) return 1;
    return 0;
}
void ch(char a[])
{
    int len = strlen(a);
    int i;
    for (i = 0;i < len;i ++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z') a[i] = a[i] - 'A' + 'a';
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    int i;
    gets(use);
    for (i = 0;i < m;i ++)
    {
        gets(ask[i]);
        ch(ask[i]);
        gets(ans[i]);
    }
    for (i = 1;i <= n;i ++)
    {
        gets(qu);
        ch(qu);
        int j;
        int x = 0;
        for(j = 0;j < m;j ++)
        {
            if(strcmp(qu,ask[j]) == 0)
            {
                    printf("%s\n",ans[j]);
                    x = 1;
            }
        }
        if(x == 0)
            {
                puts("What are you saying?");
            }
    }
    return 0;
}
