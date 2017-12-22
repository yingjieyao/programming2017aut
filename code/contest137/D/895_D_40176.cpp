#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Node{
    int l,r,val;
}w[100005];
int f[1005];
int father(int x){
    if (f[x]==x) return x;
    else return f[x]=father(f[x]);
}
bool cmp(Node x,Node y){
    return x.val<y.val;
}
int main()
{
    int n,m,i,num,ans,tmp1,tmp2;
    while (1){
        scanf ("%d %d",&n,&m);
        if (n==0 && m==0) break;
        for (i=1;i<=1000;i++) f[i]=i;
        for (i=1;i<=m;i++)
            scanf ("%d %d %d",&w[i].l,&w[i].r,&w[i].val);
        sort(w+1,w+m+1,cmp);
        num=0;
        ans=0;
        for (i=1;i<=m;i++){
            tmp1=father(w[i].l);
            tmp2=father(w[i].r);
            if (tmp2!=tmp1){
                num++;
                ans+=w[i].val;
                f[tmp2]=tmp1;
            }
            if (num==n-1) break;
        }
        printf ("%d\n",ans);
    }
    return 0;
}
