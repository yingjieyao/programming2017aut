#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double a[110];
double b[110];
int judge(double arr[],int n)
{
    int flag=0;
    int i;
    for(i=1;i<=n;i++)
    {
        if(arr[i]!=0)
        {
            flag=1;
        }
    }
    if(flag==0) return 1;
    else
        return 0;
}
int main(){
    int T,N,i,j,k=1;
    double sum;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d",&N);
        for(i=1;i<=N;i++)
        {
            scanf("%lf",&a[i]);
        }
        while(!judge(a,N))
        {
            for(i=1;i<=N;i++)
            {
                if(a[i]==0) continue;
                else if(a[i]>1)
                {
                    a[i]-=1;
                    sum+=1;
                }
                else if(a[i]<=1&&a[i]!=0)
                {
                    sum+=a[i];
                    a[i]=0;
                    b[i]=sum;
                    sum+=1;
                }

            }
        }
        printf("Case %d:%.2f",k,b[1]);
        k++;
        for(i=2;i<=N;i++)
        {
            printf(" %.2f",b[i]);
        }
        printf("\n");
    }
}