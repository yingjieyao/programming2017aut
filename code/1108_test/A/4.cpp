i#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
using namespace std;

stack<int> s;
int ans[1024];

bool in(int n)
{
    memset(ans, 0, sizeof(ans));
    int t, cnt = 1;
    cin >> t;
    if (t == 0)
        return false;
    else
    {
        ans[cnt++] = t;
        while (cnt <= n)
            cin >> ans[cnt++];
    }
    return true;
}

bool check(int n)
{
    int i = 1, x = 1;
    while (i <= n)
    {
        if (x == ans[i])
        {
            x++;
            i++;
        }
        else if (!s.empty() && s.top() == ans[i])
        {
            i++;
            s.pop();
        }
        else if (x <= n)
            s.push(x++);
        else
            return false;
    }
    return true;
}

int main()
{
    int N;
    while (cin >> N && N != 0)
    {
        while (in(N))
        {
            if (check(N))
                puts("Yes");
            else
                puts("No");
        }
        putchar('\n');
    }
}
