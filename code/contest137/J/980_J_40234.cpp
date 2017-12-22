#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char ask[105];
    char answer[105];
}a[105];
int n, m;
int check(char s[])
{
    int i, j, len = strlen(s);
    for(j = 0; j < m; j++)
    {
        int l = 0;
        for(i = 0; i < len; i++)
        {
            if(s[i] == a[j].ask[i] || s[i] == a[j].ask[i] + 'A' - 'a' || s[i] == a[j].ask[i] - 'A' + 'a') l++;
        }
        if(l == len) return j;
    }
    return -1;
}
int main()
{
    int i, j;
    char s[105];
    scanf("%d %d", &n, &m);
    getchar();
    for(i = 0; i < m; i++)
    {
        gets(a[i].ask);
        gets(a[i].answer);
    }
    for(i = 0; i < n; i++)
    {
        gets(s);
        int res = check(s);
        if(res == -1) puts("What are you saying?");
        else puts(a[res].answer);
    }
    return 0;
}
