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

const int maxn = 8000;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, cnt;
string x;
map<string, int>hax;
int edge[maxn][maxn];
int in[maxn], vis[maxn];

void cal()
{
    int len = x.length();

    int i, j;
    string t = "";
    for (i = 0; i < len; i++)
    {
        if (x[i] == '=')
        {
            break;
        }
        t = t + x[i];
    }
    if (hax[t] == 0)
    {
        cnt++;
        hax[t] = cnt;
    }

    int en = hax[t];
    for (j = i + 1; j < len; j++)
    {
        if (x[j] == '(')
        {
            break;
        }
    }
    if (x[j] == '('&&x[j + 1] == ')')
    {
        in[hax[t]] = 0;
        return;
    }
    int cur = j + 1;
    while (cur < len)
    {
        string s = "";
        int nx = cur;
        for (nx = cur; nx < len; nx++)
        {
            if (x[nx] == ',')
            {
                break;
            }
            if (x[nx] == ')')
            {
                break;
            }
            s = s + x[nx];
        }
        if (s != ""&&hax[s] == 0)
        {
            cnt++;
            hax[s] = cnt;
        }
        if (s != "")
        {
            if (edge[hax[s]][hax[t]] == 0)
            {
                edge[hax[s]][hax[t]] = 1;
                if (in[hax[t]] == -1)
                {
                    in[hax[t]] = 1;
                }
                else
                {
                    in[hax[t]]++;
                }
            }
        }
        if (x[nx] == ')')
        {
            break;
        }
        cur = nx + 1;
    }
}

void solve()
{
    cin >> n;
    cnt = 0;
    hax.clear();
    mem(edge, 0);
    mem(in, -1);
    mem(vis, 0);
    repp(i, 1, n)
    {
        cin >> x;
        cal();
    }
    //cout << cnt << endl << endl;
    int f = 1;
    repp(i, 1, cnt)
    {
        if (in[i] == -1)
        {
            puts("BAD");
            return;
        }
    }
    //cout << cnt << endl << endl;
    repp(i, 1, cnt)
    {
        int m = 0;
        int loc = 0;
        repp(j, 1, cnt)
        {
            if (in[j] == 0 && !vis[j])
            {
                m++;
                loc = j;
                break;
            }
        }
        if (m == 0)
        {
            puts("BAD");
            return;
        }
        vis[loc] = 1;
        repp(k, 1, cnt)
        {
            if (edge[loc][k] == 1)
            {
                edge[loc][k] = 0;
                in[k]--;
            }
        }
    }
    puts("GOOD");
}

int main()
{
#ifndef ONLINE_JUDGE  
    freopen("C-large.in", "r", stdin);
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