#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int f[1001],nex[200001],b[200001],e[200001];
int vis[1001];
void dfs(int k)
{   int i;
    for(i=f[k];i!=0;i=nex[i])
    {
        int y=e[i];
        if(!vis[y]) {vis[y]=1;dfs(y);}
    }

}
int main()
{   int i,j,n,T;
   cin>>T;
   for(int t=1;t<=T;t++)
   {
       cin>>n>>m;
     memset(vis,0,sizeof(vis));
     memset(f,0,sizeof(f));
     memset(nex,0,sizeof(nex));
  for(i=1;i<=m;i++)
  {  int x,y;
      cin>>b[2*i]>>e[2*i];
      b[2*i-1]=e[2*i];
      e[2*i-1]=b[2*i];
      x=b[2*i];y=b[2*i-1];
      nex[2*i]=f[x];
       f[x]=2*i;
      nex[2*i-1]=f[y];
       f[y]=2*i-1;
  }
  int ans=0;
  for(i=1;i<=n;i++)
  {
      if(!vis[i])
       {   vis[i]=1;
           ans++;
          dfs(i);
       }
  }
    cout<<ans<<endl;




   }


    return 0;
}
