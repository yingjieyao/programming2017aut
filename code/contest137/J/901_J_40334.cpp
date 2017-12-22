#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char q[111][111],a[111][111];
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    int i,j;
    getchar();
    for(i = 0;i<m;i++)
    {
        gets(q[i]);
        j = 0;
        while(q[i][j] != '\0')
        {
            if(q[i][j] >= 'A' && q[i][j] <= 'Z')
                q[i][j] = q[i][j] - 'A' + 'a';
            j++;
        }
        gets(a[i]);
    }
    char ch[111];
    for(i = 0;i < n;i++)
    {
        int state = 0;
        gets(ch);
        j = 0;
        while(ch[j] != '\0')
        {
            if(ch[j] >= 'A' && ch[j] <= 'Z')
                ch[j] = ch[j] - 'A' + 'a';
            j++;
        }
        for(j = 0;j<m;j++)
        {
            if(strcmp(q[j],ch) == 0)
            {
                state = 1;
                puts(a[j]);
                break;
            }
        }
        if(state == 0)
            printf("What are you saying?\n");
    }
    return 0;
}