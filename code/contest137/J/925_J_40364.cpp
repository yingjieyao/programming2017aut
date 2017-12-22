#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,m,i,j,flag;
    char arr[101][101];
    char brr[101][101];
    char crr[101];
    scanf("%d %d",&n,&m);
    getchar();
    for(i=0; i<n; i++)
    {
        gets(arr[i]);
        gets(brr[i]);
        for(j=0; j<strlen(arr[i]); j++)
        {
            if(arr[i][j]<='z'&&arr[i][j]>='a')arr[i][j]=arr[i][j]-'a'+'A';
        }
    }
    for(i=0; i<m; i++)
    {
        flag=1;
        gets(crr);
        for(j=0; j<strlen(crr); j++)
        {
            if(crr[j]<='z'&&crr[j]>='a')crr[j]=crr[j]-'a'+'A';
        }
        for(j=0; j<n; j++)
        {
            if(strcmp(arr[j],crr)==0)
            {
                printf("%s\n",brr[j]);
                flag=0;
            }

        }
        if(flag==1)printf("What are you saying?\n");
    }

}
