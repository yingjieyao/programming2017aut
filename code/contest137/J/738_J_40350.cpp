#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;
map<string,string>q;
int n,m;
string a,b,c,d;
int main(){
    scanf("%d%d",&m,&n);getchar();
    for (int i=1;i<=2*m;i+=2){
    getline(cin,a);getline(cin,b);
    int z=a.length();
    for (int j=0;j<z;j++)if (a[j]>='A'&&a[j]<='Z')a[j]='a'+a[j]-'A';
    q[a]=b;
    }
    while (n--){
    getline(cin,c);
    int z=c.length();
    for (int j=0;j<z;j++)if (c[j]>='A'&&c[j]<='Z')c[j]='a'+c[j]-'A';
    if (q.find(c)!=q.end())cout<<q[c]<<endl;
    else puts("What are you saying?");
    }
    //for(;;);
    return 0;
}
