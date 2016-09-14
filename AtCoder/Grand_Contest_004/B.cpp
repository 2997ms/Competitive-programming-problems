#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
 
#define INF 0x3fffffff
typedef long long ll;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define pb push_back
 
const int maxn = 5e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
ll n, x;
ll val[maxn], pre[maxn];
 
void solve()
{
    scanf("%lld%lld", &n, &x);
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &val[i]);
        res += val[i];
        pre[i] = val[i];
    }
    for (int k = 0; k < n; k++)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll t = val[(i - k + n) % n];
            pre[i] = min(pre[i], t);
            sum += pre[i];
        }
        res = min(res, sum + k*x);
    }
    printf("%lld", res);
}
 
int main()
{
    solve();
    return 0;
}