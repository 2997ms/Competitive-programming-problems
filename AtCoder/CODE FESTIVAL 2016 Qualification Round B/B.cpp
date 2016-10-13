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
 
const int maxn = 2e5 + 5;
const ll mod = 1000;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n, a, b;
string val;
 
void solve()
{
    int ca = 0, cb = 0;
    cin >> n >> a >> b;
    cin >> val;
    int len = val.length();
    rep(i, 0, len)
    {
        if (val[i] == 'c')
        {
            puts("No");
        }
        else
        {
            if (val[i] == 'a')
            {
                if (ca + cb + 1 <= a + b)
                {
                    ca++;
                    puts("Yes");
                }
                else
                {
                    puts("No");
                }
            }
            else
            {
 
                if (ca + cb + 1 <= a + b&&cb+1<=b)
                {
                    cb++;
                    puts("Yes");
                }
                else
                {
                    puts("No");
                }
            }
        }
    }
}
 
int main()
{
    solve();
    return 0;
}