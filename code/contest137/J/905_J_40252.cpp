#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int m,n;

struct node
{
   char arr[111],brr[111];
}p[111];

void change(char arr[],int len)
{
    int i=0;
    for(i=0;i<len;i++)
    {
        if(arr[i]>='A'&&arr[i]<='Z')
        {
            arr[i]+='a'-'A';
        }
    }
}

int main()
{
    scanf("%d%d",&m,&n);
    getchar();
    int i,j,co=0;
    char ans[111];
    int c;
    for(i=0;i<m;i++)
    {
        gets(p[i].arr);
        gets(p[i].brr);
        int len1=strlen(p[i].arr);
        change(p[i].arr,len1);
    }
    for(j=0;j<n;j++)
    {
        gets(ans);
        int len2=strlen(ans);
        change(ans,len2);
        co=0;
        for(i=0;i<n;i++)
        {
            if(strcmp(ans,p[i].arr)==0)
            {
                printf("%s\n",p[i].brr);
                co=1;
                break;
            }
        }
        if(co==0)
        {
            printf("What are you saying?\n");
        }
    }
    return 0;
}
