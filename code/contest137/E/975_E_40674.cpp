#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[200][200],brr[200][200];
int m,n;
void a(int x,int y)
{
    if(x>0)
    {
        if(arr[x-1][y]=='@')
        {
            arr[x-1][y]='#';
            a(x-1,y);
        }
    }
    if(x<m)
    {
        if(arr[x+1][y]=='@')
        {
            arr[x+1][y]='#';
            a(x+1,y);
        }
    }
    if(y>0)
    {
        if(arr[x][y-1]=='@')
        {
            arr[x][y-1]='#';
            a(x,y-1);
        }
    }
    if(y<n)
    {
        if(arr[x][y+1]=='@')
        {
            arr[x][y+1]='#';
            a(x,y+1);
        }
    }
    return;
}
void b(int x,int y)
{
    if(x>0)
    {
        if(brr[x-1][y]=='@')
        {
            brr[x-1][y]='#';
            b(x-1,y);
        }
    }
    if(x<m)
    {
        if(brr[x+1][y]=='@')
        {
            brr[x+1][y]='#';
            b(x+1,y);
        }
    }
    if(y>0)
    {
        if(brr[x][y-1]=='@')
        {
            brr[x][y-1]='#';
            b(x,y-1);
        }
    }
    if(y<n)
    {
        if(brr[x][y+1]=='@')
        {
            brr[x][y+1]='#';
            b(x,y+1);
        }
    }
    if(x>0&&y>0)
    {
        if(brr[x-1][y-1]=='@')
        {
            brr[x-1][y-1]='#';
            b(x-1,y-1);
        }
    }
    if(x>0&&y<n)
    {
        if(brr[x-1][y+1]=='@')
        {
            brr[x-1][y+1]='#';
            b(x-1,y+1);
        }
    }
    if(x<m&&y>0)
    {
        if(brr[x+1][y-1]=='@')
        {
            brr[x+1][y-1]='#';
            b(x+1,y-1);
        }
    }
    if(x<m&&y<n)
    {
        if(brr[x+1][y+1]=='@')
        {
            brr[x+1][y+1]='#';
            b(x+1,y+1);
        }
    }
    return;
}
int main()
{
    int i,j,k,c,d,t,p;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d %d",&m,&n);
        c=0;
        d=0;
        for(i=0; i<m; i++)
        {
            scanf("%s",arr[i]);
            strcpy(brr[i],arr[i]);
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i][j]=='@')
                    {
                        arr[i][j]='#';
                        a(i,j);
                        c++;
                    }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(brr[i][j]=='@')
                    {
                        brr[i][j]='#';
                        b(i,j);
                        d++;
                    }
            }
        }
        printf("%d %d\n",c,d);
    }
    return 0;
}
