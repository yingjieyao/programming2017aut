#include <stdio.h>
#include <stdlib.h>
int arr[501];
int cmp(const void *x,const void *y)
{
    return *(int *)x > *(int *)y;
}

int find(int x,int y,int time)
{
    int d = x > y ? x : y;
    int sum = 0;
    int number = 0;
    while (sum != 2)
    {
        if (number > time)
        {
            number = time;
            break;
        }
        sum = 0;
        number += d;
        if(number % x == 0) sum ++;
        if(number % y == 0) sum ++;
    }
    return number;
}
int min(int x,int y)
{
    return x < y ? x : y;
}
int main()
{
    //freopen ("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while (T --)
    {
        int n;
        scanf("%d",&n);
        int i;
        for (i = 1;i <= n;i ++)
        {
            scanf("%d",&arr[i]);
        }
        qsort(arr + 1,n,sizeof(arr[0]),cmp);
        int j;
        int time = 1000000001;
        for (i = 1;i < n;i ++)
        {
            for (j = i + 1;j <= n;j ++)
            {
                int x = find(arr[i],arr[j],time);
                time = min(x,time);
            }
        }
        printf("%d\n",time);
    }
    return 0;
}
