#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int n,b[501],c1[31],ans[31],an[31],a1[31],afgcd[31],bfgcd[31];
void init()
{  int i;
 for(i=1;i<=n;i++)
 cin>>b[i];


}
int gcd(int x,int y)
{
    if(y==0)  return x;
    return gcd(y,x%y);
 }
void solve()
{  // int an[100];
    memset(an,0,sizeof(an));
    memset(a1,0,sizeof(a1));
   int i,j;
    for(i=1;afgcd[i]!=-1;i++)
        for(j=1;bfgcd[j]!=-1;j++)
          {
              an[i+j-1]+=afgcd[i]*bfgcd[j];
             // cout<<an[i+j-1];

          }
         // cout<<endl;
   for(i=1;i<=20;i++)
   {
       an[i+1]+=an[i]/10;
       an[i]%=10;
       //cout<<an[i];
   }
//cout<<endl;
//   int a1[100];
  for(i=1;i<=20;i++)
      for(j=1;c1[j]!=-1;j++)
  {
      a1[i+j-1]+=an[i]*c1[j];
  }
  for(i=1;i<=20;i++)
  {
      a1[i+1]+=a1[i]/10;
      a1[i]%=10;
    // cout<<a1[i];
  }
  //cout<<endl;
  i=30;
  while(a1[i]==ans[i])
  {  i--;
  }

  if(a1[i]<ans[i])
  { //cout<<"fuck"<<i<<endl;
      for(j=i;j>=1;j--)
         ans[j]=a1[j];
  }

}
int main()
{    int i,j;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n;
        init();
      memset(ans,0,sizeof(ans));
      ans[29]=9;
     for(i=1;i<=n;i++)
         for(j=i+1;j<=n;j++)
     {   int c=gcd(b[i],b[j]);
     int k=1;
     int x,y;
     x=b[i];y=b[j];
     x/=c;y/=c;
        while(c)
        {c1[k]=c%10;
        c/=10;
        k++;
        }
        c1[k]=-1;

        k=1;
        while(x)
        {afgcd[k]=x%10;
        x/=10;
        k++;
        }
        afgcd[k]=-1;

        k=1;
        while(y)
        {bfgcd[k]=y%10;
        y/=10;
        k++;
        }
        bfgcd[k]=-1;
        solve() ;

     }
     i=30;
    while(ans[i]==0)
    {
        i--;
    }
    for(j=i;j>=1;j--)
       cout<<ans[j];
    cout<<endl;




       }
    return 0;
}
