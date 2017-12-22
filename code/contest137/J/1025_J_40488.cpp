#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

const int Maxn = 2e2;
map<char*,char*>M;
char str[Maxn][2][Maxn];

int main() {
    int n,q;
    while(~scanf("%d%d",&n,&q)) {
        M.clear();
        getchar();
        string st1,st2;
        for(int i = 1; i <= n; i++) {
            gets(str[i][0]);
            gets(str[i][1]);
        }

        for(int i = 1; i <= q; i++) {
            char str1[200];
            gets(str1);
            int flag = 0;
            int id;
            for(int j = 1; j <= n; j++) {
//                    printf("str1 = %s  str = %s\n",str1,str[j][0]);
                if(!strcasecmp(str1,str[j][0])) {
                    flag = 1;
                    id = j;
                    break;
                }

            }
            if(flag)
                printf("%s\n",str[id][1]);
            else
                printf("What are you saying?\n");

        }
    }

//            gets(str1);
//            puts(M[str1]);
//            printf("%s\n",M[str1]);
//            iter = M.find(st1);
//            if(iter!=M.end())
//            {
//                 cout << iter -> second << endl;
//            }
//            else
//            {
//                cout << "What are you saying?"<<endl;
//            }
//            cout << M.find(str1) << endl;
//            map<string,string> :: iterator iter;
//              cout << M[str1] << endl;
//            cout << iter -> second <<endl;
    return 0;
}
