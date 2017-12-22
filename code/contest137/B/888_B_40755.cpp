#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <bitset>
#include <ctime>

using namespace std;

#define pau system("pause")
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define clr(a, x) memset(a, x, sizeof(a))

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

ll a, b, c, d;
bool check(ll x) {
    return a * x * x * x + b * x + c > d;
}
int main() {
    while (~scanf("%lld%lld%lld%lld", &a, &b, &c, &d)) {
        ll s = -1000, e = 1000, mi, ans;
        while (s <= e) {
            mi = s + e >> 1;
            if (check(mi)) e = (ans = mi) - 1;
            else s = mi + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
