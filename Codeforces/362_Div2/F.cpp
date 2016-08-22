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

const int maxn = 1e6 + 10;
const double PI = acos(-1.0);
const ll mod = 20090717;
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }

struct ma
{
    int sz;
    ll val[215][215];
    ma() {};
    ma(int _n)
    {
        sz = _n;
        for (int i = 1; i <= sz; i++)
        {
            for (int j = 1; j <= sz; j++)
            {
                if (i == j)
                {
                    val[i][j] = 0;
                }
                else
                {
                    val[i][j] = -1;
                }
            }
        }
    }
};

ma res, tmp;
void mul(ma &a, ma &b)
{
    res.sz = a.sz;
    for (int i = 1; i <= res.sz; i++)
    {
        for (int j = 1; j <= res.sz; j++)
        {
            if (i == j)
            {
                res.val[i][j] = 0;
            }
            else
            {
                res.val[i][j] = -1;
            }
        }
    }

    for (int i = 1; i <= a.sz; i++)
    {
        for (int j = 1; j <= a.sz; j++)
        {
            for (int k = 1; k <= a.sz; k++)
            {
                if (a.val[i][k] == -1)continue;
                if (b.val[k][j] == -1)continue;

                res.val[i][j] = max(res.val[i][j], a.val[i][k] + b.val[k][j]);
            }
        }
    }
    for (int i = 1; i <= a.sz; i++)
    {
        for (int j = 1; j <= a.sz; j++)
        {
            a.val[i][j] = res.val[i][j];
        }
    }
}

struct AC_automation
{
#define Ni 1050
#define Mi 26
    int next[Ni][Mi], fail[Ni];
    ll end[Ni];
    int root, sz;
    int idx(char x)
    {
        return x - 'a';
    }
    int newnode()
    {
        sz++;
        for (int i = 0; i < Mi; i++)
        {
            next[sz][i] = -1;
        }
        end[sz] = 0;
        return sz;
    }
    void init()
    {
        sz = 0;
        root = newnode();
    }
    void insert(char s[], int len, int id)
    {
        int now = root;
        for (int i = 0; i < len; i++)
        {
            int c = idx(s[i]);
            if (next[now][c] == -1)
            {
                next[now][c] = newnode();
            }
            now = next[now][c];
        }
        end[now] += id;
    }
    void build()
    {
        queue<int>que;
        for (int i = 0; i < Mi; i++)
        {
            if (next[root][i] == -1)
            {
                next[root][i] = root;
            }
            else
            {
                fail[next[root][i]] = root;
                que.push(next[root][i]);
            }
        }
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            if (end[fail[now]])
            {
                end[now] += end[fail[now]];
            }
            for (int i = 0; i < Mi; i++)
            {
                if (next[now][i] == -1)
                {
                    next[now][i] = next[fail[now]][i];
                }
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    que.push(next[now][i]);
                }
            }
        }
    }
    ma getma()
    {
        ma res = ma(sz);
        for (int i = 1; i <= sz; i++)
        {
            for (int j = 0; j < Mi; j++)
            {
                res.val[i][next[i][j]] = end[next[i][j]];           
            }
        }
        return res;
    }
}ac;

int n;
ll k;
int val[205];
char x[205];
ma t;

void solve()
{
    ac.init();
    scanf("%d", &n);
    scanf("%lld", &k);
    repp(i, 1, n)
    {
        scanf("%d", &val[i]);
    }
    repp(i, 1, n)
    {
        scanf("%s", x);
        ac.insert(x, strlen(x), val[i]);
    }
    ac.build();
    t = ac.getma();
    tmp.sz = t.sz;
    for (int i = 1; i <= tmp.sz; i++)
    {
        for (int j = 1; j <= tmp.sz; j++)
        {
            if (i == j)
            {
                tmp.val[i][j] = 0;
            }
            else
            {
                tmp.val[i][j] = -1;
            }
        }
    }
    while (k)
    {
        if (k & 1)
        {
            mul(tmp, t);
        }
        mul(t, t);
        k >>= 1;
    }
    ll ans = 0;
    for (int i = 1; i <= t.sz; i++)
    {
        ans = max(ans, tmp.val[1][i]);
    }
    printf("%lld", ans);
}

int main()
{
    solve();
    return 0;
}