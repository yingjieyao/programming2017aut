#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, tmp, index;
    int N, cas;
    int arr[10];
    scanf("%d", &N);
    for (cas = 0; cas < N; ++cas)
    {
        for (i = 0; i < 10; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (i = 0; i < 10; i++)
        {
            tmp = arr[i];
            index = i;
            for (j = i + 1; j < 10; j++)
            {
                if (arr[j] < tmp)
                {
                    tmp = arr[j];
                    index = j;
                }
            }
            if (index != i)
            {
                tmp = arr[i];
                arr[i] = arr[index];
                arr[index] = tmp;
            }
        }

        printf("%d", arr[0]);
        for (i = 1; i < 10; i++)
        {
            printf(" %d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
