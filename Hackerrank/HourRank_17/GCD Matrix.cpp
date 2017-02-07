//#pragma comment(linker, "/STACK:102400000,102400000")
#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
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
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

typedef long long ll;
#define eps 1e-8
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

const int dx4[5] = { 0,-1,0,1,0 };
const int dy4[5] = { 0,0,1,0,-1 };
const int dx8[9] = { 0,-1,0,1,0,1,1,-1,-1 };
const int dy8[9] = { 0,0,1,0,-1,1,-1,1,-1 };
const int maxn = 1e5 + 50;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }

int n, m, q;
int a[maxn], b[maxn];
int cnta[maxn], cntb[maxn];
ll res[maxn];

void solve()
{
    sa(n), sa(m);
    sa(q);
    repp(i, 1, n)
    {
        sa(a[i]);
    }
    repp(i, 1, m)
    {
        sa(b[i]);
    }

    while (q--)
    {
        int r1, r2, c1, c2;
        sa(r1), sa(r2), sa(c1), sa(c2);
        r1++, r2++, c1++, c2++;
        mem(cnta, 0);
        mem(cntb, 0);
        repp(i, r1, c1)
        {
            cnta[a[i]]++;
        }
        repp(i, r2, c2)
        {
            cntb[b[i]]++;
        }
        repp(i, 1, 1e5)
        {
            for (int j = i + i; j <= 1e5; j += i)
            {
                cnta[i] += cnta[j];
                cntb[i] += cntb[j];
            }
        }
        mem(res, 0);
        int wc = 0;
        for (int i = 1e5; i >= 1; i--)
        {
            res[i] = 1LL * cnta[i] * cntb[i];
            for (int j = i + i; j <= 1e5; j += i)
            {
                res[i] -= res[j];
            }
            if (res[i])wc++;
        }
        printf("%d\n", wc);
    }
}

int main()
{
    solve();
    //system("pause");
    return 0;
}