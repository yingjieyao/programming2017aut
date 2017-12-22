
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m,n;
char a[111][111];
int x[4]={1,0,-1,0};
int vis[111][111];
int y[4]={0,1,0,-1};
int x1[8]={1,1,1,0,0,-1,-1,-1};
int y11[8]={1,0,-1,1,-1,1,0,-1};
void sort(int i,int j)
{
    int k;
    if(i<1||i>n||j<0||j>=m) return;
    if(vis[i][j]==1||(a[i][j]=='#')) return;
    vis[i][j]=1;
    for(k=0;k<4;k++)
    {
        sort(i+x[k],j+y[k]);
    }
}
void sort1(int i,int j)
{
    int k;
    if(i<1||i>n||j<0||j>=m) return;
    if(vis[i][j]||(a[i][j]=='#')) return;
    vis[i][j]=1;
    for(k=0;k<8;k++)
    {
        sort1(i+x1[k],j+y11[k]);
    }
}
int main()
{int t;
   int cas;
   scanf("%d",&cas);
   int i;
   int j;
   while(cas--)
   {
       t=0;
int p=0;
       scanf("%d %d",&n,&m);
       for(i=1;i<=n;i++)
       {

               scanf("%s",a[i]);

       }

       memset(vis,0,sizeof(vis));
       for(i=1;i<=n;i++)
       {
           for(j=0;j<m;j++)
           {
               if(a[i][j]=='@'&&vis[i][j]==0)
               {

                   sort(i,j);

                   t++;
               }
           }
       }
       memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
       {
           for(j=0;j<m;j++)
           {
               if(a[i][j]=='@'&&vis[i][j]==0)
               {

                  sort1(i,j);
                   p++;
               }
           }
       }
       printf("%d %d\n",t,p);
   }
    return 0;
}
