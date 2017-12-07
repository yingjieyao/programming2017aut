// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/27 22时42分25秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//
#include <stdio.h>
#include <stdlib.h>

double min ( double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int j, k;
    int N;
    int V;
    while ( ~scanf("%d %d", &V, &N) && (V != 0  || N!=0))
    {
        double dp[10005];
        int vo[10005];
        double va[10005];
        for (j = 0; j <= V; j++)
        {
            dp[j] = 1;
        }
        for (j = 0; j < N; j++)
        {
            scanf ("%d %lf", &vo[j], &va[j]);
            va[j] = 1.0 - va[j];
        }
        //dp[vo[0]] = va[0];
        double tmp;
        for (j = 0; j < N; j ++)
        {
            for (k = V; k >= vo[j]; k--)
            {
                tmp = dp[k-vo[j]] * va[j];
                dp[k] = min( tmp , dp[k]);
            }
        }
        tmp = (1.0 - dp[V]) * 100.0;

        printf("%.1lf%%\n", tmp);

    }

    return 0;
}
