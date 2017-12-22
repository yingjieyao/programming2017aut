#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int fa[1001],flag[1001];
void make_set()
{
    int i;
    for(i=0;i<1001;++i) fa[i]=i;
    return;
}
int find_root(int x)
{
    if(fa[x]==x) return x;
    fa[x]=find_root(fa[x]);
    return fa[x];
}
void union_set(int a,int b)
{
    int tx=find_root(a);
    int ty=find_root(b);
    if(tx==ty) return;
    fa[tx]=ty;
    return;
}
int main()
{
    int x,q,n,m,i,a,b,p;
    scanf("%d",&q);
    for(x=0;x<q;++x)
    {
        scanf("%d %d",&n,&m);
        make_set();
        for(i=0;i<m;++i)
        {
            scanf("%d %d",&a,&b);
            union_set(a,b);
        }
        int count=0;
        memset(flag,0,sizeof(flag));
        for(i=1;i<=n;++i)
        {   //printf("%d %d\n",fa[i],flag[fa[i]]);
        p=find_root(i);
            if(!flag[p])
            {
                flag[p]=1;
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
