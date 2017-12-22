#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int MAXN=1e5+5;
const int MAXM=1e6+5;
const int mod=1e5+5;
const int INF=1000000;
//const int dx[]={0,0,1,-1,1,1,-1,-1};
//const int dy[]={1,-1,0,0,1,-1,1,-1};
const int dx[]={1,0,-1,1};
const int dy[]={0,1,1,1};

int n,m;

char x[200][200],y[200][200],z[200];

int main(){
    scanf("%d%d",&n,&m); getchar();
    for(int i=1;i<=n;i++){
        gets(x[i]+1);
        gets(y[i]+1);
    }
    for(int i=1;i<=m;i++){
        gets(z+1);
        int len=strlen(z+1);
        int tag=0;
        for(int j=1;j<=n;j++){
            if (len!=strlen(x[j]+1)) continue;
            int kk=1;
            for(int k=1;k<=len;k++){
                if (x[j][k]==z[k]){
                    continue;
                }
                if ((('a'<=x[j][k] && x[j][k]<='z') || ('A'<=x[j][k] && x[j][k]<='Z')) && (('a'<=z[k] && z[k]<='z') || ('A'<=z[k] && z[k]<='Z'))){
                    if (abs(x[j][k]-z[k])==32){
                        continue;
                    }
                }
                kk=0; break;
            }
            if (kk==1) {tag=j; break;}
        }
        if (tag==0) puts("What are you saying?");
        else printf("%s\n",y[tag]+1);
    }
    return 0;
}
