#include<cstdio>
#include<algorithm>
#include<cstring>
#define nn 100005
using namespace std;
int n,pre,z,first,u,last,i,j,ans,p;
struct nod{int a,b;
}a[nn];
bool cmp(const nod&a,const nod&b){
     return a.a<b.a;
     }
int main(){int T=0,id=0;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++)scanf("%d",&a[i].a);
        for (int i=1;i<=n;i++)scanf("%d",&a[i].b);
        sort(a+1,a+n+1,cmp);
        printf("Case #%d: ",++id);
        for (u=1;u<=n&&a[u].b==0;u++);
        
        if (u==n+1)puts("-1");
        else{
        pre=u;z=0;ans=0;
        ans+=a[pre].a-a[1].a;
        for (int i=u+1;i<=n;i++)if (a[i].b==1){
            if (pre+1<i){
            z=max(z,a[i].a-a[i-1].a);
            ans+=a[i].a-a[pre].a-z;
            }
            pre=i;
            z=0;
            }else z=max(z,a[i].a-a[i-1].a);
        if (pre!=n)ans+=a[n].a-a[pre].a;
        printf("%d\n",ans);
        }
    }
    return 0;
}
/*
5
5
4 1 6 7 10
0 1 1 1 0
*/
