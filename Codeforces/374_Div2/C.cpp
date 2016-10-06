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

const int maxn = 5005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

struct ed
{
    int to;
    int tim;
    int next;
}edge[maxn];

int n, m, T;
int cnt;
int head[maxn], vis[maxn];
int dp[maxn][maxn], pre[maxn][maxn];

void init()
{
    cnt = 0;
    memset(edge, -1, sizeof(edge));
    memset(dp, 0x3f, sizeof(dp));
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int w)
{
    cnt++;
    edge[cnt].to = v;
    edge[cnt].tim = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void cal(int x)
{
    if (vis[x])
        return;
    vis[x] = 1;
    if (x == n)
    {
        dp[x][1] = 0;
    }
    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        int nxt = edge[i].to;
        int t = edge[i].tim;
        cal(nxt);
        for (int j = 1; j <= n; j++)
        {
            if (dp[x][j] > t + dp[nxt][j - 1])
            {
                dp[x][j] = t + dp[nxt][j - 1];
                pre[x][j] = nxt;
            }
        }
    }
}
void prin(int x,int num)
{
    if (x == n || num == 1)
    {
        //printf("%d\n", n);
        return;
    }
    printf("%d ", pre[x][num]);
    prin(pre[x][num], num - 1);
}

void solve()
{
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    cal(1);
    int i;
    for (i = n; i >= 1; i--)
    {
        if (dp[1][i] <= T)
        {
            break;
        }
    }
    printf("%d\n", i);
    printf("1 ");
    prin(1,i);
}

int main()
{
    init();
    solve();
    return 0;
}