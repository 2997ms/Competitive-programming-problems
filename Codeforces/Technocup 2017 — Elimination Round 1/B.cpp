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

const int maxn = 1e6 + 5;
const ll mod = 1000;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

char x[maxn];

void solve()
{
    scanf("%s", x + 1);
    ll res = 0;
    for (int i = 1; x[i]; i++)
    {
        if (isalpha(x[i]))continue;
        ll t = 0;
        int dot = -1;
        while (x[i]&&!isalpha(x[i]))
        {
            if (x[i] == '.')
            {
                dot = i;
            }
            else
            {
                t = t * 10 + x[i] - '0';
            }
            i++;
        }
        if (dot == -1 || i - dot == 4)
        {
            t *= 100;
        }
        res += t;
        i--;
    }
    if (res < 100)
    {
        printf("0.%02lld\n", res);
        return;
    }
    vector<int>r;
    while (res)
    {
        r.push_back(res % 10);
        res /= 10;
    }
    reverse(r.begin(), r.end());

    for (int i = 0; i < r.size()-2; i++)
    {
        printf("%d", r[i]);
        if ((r.size() - 2 - (i+1)) % 3 == 0 && i != r.size() - 3)
        {
            printf(".");
        }
    }
    if (r[r.size() - 1] == 0 && r[r.size() - 2] == 0)
    {
        return;
    }
    else
    {
        printf(".%d%d\n", r[r.size() - 2], r[r.size() - 1]);
    }
}

int main()
{
    solve();
    return 0;
}
