#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>//a 97 A 65
int comp(char a[],char b[])//相同为0
{
    int n,i,flag=0;
    if(strlen(a)!=strlen(b)) return 1;
    n=strlen(a);
    for(i=0;i<n;++i)
    {
        if(a[i]!=b[i])
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                if(a[i]+32!=b[i])
                {
                    flag=1;
                    break;
                }
            }
            else if(a[i]>='a' && a[i]<='z')
            {
                if(a[i]-32!=b[i])
                {
                    flag=1;
                    break;
                }
            }
        }
    }
    return flag;
}
int main()
{
    char a[101][101],b[101][101],s[101];
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    gets(s);
    for(i=0;i<m;++i)
    {
        gets(a[i]);//printf("%s\n",a[i]);
        gets(b[i]);//printf("%s\n",b[i]);
    }
    for(i=0;i<n;++i)
    {
        gets(s);//printf("%s\n",s);
        int fg=0;
        for(j=0;j<m;++j)
        {
            if(!comp(a[j],s))
            {
                fg=1;
                printf("%s\n",b[j]);
            }
        }
        if(!fg) printf("What are you saying?\n");
    }
    return 0;
}
