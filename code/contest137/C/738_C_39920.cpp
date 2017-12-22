#include<cstdio>
#define nn 1005
using namespace std;
int fa[nn];
int a,b,T,n,k,Z,z,ans;
int get(int w){return (fa[w]==w)?w:(fa[w]=get(fa[w]));}
int main(){
    scanf("%d",&T);
    while (T--){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=k;i++){
        scanf("%d%d",&a,&b);
        z=get(a);Z=get(b);
        if (z!=Z)fa[z]=Z;
        }
    int ans=0;
    for (int i=1;i<=n;i++)if (fa[i]==i)ans++;
    printf("%d\n",ans);
    }
    return 0;
}
