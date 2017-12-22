#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    char q[111][111],r[111][111];
    char in[111];
    int m,n;
    scanf("%d%d",&m,&n);
    char c = getchar();
    for (int i = 0;i < m;i++)
    {
        gets(q[i]);
        gets(r[i]);
        int lenq = strlen(q[i]);
        int lenr = strlen(r[i]);
        for (int j = 0;j < lenq;j++)
            if (q[i][j] >= 'A' && q[i][j] <= 'Z') q[i][j] += 32;
    }
    for (int i = 0;i < n;i++)
    {
        gets(in);
        int lenin = strlen(in);
        for (int j = 0;j < lenin;j++)
            if (in[j] >= 'A' && in[j] <= 'Z') in[j] += 32;
        int state = 0;
        for (int j = 0;j < m;j++)
        {
            if (!strcmp(in,q[j]))
            {
                puts(r[j]);
                state = 1;
                break;
            }
        }
        if (!state) printf("What are you saying?\n");
    }
    return 0;
}
