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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int app[30];
char x[maxn];

void solve()
{
    cin >> x + 1;
    int len = strlen(x + 1);

    if (len < 26)
    {
        puts("-1");
        return;
    }
    int f = 0;
    for (int i = 1; i <= len; i++)
    {
        if (i + 25>len)
        {
            break;
        }
        mem(app, 0);
        int cnt = 0;
        int q = 0, w = 0;
        for (int j = i; j <= len; j++)
        {
            cnt++;
            if (x[j] == '?')
            {
                q++;
                continue;
            }
            if (app[x[j] - 'A'])
            {
                break;
            }
            else
            {
                w++;
                app[x[j] - 'A'] = 1;
            }
            if (cnt == 26)
            {
                break;
            }
        }
        if (w + q == 26)
        {
            f = 1;
            int cnt = 0;
            for (int j = i; j <= len; j++)
            {
                cnt++;
                if (x[j] == '?')
                {
                    for (int y = 0; y < 26; y++)
                    {
                        if (app[y] == 0)
                        {
                            app[y] = 1;
                            x[j] = 'A' + y;
                            break;
                        }
                    }
                }
                if (cnt == 26)
                {
                    break;
                }
            }
            break;
        }
    }
    if (f == 0)
    {
        puts("-1");
    }
    else
    {
        for (int i = 1; i <= len; i++)
        {
            if (x[i] == '?')
            {
                x[i] = 'A';
            }
            cout << x[i];
        }
        cout << endl;
    }
}

int main()
{

    solve();
    return 0;
}