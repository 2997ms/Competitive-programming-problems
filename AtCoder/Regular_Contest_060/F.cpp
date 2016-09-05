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
 
int len, k;
char x[maxn];
int pos[maxn], ans[maxn];
 
void kmp()
{
    k = 0;
    memset(pos, 0, sizeof(pos));
    for (int i = 2; i <= len; i++)
    {
        while (k && x[k + 1] != x[i])
        {
            k = pos[k];
        }
        if (x[k + 1] == x[i])
        {
            k++;
        }
        pos[i] = k;
    }
}
 
void solve()
{
    scanf("%s", x + 1);
    len = strlen(x + 1);
    kmp();
    int L = 0;
    if (k&&len % (len - k) == 0)
    {
        L = (len - k);
    }
    if (L == 0)
    {
        printf("1\n1\n");
        return;
    }
    if (L == 1)
    {
        printf("%d\n1\n", len);
        return;
    }
    for (int i = 1; i <= len; i++)
    {
        ans[i] = (pos[i] == 0 || (i % (i - pos[i]) != 0));
    }
    reverse(x + 1, x + len + 1);
    kmp();
    int res = 0;
    for (int i = 1; i <= len; i++)
    {
        ans[len - i] &= (pos[i] == 0 || (i % (i - pos[i]) != 0));
        res += ans[len - i + 1];
    }
    printf("2\n%d\n", res);
}
 
int main()
{
    solve();
    return 0;
}