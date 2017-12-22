#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int m, n;
struct data
{
    char q[110];
    char a[110];
}da[110];
//typedef struct data D;
//D que[10010];

int sear(char s[])
{
    int k = -1;
    for(int i = 0; i < m; i++)
    {
        if(strcmp(s, da[i].q) == 0)
        {
            k = i;
            break;
        }
    }
    return k;
}

int main()
{
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++)
    {
        getchar();
        gets(da[i].q);
        gets(da[i].a);
    }
    char s[110];
    int t;
    for(int i = 0; i < n; i++)
    {
        getchar();
        gets(s);
        t = sear(s);
        if(t == -1) printf("What are you saying?\n");
        else printf("%s\n", da[t].a);
    }
    return 0;
}
