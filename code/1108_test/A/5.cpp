#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main()
{
    int t,n,i,len,flag;
    int a[1001],stack[1001];
    int cur,pos,top;
    while(scanf("%d",&t)!=EOF)
    {
        if(t==0)
            return 0;
        while(1)
        {
            cur=1;pos=0;top=0;
            for(i=0;i<t;i++)
            {
                scanf("%d",&n);
                //printf("i=%d n=%d flag=%d\n",i,n,flag);
                if(i==0 && n==0)
                {
                    flag=0;
                    printf("\n\n");
                    t=0;
                }
                a[i]=n;
            }
            if(t)
            {
                stack[top] = cur;
                while (pos < t && top < t)
                {
                    if (a[pos] == stack[top])
                    {
                        pos++;
                        if (--top < 0)
                        {
                            top = 0;
                            stack[top] = ++cur;
                        }
                    }
                    else
                        stack[++top] = ++cur;
                }
                if (top == t)
                    printf("No\n");
                else
                    printf("Yes\n");
            }
            if(t==0)
                break;
        }
    }
    return 0;
}
