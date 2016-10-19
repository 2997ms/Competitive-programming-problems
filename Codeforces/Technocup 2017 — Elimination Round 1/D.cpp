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

int n;
string x[6] = { "S", "M", "L", "XL", "XXL", "XXXL" };
int num[6], ans[maxn];

void solve()
{
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &num[i]);
    }
    scanf("%d", &n);
    vector<int>op[6];
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        int fl = 1;
        for (int j = 0; j < 6; j++)
        {
            if (t == x[j])
            {
                fl = 0;
                num[j]--;
                ans[i] = j;
                if (num[j] < 0)
                {
                    puts("NO");
                    return;
                }
                break;
            }
        }
        if (fl)
        {
            for (int j = 0; j < 6; j++)
            {
                if (t.substr(0,x[j].size()) == x[j])
                {
                    op[j].push_back(i);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < op[i].size(); j++)
        {
            if (num[i] == 0 && num[i + 1] == 0)
            {
                puts("NO");
                return;
            }
            if (num[i])
            {
                num[i]--;
                ans[op[i][j]] = i;
            }
            else
            {
                num[i + 1]--;
                ans[op[i][j]] = i + 1;
            }
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++)
    {
        cout << x[ans[i]] << endl;
    }
}

int main()
{
    solve();
    return 0;
}
