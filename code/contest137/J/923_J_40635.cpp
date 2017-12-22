#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char qq[111],q[111][111],a[111][111];
unsigned int n,m;

int judge()
{  unsigned int j,i;
   for(i=0;i<n;i++)
   {
       if(strlen(qq)!=strlen(q[i])){continue;}
       for(j=0;j<strlen(qq);j++)
       {   int tmp=abs(qq[j]-'A'-q[i][j]+'A');
           if(tmp!=0&&tmp!=32)break;
       }
       if(j==strlen(qq))return i;
   }
   return -1;
}
int main()
{
   unsigned int i;
scanf("%d %d",&n,&m);
getchar();
for(i=0;i<n;i++)
{
    gets(q[i]);
    gets(a[i]);
}
for(i=0;i<m;i++)
    {
        gets(qq);

            int k=judge();
                if(k==-1)
                printf("What are you saying?\n");
                else puts(a[k]);
    }
    return 0;
}
