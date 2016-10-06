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
#include <ctime>
typedef long long ll;
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

const int maxn = 2005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, m;
int val[maxn], num[maxn], vis[maxn];

void solve()
{
    sa(n), sa(m);
    repp(i, 1, n)
    {
        sa(val[i]);
        if (val[i] <= m)
        {
            num[val[i]]++;
        }
    }
    int k = n / m;
    int v = n%m;
    int ans = 0;

    repp(i, 1, m)
    {
        repp(j, 1, n)
        {
            if (num[i] >= k)continue;
            if ((val[j] > m) || (num[val[j]] > k))
            {
                ans++;
                if (val[j] > m)
                {
                    val[j] = i;
                }
                else
                {
                    num[val[j]]--;
                    val[j] = i;
                }
                num[i]++;
            }
        }
    }

    printf("%d %d\n", k, ans);
    repp(i, 1, n)
    {
        printf("%d ", val[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE  
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
    solve();
    return 0;
}