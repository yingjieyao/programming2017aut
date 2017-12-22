#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
typedef struct QA
{
    char a[102];
    char b[102];
} QA;
QA bot[101];
int i,j;
int n,m;
int main()
{
    int m,n;
    cin>>m>>n;
    char vd[102];
    getchar();
    for(i=1; i<=m; i++)
    {

        gets(bot[i].a);
        gets(bot[i].b);

    }
    int flag=0;
    while(n--)
    {
        flag=0;
        gets(vd);
        for(i=1; i<=m; i++)
        {
            for(j=1; j<min(strlen(bot[i].a),strlen(vd)); j++)
            {
                if(vd[j]==bot[i].a[j])
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
           if(flag==1)
            {
                cout<<bot[i].b<<endl;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"What are you saying?"<<endl;
        }

    }
    return 0;
}
