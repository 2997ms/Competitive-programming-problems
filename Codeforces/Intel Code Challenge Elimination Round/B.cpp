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
#include <ctime>
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

int n;
int p[150];
char x[150][150];
bool idx(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve()
{
    sa(n);
    repp(i, 1, n)
    {
        sa(p[i]);
    }
    char tmp;
    scanf("%c", &tmp);
    repp(i, 1, n)
    {
        cin.getline(x[i] + 1, 130);
        //cout << strlen(x[i] + 1) << endl;
    }
    repp(i, 1, n)
    {
        int len = strlen(x[i] + 1);
        int num = 0;
        repp(j, 1, len)
        {
            if (idx(x[i][j]))
            {
                num++;
            }
        }
        if (num == p[i])continue;
        else
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}


int main()
{
    solve();
    return 0;
}