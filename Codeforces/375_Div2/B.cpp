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

const int maxn = 1005;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n;
char x[300];

bool idx(char x)
{
    if ((x >= 'a'&&x <= 'z') || (x >= 'A'&&x <= 'Z'))
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
    scanf("%s", x + 1);

    int maxx = 0;
    int num = 0;
    int fla = 0;
    int len = 0;
    int len2 = 0;
    repp(i, 1, n)
    {
        if (fla == 0)//waibu
        {
            if (x[i] == '(')
            {
                fla = 1;
                maxx = max(maxx, len);
                len = 0;
            }
            else if (idx(x[i]))
            {
                len++;
            }
            else
            {
                if (len)
                {
                    maxx = max(maxx, len);
                    len = 0;
                }
                len = 0;
            }
        }
        else
        {
            if (x[i] == ')')
            {
                if (len2)
                {
                    num++;
                    len2 = 0;
                }
                fla = 0;
            }
            else if (idx(x[i]))
            {
                len2++;
            }
            else
            {
                if (len2)
                {
                    num++;
                }
                len2 = 0;
            }
        }
    }
    maxx = max(maxx, len);
    cout << maxx << " " << num << endl;
}
int main()
{
    solve();
    return 0;
}