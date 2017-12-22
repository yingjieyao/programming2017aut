#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
char que[100][100];
char ans[100][100];
int n,m;

int findd(char a[])
{
    for(int i=0;i<n;i++){
        if(!strcmp(a,que[i])) return i;
    }
    return -1;
}

void input(char str[])
{
    int i=0;
    char a;
    while(1)
    {
        a=getchar();
        if(a=='\n'){
            str[i]='\0';
            return ;
        }
        str[i++]=a;
    }
}

int main()
{
    //freopen("text.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        getchar();
        for(int i=0;i<n;i++){
            input(que[i]);
            input(ans[i]);
        }
        for(int i=0;i<m;i++) {
            char a[100];
            input(a);
            int k=findd(a);
            if(k!=-1) printf("%s\n",ans[k]);
            else printf("What are you saying?\n");
        }
    }
    return 0;
}
