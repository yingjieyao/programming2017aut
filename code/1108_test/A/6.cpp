#include <stdio.h>

int main()
{
    int n, num[1005], Stack[1005], top = -1, nCount = -1, index, l;
    while(scanf("%d", &n )&& n != 0)
    {
        l = 0;
        index = 0;
        nCount = -1;
        top = -1;
        while(scanf("%d", &num[++nCount]) && num[0] != 0)
        {
            index++;
            if (index == num[nCount])
            {
                l++;
            }
            else
            {
                Stack[++top] = index;
            }
            for (int i = 1; i < n; i++)
            {
                scanf("%d", &num[++nCount]);
                Stack[++top] = ++index;
                while(num[l] == Stack[top] && top >= 0)
                {
                    top--;
                    l++;
                }
            }
            if (top == -1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
            index = 0;
            nCount = -1;
            top = -1;
            l = 0;
        }
        printf("\n");
    }
    return 0;
}
