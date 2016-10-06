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

int n, m, k;
int flag;
int cnt;
char x[150][150];
int vis[150][150];
map<int, int>hax;
vector<pair<int, int>>lak;

int dfs(int i, int j,int d)
{
    if (i == 1 || i == n || j == 1 || j == m)
    {
        flag = 1;
        return 0;
    }
    vis[i][j] = d;
    int num = 0;
    if (x[i + 1][j] == '.'&&!vis[i + 1][j])
    {
        num += dfs(i + 1, j,d);
    }
    if (x[i - 1][j] == '.'&&!vis[i - 1][j])
    {
        num += dfs(i - 1, j,d);
    }
    if (x[i][j+1] == '.'&&!vis[i][j+1])
    {
        num += dfs(i, j + 1,d);
    }
    if (x[i][j-1] == '.'&&!vis[i][j-1])
    {
        num += dfs(i, j - 1,d);
    }
    return num + 1;
}

void solve()
{
    sa(n), sa(m), sa(k);
    repp(i, 1, n)
    {
        scanf("%s", x[i] + 1);
    }
    cnt = 0;
    repp(i, 1, n)
    {
        repp(j, 1, m)
        {
            if (x[i][j] == '.'&&!vis[i][j])
            {
                flag = 0;//flag=1 pengbian
                cnt++;
                int sz = dfs(i, j, cnt);
                if (!flag)
                {
                    lak.push_back(make_pair(sz, cnt));
                }
            }
        }
    }
    sort(lak.begin(), lak.end());
    int sz = lak.size();
    int res = 0;
    rep(i, 0, sz - k)
    {
        res += lak[i].first;
        hax[lak[i].second] = 1;
    }
    printf("%d\n", res);
    repp(i, 1, n)
    {
        repp(j, 1, m)
        {
            if (x[i][j] == '*')
            {
                printf("%c", x[i][j]);
            }
            else if(hax[vis[i][j]])
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}
int main()
{
    solve();
    return 0;
}