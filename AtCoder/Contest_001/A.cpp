#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pill;

#define eps 1e-10
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int maxn = 405;
const ll mod = 1000000007;
const double PI = acos(-1.0);

int n;
int val[maxn];

void solve()
{
    int res = 0;
    int i, j, k;
    repp(i, 1, 2 * n)
    {
        sa(val[i]);
    }
    sort(val + 1, val + 2*n + 1);
    for (i = 1; i <= 2 * n - 1; i = i + 2)
    {
        res += val[i];
    }
    printf("%d\n", res);
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        solve();
    }
    return 0;
}