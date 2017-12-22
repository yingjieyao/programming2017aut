#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define nn 100005
#define inf 1000000000
using namespace std;
int T,n,a,b,c,r,tem,A[nn][21],f[nn][21];
int main(){
    while (1){
    scanf("%d",&n);
    if (!n)break;
    memset(A,0,sizeof(A));
    for (int i=1;i<=n;i++){
        scanf("%d%d%d",&a,&b,&c);
         r=max(r,b);
        A[b][a]+=c;
        }
    for (int i=0;i<=r;i++)
    for (int j=0;j<=20;j++)f[i][j]=-inf;
        
    f[0][10]=tem=0;
    for (int i=1;i<=r;i++){
        for (int j=0;j<=20;j++){
            if (j-1>=0)f[i][j]=max(f[i][j],f[i-1][j-1]+A[i][j]);
            f[i][j]=max(f[i][j],f[i-1][j]+A[i][j]);
            if (j+1<=20)f[i][j]=max(f[i][j],f[i-1][j+1]+A[i][j]);
            tem=max(tem,f[i][j]);
            }
    }
    printf("%d\n",tem);        
    }
    return 0;
}
