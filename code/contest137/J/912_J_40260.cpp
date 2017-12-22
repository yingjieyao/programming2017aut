#include <stdio.h>
#include <string.h>

int main(void)
{
    int m, n, i, j, k, flag;
    char tmp[105];
    char q[105][105], a[105][105];

    scanf("%d%d", &m, &n);
    getchar();
    for (i = 1; i <= m; i++){
        gets(q[i]);
        gets(a[i]);
    }
    for (i = 1; i <= n; i++){
        gets(tmp);
        flag = 0;
        for (j = 1; j <= m; j++){
            if (strcmp(q[j], tmp) == 0){
                k = j;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("What are you saying?\n");
        else
            puts(a[k]);
    }
    return 0;
}
