#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    int a,b,i,k;
    char que[111][111],ans[111][111],qu[111][111];
    scanf("%d%d",&a,&b);
    getchar();
    for(i=0; i<a; i++)
    {
        gets(que[i]);
        gets(ans[i]);
    }
    for(i=0; i<b; i++)
        gets(qu[i]);
    for(i=0; i<b; i++)
    {
        for(k=0; k<a; k++)
        {
            if(strcasecmp(qu[i],que[k])==0)
            {
                printf("%s",ans[k]);
                break;
            }
            else if(k==a-1)
                printf("What are you saying?");
        }
        if(i!=b-1)
            printf("\n");
    }
    return 0;
}