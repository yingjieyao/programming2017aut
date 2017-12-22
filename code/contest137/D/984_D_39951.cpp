#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1010;
const int M = 100010;
typedef long long ll;
int n, m, fa[N];
struct Node
{
    int  a,b,d;
}eg[M];

int cmp(Node x, Node y)
{
    return x.d < y.d;
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int kruskal()
{
    int now = 0;
    sort(eg,eg+1+m,cmp);
    double ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (now==n-1)
            break;
        int x = find(eg[i].a), y = find(eg[i].b);
        if (x != y)
        {
            fa[x] = y;
            ans += eg[i].d;
            now++;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    while (!((n==0) && (m==0)))
    {
        for (int i=1;i<=n;i++)
            fa[i]=i;
        for (int i=1;i<=m;i++)
        {
            int x,y,t;
            scanf("%d%d%d",&x,&y,&t);
            eg[i].a=x;
            eg[i].b=y;
            eg[i].d=t;
        }
        printf("%d\n", kruskal());
        scanf("%d%d",&n,&m);
    }
    return 0;
}
