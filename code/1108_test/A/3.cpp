#include<cstdio>
#include<string.h>
#include<stack>
using namespace std;
const int MAXN = 1010;

stack<int> s;
int train[MAXN];

int main()
{
    int N;
    while(~scanf("%d",&N) && N)
    {
        while(scanf("%d",&train[1]) && train[1])
        {
            for(int i = 2; i <= N; i++)
                scanf("%d",&train[i]);
            int B = 1;
            for(int i = 1; i <= N; i++)
            {
                s.push(i);
                while(!s.empty() && s.top() == train[B])
                {
                    s.pop();
                    B++;
                }
            }

            if(B == N+1)
                printf("Yes\n");
            else
                printf("No\n");
            memset(train,0,sizeof(train));
        }
        printf("\n");
    }

    return 0;
}
