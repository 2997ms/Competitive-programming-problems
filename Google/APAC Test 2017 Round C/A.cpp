//#pragma comment(linker, "/STACK:102400000,102400000") 
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

const int maxn = 30;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

char x[5];
double res;
int val[maxn][maxn], num[maxn][maxn];
int ri, ci, ste, sx, sy;
double p, q;

void dfs(int x, int y, int step,double r)
{
    if (step < 0)
    {
        res = max(r, res);
        return;
    }
    if (step != ste)
    {
        if (val[x][y])
        {
            double a = 1;
            repp(i, 1, num[x][y])
            {
                a *= (1 - p);
            }
            r += a*p;
        }
        else
        {
            double a = 1;
            repp(i, 1, num[x][y])
            {
                a *= (1 - q);
            }
            r += a*q;
        }
        num[x][y]++;
    }

    if (x + 1 <= ri)
    {
        dfs(x + 1, y, step - 1, r);
    }
    if (y + 1 <= ci)
    {
        dfs(x, y+1, step - 1, r);
    }

    if (y - 1 >= 1)
    {
        dfs(x, y - 1, step - 1, r);
    }
    /*
    if (x == 10 && y == 3 && step == 3)
    {
        step++;
        step--;
    }*/
    if (x - 1 >= 1)
    {
        dfs(x-1, y, step - 1, r);
    }
    if(step != ste)num[x][y]--;
}

void solve()
{
    cin >> ri >> ci >> sx >> sy >> ste;
    cin >> p >> q;
    sx++, sy++;
    mem(val, 0);
    mem(num, 0);
    repp(i, 1, ri)
    {
        repp(j, 1, ci)
        {
            scanf("%s", x);
            if (x[0] == '.')
            {
                val[i][j] = 0;
            }
            else
            {
                val[i][j] = 1;
            }
        }
    }
    res = 0;
    dfs(sx, sy, ste, 0);
    printf("%.8lf\n", res);
}
int main()
{
#ifndef ONLINE_JUDGE  
    freopen("A-large.in", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    repp(i, 1, t)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}