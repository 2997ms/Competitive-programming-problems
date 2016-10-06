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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, m;
vector< pair<int, pair<int, int>> >val[maxn];
int vis[50], num[50];

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int len;
        scanf("%d", &len);
        for (int j = 0; j < len; j++)
        {
            int x;
            scanf("%d", &x);
            pair<int, pair<int, int>>tmp;
            tmp.first = i;
            tmp.second.first = j;
            tmp.second.second = len;
            val[x].push_back(tmp);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int res = 0;
        int le = 0;
        memset(vis, -1, sizeof(vis));
        memset(num, -1, sizeof(num));
        for (int k = 0; k < val[i].size(); k++)
        {
            int nth = val[i][k].first;
            int pos = val[i][k].second.first;
            int len = val[i][k].second.second;
            int ri = nth;
            if (k == 0 || nth > val[i][k - 1].first + 1)
            {
                le = nth;
            }
            else
            {
                for (int v = 1; v <= 40; v++)
                {
                    if (vis[v] == -1)continue;
                    int g = gcd(v, len);
                    if (pos%g != vis[v] % g)
                    {
                        le = max(le, num[v] + 1);
                    }
                }
            }
            res = max(res, ri - le + 1);
            vis[len] = pos;
            num[len] = nth;
        }
        printf("%d\n", res);
    }
}

int main()
{
    solve();
    return 0;
}