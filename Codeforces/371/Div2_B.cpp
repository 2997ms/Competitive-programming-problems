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

const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n;
int val[maxn];
int num[4];
set<int>res;
map<int, int>app;
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
        res.insert(val[i]);
    }
    if (res.size() <= 2)
    {
        puts("YES");
    }
    else if(res.size()==3)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (app[val[i]] == 0)
            {
                app[val[i]] = 1;
                cnt++;
                num[cnt] = val[i];
            }
        }
        sort(num + 1, num + 4);
        if (num[3] - num[2] == num[2] - num[1])
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    else
    {
        puts("NO");
    }
}

int main()
{
    solve();
    return 0;
}