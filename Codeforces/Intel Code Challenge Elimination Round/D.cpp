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

const int maxn = 5e4 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n;
int val[maxn];
map<int, int>hax;
priority_queue<int>que;

void solve()
{
    scanf("%d", &n);
    repp(i, 1, n)
    {
        scanf("%d", &val[i]);
        hax[val[i]] = 1;
        que.push(val[i]);
    }
    while (true)
    {
        int t = que.top();
        que.pop();

        int p = t;
        while (t&&hax[t])
        {
            t = t / 2;
        }
        if (t == 0)
        {
            break;
        }
        hax[p] = 0;
        hax[t] = 1;
        que.push(t);
    }
    for (auto it : hax)
    {
        if (it.second == 1)
        {
            cout << it.first << " ";
        }
    }
}

int main()
{
    solve();
    return 0;
}