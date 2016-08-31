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
#define eps 1e-10
#define LL_INF 0x33ffffffffffffff
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

const int maxn = 505;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

ll n;
ll row[maxn], col[maxn];
ll val[maxn][maxn];

void solve()
{
    scanf("%lld", &n);
    if (n == 1)
    {
        scanf("%lld", &n);
        puts("1");
        return;
    }
    ll row = 1, col = 1;
    repp(i, 1, n)
    {
        repp(j, 1, n)
        {
            scanf("%lld", &val[i][j]);
            if (val[i][j] == 0)
            {
                row = i;
                col = j;
            }
        }
    }
    ll sum = 0;
    repp(i, 1, n)
    {
        if (i == row)continue;
        repp(j, 1, n)
        {
            sum += val[i][j];
        }
        break;
    }
    ll subsum = 0;
    repp(j, 1, n)
    {
        subsum += val[row][j];
    }
    if (subsum >= sum)
    {
        puts("-1");
        return;
    }
    else
    {
        val[row][col] = sum - subsum;
        repp(i, 1, n)
        {
            ll sub = 0;
            repp(j, 1, n)
            {
                sub += val[i][j];
            }
            if (sub != sum)
            {
                puts("-1");
                return;
            }
        }

        repp(j, 1, n)
        {
            ll sub = 0;
            repp(i, 1, n)
            {
                sub += val[i][j];
            }
            if (sub != sum)
            {
                puts("-1");
                return;
            }
        }
        ll sub = 0;
        repp(i, 1, n)
        {
            sub += val[i][i];
        }
        if (sub != sum)
        {
            puts("-1");
            return;
        }

        sub = 0;
        repp(i, 1, n)
        {
            sub += val[i][n - i + 1];
        }
        if (sub != sum)
        {
            puts("-1");
            return;
        }
        printf("%lld", val[row][col]);
    }
}
int main()
{
    solve();
    return 0;
}