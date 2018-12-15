/*题目是求一个数可以用多少种不同的斐波那契数表示方法，要求两两之间不重复，这个条件很重要。
思路非常赞的一道题，首先可以知道一个数一定可以被斐波那契数表示，现在贪心取最大的一种表示方法。
之后是将一个一个的1，看有多少种方法向后推。DP
*/
//#pragma comment(linker,"/STACK:102400000,102400000")
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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define eps 1e-8
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i, n, m) for (int i = n; i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define slla(n) scanf("%lld", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define DE(val) cout << #val << ": " << val << endl;
#define CASET             \
    int ___T, case_n = 1; \
    scanf("%d ", &___T);  \
    repp(i, 1, ___T)

const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};

const int dx4[5] = {0, 1, 0, -1};
const int dy4[5] = {1, 0, -1, 0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
const int maxn = 5e5 + 100;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mod1 = 1e8 + 7;
const ll mod2 = 1e9 + 7;
ll po(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
void extgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
ll inverse(ll a, ll n)
{
    ll d, x, y;
    extgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

void YES()
{
    puts("YES");
    exit(0);
}
void Yes() { puts("Yes"); } // exit(0); }
void NO()
{
    puts("NO");
    exit(0);
}
void No() { puts("No"); } // exit(0); }
void one()
{
    puts("-1");
    exit(0);
}

/*************************************************************************/
ll n;
ll f[100];
ll dp[100][2];

void solve() {
    f[1]=1;
    f[2]=2;
    repp(i,3,88) {
        f[i] = f[i-1] + f[i-2];
    }
    slla(n);
    vector<int>s;
    for(int i=88;i>=1;i--) {
        if(n>=f[i]) {
            n-=f[i];
            s.push_back(i);
        }
    }
    reverse(s.begin(),s.end());
    dp[0][1]=1;
    dp[0][0]=(s[0]-1)/2;
    rep(i,1,s.size()) {
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
        dp[i][0] = (s[i]-s[i-1])/2*dp[i-1][0] + (s[i]-s[i-1]-1)/2*dp[i-1][1];
    }
    printf("%lld\n",dp[s.size()-1][0] + dp[s.size()-1][1]);
}

int main()
{

    solve();
    return 0;
}