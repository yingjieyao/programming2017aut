#include <stdio.h>
#include <stdlib.h>
struct zfc
{
    int arr[200],brr[200];
    int x,y;
} a[100];
int main()
{
    int crr[200];
    int n,m,i,j,k,t;
    char c;
    scanf("%d %d",&n,&m);
    getchar();
    for(i=0; i<n; i++)
    {
        j=0;
        c=getchar();
        while(c!='\n')
        {
            a[i].arr[j]=c;
            j++;
            c=getchar();
        }
        a[i].x=j;
        j=0;
        c=getchar();
        while(c!='\n')
        {
            a[i].brr[j]=c;
            j++;
            c=getchar();
        }
        a[i].y=j;
    }
    for(i=0; i<m; i++)
    {
        j=0;
        c=getchar();
        while(c!='\n')
        {
            crr[j]=c;
            j++;
            c=getchar();
        }
        t=j;
        for(k=0; k<n; k++)
        {
            if(t!=a[k].x)
                continue;
            for(j=0; j<t; j++)
            {
                if(crr[j]>=97&&crr[j]<=122)
                {
                    if(a[k].arr[j]!=crr[j]&&a[k].arr[j]!=crr[j]-32)
                        j=t+1;
                }
                else if(crr[j]>=65&&crr[j]<=90)
                {
                    if(a[k].arr[j]!=crr[j]&&a[k].arr[j]!=crr[j]+32)
                        j=t+1;
                }
                else if(a[k].arr[j]!=crr[j])
                    j=t+1;
            }
            if(j==t)
            {
                for(j=0; j<a[k].y;j++)
                {
                    printf("%c",a[k].brr[j]);
                }
                printf("\n");
                k=n+1;
                break;
            }
        }
        if(k!=n+1)
            printf("What are you saying?\n");
    }
    return 0;
}
