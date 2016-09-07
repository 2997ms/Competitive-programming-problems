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
 
const int maxn = 2e6 + 10;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
 
ll n, lk, cnt;
ll val[maxn], res[maxn];
 
bool check()
{
    ll i, j, k;
    ll sum = 0;
    int num = 0;
    repp(i, 2, n)
    {
        ll t = val[i] + val[i - 1];
        if (t > sum)
        {
            sum = t;
            num = i - 1;
        }
    }
    cnt = 0;
    if (sum < lk)
    {
        return false;
    }
    else
    {
        for (i = 1; i < num; i++)
        {
            cnt++;
            res[cnt] = i;
        }
        for (i = n - 1; i > num; i--)
        {
            cnt++;
            res[cnt] = i;
        }
        cnt++;
        res[cnt] = num;
        return true;
    }
}
 
void solve()
{
    ll i, j, k;
    scanf("%lld%lld", &n, &lk);
    repp(i, 1, n)
    {
        scanf("%lld", &val[i]);
    }
    if (check())
    {
        puts("Possible");
        repp(i, 1, cnt)
        {
            printf("%d\n", res[i]);
        }
    }
    else
    {
        puts("Impossible");
    }
}
 
 
int main()
{
    solve();
    return 0;
}