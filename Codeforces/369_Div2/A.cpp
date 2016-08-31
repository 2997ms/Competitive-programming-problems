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

char x[1005][20];
int f[maxn];

int main()
{

    int t;
    int f = 0;
    sa(t);
    repp(i,1,t)
    {
        scanf("%s", x[i] + 1);
        if (f)continue;
        if (x[i][1] == 'O'&&x[i][2] == 'O')
        {
            f = 1;
            x[i][1] = '+';
            x[i][2] = '+';
        }
        else if (x[i][4] == 'O'&&x[i][5] == 'O')
        {
            f = 1;
            x[i][4] = '+';
            x[i][5] = '+';
        }
    }
    if (f)
    {
        puts("YES");
        repp(i, 1, t)
        {
            cout << x[i] + 1 << endl;
        }
    }
    else
    {
        puts("NO");
    }
    return 0;
}