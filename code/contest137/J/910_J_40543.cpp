#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int n,m;
int cnt=0;
int u;
int main()
{
    char qu[100][100];
    char an[100][100];
    int m,n;
    scanf("%d%d",&m,&n);
    int i,j;
    getchar();
    for(i=0;i<m;i++)
    {
        char temp[100];
        gets(temp);
        for(j=0;j<100;j++) qu[i][j]=temp[j];
        gets(temp);
        for(j=0;j<100;j++) an[i][j]=temp[j];
    }
  char str[100];
    for(i=0;i<n;i++)
    {
        gets(str);
        int flag=0;
        char temp[100];
        for(j=0;j<n;j++)
        {
            for(int k=0;k<100;k++)
            {
                temp[k]=qu[j][k];
            }
            if(strcmp(str,temp)==0)
            {
                cout<<an[j]<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0) printf("What are you saying?\n");
    }
    return 0;
}
