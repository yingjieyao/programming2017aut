#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int e[100001],b[100001],d[100001];
int f[10001];
int n,m;
int father(int n)
{  if(f[n]==n) return n;
  return f[n]=father(f[n]);
}
void sort1(int l,int r)
{
      int i=l,j=r,mid=d[(l+r)/2];
      while(i<=j)
      {
          while(d[i]<mid) i++;
          while(d[j]>mid) j--;
          if(i<=j)
          {
           swap(e[i],e[j]);
           swap(b[i],b[j]);
           swap(d[i],d[j]);
           i++;j--;
          }
      }

    if(l<j) sort1(l,j);
    if(i<r) sort1(i,r);


}
int main()
{   int i,j;
    while(cin>>n>>m)
    {

        int sum=0;
        if(!n&&!m) break;
        for(i=1;i<=n;i++)
            f[i]=i;
        for(i=1;i<=m;i++)

            cin>>b[i]>>e[i]>>d[i];
    sort1(1,m);
    //cout<<"fuck"<<endl;
      for(i=1;i<=m;i++)
      {
          int x,y;
          x=father(e[i]);
          y=father(b[i]);
          if(x!=y)
          {
              sum+=d[i];
              f[x]=y;
          }
      }

     cout<<sum<<endl;



    }




    return 0;
}
