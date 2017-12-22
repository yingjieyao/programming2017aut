#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

struct note
{
    char str1[105];
    char str2[105];
} Note[105];
int main()
{
    //int eee=strcmp("W","w");
    //printf("eeee%d\n",eee);
    char s[105];
    int flag=0,m,n;
    scanf("%d%d",&m,&n);
    getchar();
    for(int i=0; i<m; i++)
    {
        gets(Note[i].str1);
        gets(Note[i].str2);
    }
    for(int j=0; j<n; j++)
    {
        flag=0;
        gets(s);
        for(int i=0; i<m; i++)
        {

            if(!strcmp(s+1,Note[i].str1+1))
            {
                puts(Note[i].str2);
                flag=1;
                break;
            }
        }
        if(!flag)
        {


            puts("What are you saying?");
        }


    }

    //cout << "Hello world!" << endl;
    return 0;
}
