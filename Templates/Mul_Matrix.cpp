struct Matrix
{
    ll val[maxn][maxn];
    void Init(){
        memset(val, 0, sizeof(val));
        for(int i=0; i<maxn; i++)
            val[i][i] = 1;
    }
};


Matrix Mul_Matrix(Matrix a, Matrix b)
{
    Matrix c;
    for(int i=0; i<maxn; i++)
    {
        for(int j=0; j<maxn; j++)
        {
            c.val[i][j] = 0;
            for(int k=0; k<maxn; k++)
            {
                c.val[i][j] += (a.val[i][k] * b.val[k][j]) % mod;
                c.val[i][j] %= mod;
            }
        }
    }
    return c;
}
Matrix quick_Mod_Matrix(Matrix p, ll m)
{
    Matrix ans, b = p;
    ans.Init();
    while(m)
    {
        if(m & 1)
            ans = Mul_Matrix(ans, b);
        m>>=1;
        b = Mul_Matrix(b, b);
    }
    return ans;
}

/*
hdu 5950
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

const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
char dir_box[] = {'j','N', 'S', 'W', 'E'};
char dir_man[] = {'j','n', 's', 'w', 'e'};
const int dx4[6] = {0,1, 0, -1, 0};
const int dy4[6] = {0,0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const int maxn = 7;
const double PI = acos(-1.0);
const ll mod = 2147493647;
const ll mod1 = 1e6 + 7;
const ll mod2 = 1e8 + 7;

struct Matrix
{
    ll val[maxn][maxn];
    void Init(){
        memset(val, 0, sizeof(val));
        for(int i=0; i<maxn; i++)
            val[i][i] = 1;
    }
};


Matrix Mul_Matrix(Matrix a, Matrix b)
{
    Matrix c;
    for(int i=0; i<maxn; i++)
    {
        for(int j=0; j<maxn; j++)
        {
            c.val[i][j] = 0;
            for(int k=0; k<maxn; k++)
            {
                c.val[i][j] += (a.val[i][k] * b.val[k][j]) % mod;
                c.val[i][j] %= mod;
            }
        }
    }
    return c;
}
Matrix quick_Mod_Matrix(Matrix p, ll m)
{
    Matrix ans, b = p;
    ans.Init();
    while(m)
    {
        if(m & 1)
            ans = Mul_Matrix(ans, b);
        m>>=1;
        b = Mul_Matrix(b, b);
    }
    return ans;
}
///求得的矩阵
Matrix p = {1, 1, 0, 0, 0, 0, 0,
            2, 0, 0, 0, 0, 0, 0,
            1, 0, 1, 0, 0, 0, 0,
            4, 0, 4, 1, 0, 0, 0,
            6, 0, 6, 3, 1, 0, 0,
            4, 0, 4, 3, 2, 1, 0,
            1, 0, 1, 1, 1, 1, 1
           };

int main()
{

    int t;
    sa(t);
    while(t--) {
        ll n, a, b ;
        scanf("%lld%lld%lld", &n, &a, &b);
        if(n==1) {
            printf("%lld\n", a);
            continue;
        }
        if(n==2) {
            printf("%lld\n", b);
            continue;
        }
        Matrix p2 = quick_Mod_Matrix(p, n-2);
        ll ans = b * p2.val[0][0]%mod;
        ans = (ans + a * p2.val[1][0]%mod)%mod;
        ans = (ans + 16 * p2.val[2][0]%mod)%mod;
        ans = (ans + 8 * p2.val[3][0]%mod)%mod;
        ans = (ans + 4 * p2.val[4][0]%mod)%mod;
        ans = (ans + 2 * p2.val[5][0]%mod)%mod;
        ans = (ans + 1 * p2.val[6][0]%mod)%mod;
        printf("%lld\n", ans);
    }
    return 0;
}


*/