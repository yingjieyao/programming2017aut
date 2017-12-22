#include <stdio.h>
#include <stdlib.h>

char ask[200][200],ans[200][200],qur[200];
int m,n,flag=0;
int seek()
{
    int i,j;
    for(i=0;i<m;i++)
    {
        j=0;
        flag=0;
        while(ask[i][j]!='\0'&&qur[j]!='\0'&&!flag)
        {
            if(ask[i][j]>='A'&&ask[i][j]<='Z')
            {
                if(ask[i][j]==qur[j]||ask[i][j]==qur[j]-('a'-'A')) j++;
                else  flag=1;
            }
           if(ask[i][j]>='a'&&ask[i][j]<='z')
           {
               if(ask[i][j]==qur[j]||ask[i][j]==qur[j]+('a'-'A')) j++;
               else flag=1;
           }
           else
           {
               if(ask[i][j]==qur[j])  j++;
               else flag=1;
           }
        }
        if(flag==0) return i;
    }
    return -1;
}
int main()
{
    int i;
    scanf("%d%d",&m,&n);
    getchar();
    for(i=0;i<m;i++)
    {
        gets(ask[i]);
        gets(ans[i]);
    }
    for(i=0;i<n;i++)
    {
        gets(qur);
        if (seek()==-1)
            printf("What are you saying?\n");
        else
        {
            puts(ans[seek()]);
        }
    }
    return 0;
}
