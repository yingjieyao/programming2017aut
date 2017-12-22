#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int m,n,i,j,t,ii,as,t1,t2,zh,mb,kw;
int a[10000];

int main()
{
    //freopen("testin.txt","r",stdin);
    //freopen("myout.txt","w",stdout);
    scanf("%d",&t);
    for(ii=0;ii<t;ii++)
    {
        memset(a,-1,sizeof(a));zh=1;mb=0;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)a[i]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&t1,&t2);
            if((a[t1]==0)&&(a[t2]==0))
            {
                a[t1]=zh;a[t2]=zh;zh++;
            }
            else
            {
                if(a[t1]==0)a[t1]=a[t2];
                if(a[t2]==0)a[t2]=a[t1];
                if((a[t1]!=0)&&(a[t2]!=0)&&(a[t1]!=a[t2]))
                {
                    mb++;
                    for(j=1;j<=n;j++)
                    {
                        if(j==t2)continue;
                        if(a[j]==a[t2])a[j]=a[t1];
                    }
                    a[t2]=a[t1];
                }
            }
        }
        kw=0;
        for(i=1;i<=n;i++)if(a[i]==0)kw++;
        printf("%d\n",zh-mb+kw-1);
    }


    return 0;
}
