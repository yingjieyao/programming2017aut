#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
char a[200][200],b[200][200];
//string a[200],b[200];
int main()
{   int   i,j;
    int n,m;
     cin>>n>>m; getchar();
     for(i=1;i<=n;i++)
     {
         cin.getline(a[i],110);

         cin.getline(b[i],110);
         //puts(a[i]);
       //  puts(b[i]);
      // cout<<a[i];
     //  cout<<b[i];

     }
    for(i=1;i<=m;i++)
    {   int flag=0;
        char c[200];
        cin.getline(c,110);
        for(j=1;j<=n;j++)
        {
            if(strcmp(a[j],c)==0) {cout<<b[j]<<endl;flag=1;}
        }
        if(!flag) cout<<"What are you saying?"<<endl;
    }




    return 0;
}
