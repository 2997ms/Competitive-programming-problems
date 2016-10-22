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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)

const int maxn = 1e6+2;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, c;
int len[maxn], cnt[2*maxn];
vector<int>val[maxn];

void add(int x, int y)
{
    if (x >= c || x > y)return;
    cnt[x]++;
    cnt[y + 1]--;
}

void solve()
{
    sa(n), sa(c);
    repp(i, 1, n)
    {
        sa(len[i]);
        repp(k, 1, len[i])
        {
            int x;
            sa(x);
            val[i].push_back(x);
        }
    }
    for (int i = 1; i < n; i++)
    {
        int minn = min(len[i], len[i + 1]);
        int fl = 0;
        for (int j = 0; j < minn; j++)
        {
            if (val[i][j] == val[i + 1][j])continue;
            if (val[i][j]>val[i + 1][j])
            {
                add(c + 1 - val[i][j], c - val[i + 1][j]);
            }
            else
            {
                add(0, c - val[i + 1][j]);
                int le = val[i][j] - 2;
                add(c + 1 - val[i][j], c + 1 - val[i][j] + le);
            }
            fl = 1;
            break;
        }
        if (!fl&&len[i]>len[i + 1])
        {
            puts("-1");
            return;
        }
        else if (!fl)
        {
            add(0, c - 1);
        }
    }
    for (int i = 0; i < c; i++)
    {
        cnt[i] += cnt[i - 1];
        if (cnt[i] == n - 1)
        {
            printf("%d", i);
            return;
        }
    }
    puts("-1");
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