#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<ctime>
#include<cmath>
#define nn 109
using namespace std;
int n,m,X,Y,Z,ans1,ans2;
char a[nn][nn],A[nn][nn];
struct nod{int x,y;
}z;
queue<nod>q;
int han[4]={0,0,1,-1};
int lie[4]={1,-1,0,0};
int Han[8]={0,0,1,-1,-1,1,1,-1};
int Lie[8]={1,-1,0,0,-1,1,-1,1};
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
    scanf("%s",a[i]+1);
    for (int j=1;j<=m;j++)A[i][j]=a[i][j];
    }
    ans1=ans2=0;
    
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)if (a[i][j]=='@'){
    while (!q.empty())q.pop();
    a[i][j]='#';ans1++;
    q.push((nod){i,j});
    while (!q.empty()){
          z=q.front();
          q.pop();
          for (int i=0;i<4;i++){
              X=z.x+han[i];
              Y=z.y+lie[i];
              if (X>=1&&X<=n&&Y>=1&&Y<=m)
                 if (a[X][Y]=='@'){
                    a[X][Y]='#';
                    q.push((nod){X,Y});
                    }
              }
          }
          
    }
    
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)if (A[i][j]=='@'){
       while (!q.empty())q.pop();
    A[i][j]='#';ans2++;
    q.push((nod){i,j});
    while (!q.empty()){
          z=q.front();
          q.pop();
          for (int i=0;i<8;i++){
              X=z.x+Han[i];
              Y=z.y+Lie[i];
              if (X>=1&&X<=n&&Y>=1&&Y<=m)
                 if (A[X][Y]=='@'){
                    A[X][Y]='#';
                    q.push((nod){X,Y});
                    }
              }
          }
    }
    printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
