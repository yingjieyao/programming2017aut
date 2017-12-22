#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<queue>
using namespace std;

const int Maxn=100010;
int dp[Maxn][30],num[Maxn][30];
int n;

int main()
{
    scanf("%d",&n);
    while (n!=0)
    {
        memset(dp,-1,sizeof(dp));
        memset(num,0,sizeof(num));
        int imaxt=-1;
        for (int i=1;i<=n;i++)
        {
            int x,t,w;
            scanf("%d%d%d",&x,&t,&w);
            num[t][x]+=w;
            imaxt=max(imaxt,t);
        }
        //sort(arr+1,arr+1+n,cmp);
        dp[0][10]=0;
        for (int i=1;i<=imaxt;i++)
        {
            for (int j=0;j<=20;j++)
            {
                if (dp[i-1][j]!=-1)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+num[i][j]);
                if ((j!=0) && dp[i-1][j-1]!=-1)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+num[i][j]);
                if ((j!=20) && dp[i-1][j+1]!=-1)
                    dp[i][j]=max(dp[i][j],dp[i-1][j+1]+num[i][j]);
            }
        }
        int ans=-1;
        for (int i=0;i<=20;i++)
            ans=max(ans,dp[imaxt][i]);
        printf("%d\n",ans);
        scanf("%d",&n);
    }
}
