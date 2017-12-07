// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  F.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/27 22时52分47秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[10000];
int dp[101][101];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    char end[20]="end";
    int n,i,j,k;
    while(~scanf("%s",arr)&&strcmp(arr, end) != 0)
    {
        n=strlen(arr);
        memset(dp,0,sizeof(dp));
        for(k=1; k<=n; k++)
        {
            for(i=0; i<n-k; i++)
             {
                if((arr[i]=='('&&arr[i+k]==')')||(arr[i]=='['&&arr[i+k]==']'))
                    dp[i][i+k]=2+dp[i+1][i+k-1];
                for(j=i; j<i+k; j++)
                    dp[i][i+k]=max(dp[i][i+k],dp[i][j]+dp[j+1][i+k]);
            }
        }
        printf("%d\n",dp[0][n - 1]);
    }
    return 0;
}
