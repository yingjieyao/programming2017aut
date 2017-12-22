#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct qa
{
    int q[110], flag;
    char a[110];
} QA;

QA tra[110];

int main()
{
    int m, n, i, j, k, c, c1, c2, tmp;
    scanf("%d%d",&m,&n);
     c = getchar();
    for ( i = 0; i < m; i++)
    {
        tra[i].flag = 1;
        for ( j = 0; j < 110; j++)
        {
            tra[i].a[j] = 0;
            tra[i].q[j] = 0;
        }
    }
    for ( i = 0; i < m; i++)
    {
        j = 0;
        while (1)
        {
            tra[i].q[j] = getchar();
            if ( tra[i].q[j] == '\n') break;
            j++;
        }
        j = 0;
        while (1)
        {
            tra[i].a[j] = getchar();
            if ( tra[i].a[j] == '\n') break;
            j++;
        }
    }
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < 110; j++) tra[j].flag = 1;
        j = 0;
        c = 0;
        while ( c != '\n')
        {
            c = getchar();
            if ( c >= 'a' && c <= 'z')
            {
                c1 = c - 'a' + 'A';
                c2 = c;
            }
            else if ( c >= 'A' && c <= 'Z')
            {
                c1 = c;
                c2 = c - 'A' + 'a';
            }
            else
            {
                c1 = c;
                c2 = c;
            }
            for ( k = 0; k < m; k++)
            {
                if ( tra[k].q[j] != c1 && tra[k].q[j] != c2) tra[k].flag = 0;
            }
            j++;
        }
        tmp = -1;
        for ( k = 0; k < m; k++)
            if ( tra[k].flag == 1)
            {
                tmp = k;
                break;
            }
        if ( tmp == -1) printf("What are you saying?\n");
        else
        {
            j = 0;
            while ( tra[tmp].a[j] != '\n')
            {
                printf("%c",tra[tmp].a[j]);
                j++;
            }
            printf("\n");
        }
    }
    return 0;
}
