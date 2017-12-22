#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int m,n;
    char a[101][500],b[101][500];
    char qu[1000];
    scanf("%d%d",&m,&n);
    int i,j;
    getchar();
    for(i=0;i<m;i++)
    {
        gets(a[i]);
        gets(b[i]);
    }
    for(j=0;j<n;j++)
    {
        gets(qu);
        int f=1;
        for(i=0;i<m;i++)
        {
            if(strcmp(qu,a[i])==0)
            {
                printf("%s\n",b[i]);
                f=0;
                break;
            }
            qu[0]=qu[0]+32;
             if(strcmp(qu,a[i])==0)
            {
                printf("%s\n",b[i]);
                f=0;
                break;
            }
            qu[0]=qu[0]-32;
            qu[0]=qu[0]-32;
            if(strcmp(qu,a[i])==0)
            {
                printf("%s\n",b[i]);
                f=0;
                break;
            }
            qu[0]=qu[0]+32;

        }
        if(f) printf("What are you saying?\n");
    }
    //printf("Hello world!\n");
    return 0;
}
