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
 
const int maxn = 505 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
int n, m;
char x[maxn][maxn], res1[maxn][maxn], res2[maxn][maxn];
 
void solve()
{
    int i, j, k;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%s", x[i] + 1);
        for (int j = 1; j <= m; j++)
        {
            res1[i][j] = '.';
            res2[i][j] = '.';
        }
        if (i & 1)
        {
            for (int j = 1; j < m; j++)res1[i][j] = '#';
            res2[i][m] = '#';
        }
        else
        {
            for (int j = 2; j <= m; j++)res2[i][j] = '#';
            res1[i][1] = '#';
        }
        for (int j = 1; j <= m; j++)
        {
            if (x[i][j] == '#')
            {
                res1[i][j] = res2[i][j] = '#';
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%s\n", res1[i] + 1);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%s\n", res2[i] + 1);
    }
}
 
int main()
{
    solve();
    return 0;
}