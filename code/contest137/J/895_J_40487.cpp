#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char in[105][105],out[105][105],que[105];
int main()
{
    //freopen ("J.in","r",stdin);
    //freopen ("J.out","w",stdout);
    int n,m,i,j,k,len,flag;
    char c;
    scanf ("%d %d",&m,&n);
    c=getchar();
    for (i=1;i<=m;i++){
        gets(in[i]+1);
        len=strlen(in[i]+1);
        for (j=1;j<=len;j++)
            if (in[i][j]>='A' && in[i][j]<='Z') in[i][j]=in[i][j]-'A'+'a';
        gets(out[i]+1);
    }
    for (i=1;i<=n;i++){
        gets(que+1);
        len=strlen(que+1);
        flag=-1;
        for (j=1;j<=len;j++)
            if (que[j]>='A' && que[j]<='Z') que[j]=que[j]-'A'+'a';
        for (j=1;j<=m;j++){
            if (strcmp(que+1,in[j]+1)==0){
                flag=1;
                len=strlen(out[j]+1);
                for (k=1;k<=len;k++) cout<<out[j][k];
                cout<<endl;
            }
        }
        if (flag==-1) printf ("What are you saying?\n");
    }
    return 0;
}
