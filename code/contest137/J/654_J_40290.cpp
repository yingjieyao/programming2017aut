#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
map <string,string> ma;
int m,n;
char a[1050],b[1050];
int main()
{
    scanf("%d %d",&m,&n);
    getchar();
    for(int i=1;i<=m;i++)
    {
        string as,bs;
        cin.getline(a,100);
        cin.getline(b,100);
        as=a;
        bs=b;
        //cout<<as<<endl<<bs<<endl;
        for(int i=0;i<as.size();i++)
        {
            if(as[i]>='A'&&as[i]<='Z')
            {
                as[i]=as[i]-'A'+'a';
            }
        }
        ma[as]=bs;
    }
    for(int i=1;i<=n;i++)
    {
        string as;
        cin.getline(a,100);
        as=a;
        for(int i=0;i<as.size();i++)
        {
            if(as[i]>='A'&&as[i]<='Z')
            {
                as[i]=as[i]-'A'+'a';
            }
        }
        if(ma.find(as)!=ma.end())
        {
            cout<<ma[as]<<endl;
        }
        else
        {
            cout<<"What are you saying?"<<endl;
        }
    }
    return 0;
}
