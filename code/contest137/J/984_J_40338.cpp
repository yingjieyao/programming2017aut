#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<string.h>
using namespace std;

map<string,string> ma;

int m,n;
string str,str1,str2;

int main()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++)
    {
        char c=getchar();
        str2.clear();
        str1.clear();
        while (isspace(c))
            c=getchar();
        while (c!='\n')
        {
            if (c>='A' && c<='Z')
                c=c-'A'+'a';
            str1+=c;
            c=getchar();
        }
        while (isspace(c))
            c=getchar();
        while (c!='\n')
        {
            str2+=c;
            c=getchar();
        }
        ma[str1]=str2;
        //cout<<str1<<" "<<ma[str1]<<endl;
    }
    for (int i=1;i<=n;i++)
    {
        char c=getchar();
        while (isspace(c))
            c=getchar();
        str.clear();
        while (c!='\n' && c!=EOF)
        {
            if (c>='A' && c<='Z')
                c=c-'A'+'a';
            str+=c;
            c=getchar();
        }
        //cout<<str<<endl;
        if (ma.find(str)==ma.end())
            puts("What are you saying?");
        else
            cout<<ma[str]<<endl;
    }
}
