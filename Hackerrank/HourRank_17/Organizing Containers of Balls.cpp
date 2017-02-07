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

//const int dx4[5] = { 0,-1,0,1,0 };
//const int dy4[5] = { 0,0,1,0,-1 };
const int dx8[9] = { 0,-1,0,1,0,1,1,-1,-1 };
const int dy8[9] = { 0,0,1,0,-1,1,-1,1,-1 };
const int maxn = 1e2 + 50;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }


int n;
int val[maxn][maxn];
ll col[maxn], row[maxn];

void solve()
{
    mem(col, 0);
    mem(row, 0);
    sa(n);
    repp(i, 1, n)
    {
        repp(j, 1, n)
        {
            sa(val[i][j]);
            row[i] += val[i][j];
            col[j] += val[i][j];
        }
    }
    sort(row + 1, row + n + 1);
    sort(col + 1, col + n + 1);
    repp(i, 1, n)
    {
        if (row[i] != col[i])
        {
            puts("Impossible");
            return;
        }
    }
    puts("Possible");
}

int main()
{

    int t;
    sa(t);
    while (t--)
        solve();
    //system("pause");
    return 0;
}