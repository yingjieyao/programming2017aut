#include<cstdio>
#define nn 105
using namespace std;
int T,n,fl;
double a[nn],ans[nn],now;
int main(){
    scanf("%d",&T);int id=0;
    while (T--){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%lf",&a[i]);
    now=0;
    while (1){
    fl=0;
    for (int i=1;i<=n;i++)if (a[i]>0){
    if (a[i]>1.0){
        now+=1;a[i]-=1;        
        }else {ans[i]=a[i]+now;
        now+=a[i]+1;a[i]=0;
        }
    fl=1;
    }
    if (!fl)break;
    }
    printf("Case %d:",++id);
    for (int i=1;i<n;i++)printf("%.2lf ",ans[i]);printf("%.2lf\n",ans[n]);
    }
    return 0;
}
