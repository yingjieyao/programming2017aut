#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int nn = 'A' - 'a';
char qq[101][101], ans[101][101], q[101][101];
int m, n;
bool cmp(char a[], char b[]){
    for(int i = 0; a[i] != '\0'&&b[i] != '\0'; i++)
        if(a[i] != b[i]&&a[i] + nn != b[i]&&a[i] - nn != b[i])
            return false;
    return true;
}
int main()
{
    scanf("%d%d",&n, &m);getchar();
    for(int i = 1; i <= m; i++){
        gets(qq[i]);
        gets(ans[i]);
        //printf("%s$$%s\n",qq[i],ans[i]);
    }
    for(int i = 1; i <= n; i++){
        gets(q[i]);
        //printf("%s$$\n",q[i]);
    }
    for(int i = 1; i <= n; i++){
        int flag = 1;
        for(int j = 1; j <= m; j++){
            if(cmp(q[i],qq[j])){
                printf("%s\n",ans[j]);
                flag = 0;
                break;
            }
        }
        if(flag) printf("What are you saying?\n");
    }
    return 0;
}
