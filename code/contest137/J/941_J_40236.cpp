#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m,i,j,flag;
char w[222][111];
char d[222][111];
char ch[111];
int main()
{
    scanf ("%d %d",&m,&n);
    getchar();
    for (i=0; i<m; i++)
    {
        gets(w[i]);
        strcpy(w[i+m],w[i]);
        if (w[i][0]>='a')
        {
            w[i][0]=w[i][0]-'a'+'A';
        }
        else
        {
            w[i][0]=w[i][0]-'A'+'a';
        }
        gets(d[i]);
        strcpy(d[i+m],d[i]);
    }
    for (i=0; i<n; i++)
    {
        gets(ch);
        flag=0;
        for (j=0; j<2*m; j++)
        {
            if (strcmp(ch,w[j])==0)
            {
                printf ("%s\n",d[j]);
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            printf ("What are you saying?\n");
        }
    }
    return 0;
}
