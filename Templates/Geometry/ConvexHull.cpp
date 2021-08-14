// POJ 1228
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
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
// #include <unordered_map>
// #include <bitset>
// #include <iomanip>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define EPS 1e-8
#define LL_INF 0x3fffffffffffffff
#define MEM(a, b) memset(a, b, sizeof(a))
#define PPER(i, n, m) for (int i = n; i >= m; i--)
#define REPP(i, n, m) for (int i = n; i <= m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define PER(i, n, m) for (int i = n; i > m; i--)
#define SA(n) scanf("%d", &(n))
#define SLLA(n) scanf("%lld", &(n))
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define DE(val) cout << #val << ": " << val << endl;
// #define DBG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// #else
// #define DBG(...) 42
// #endif
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[8] = {0, 0, 1,-1,1,-1,0};
const int dy4[8] = {1, -1, 0,0,1,-1,0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};

void update(ll& x,ll v){
    if(x==-1)x=v;
    else if(x>v)x=v;
}
 
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
const int maxn = 3e3 + 5;
const int maxm = 5e2 + 5;
const ll mod = 998244353;
const double PI = acos(-1.0);
#define mst(x, a) memset(x, a, sizeof(x))
const double eps = 1e-10;
/*************************************************************************/


void init() {}

struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double k) const { return Point(x * k, y * k); }
  Point operator/(double k) const { return Point(x / k, y / k); }
  double operator^(const Point &p) const { return x*p.y - y*p.x; }
}pog[maxn];

Point que[maxn];
double dis(Point A, Point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double crossProduct(Point A, Point B) {
    return A.x*B.y-A.y*B.x;
}

bool cmp(Point A,Point B) {
    double s = crossProduct(A-pog[1],B-pog[1]);
    if(s>0)
        return true;
    if(s==0)
        return dis(A,pog[1])<dis(B,pog[1]);
    return false;
}

int n, p;
void solve() {
    SA(n);
    REPP(i,1,n) {
        scanf("%lf%lf", &pog[i].x, &pog[i].y);
    }
    if(n < 6) {
        puts("NO");
        return;
    }
    p = 1;
    REPP(i,2,n) {
        if(pog[i].x < pog[p].x || (pog[i].x == pog[p].x && pog[i].y < pog[p].y)) {
            p = i;
        }
    }
    swap(pog[1], pog[p]);
    sort(pog+2, pog+n+1, cmp);
    que[1] = pog[1];
    que[2] = pog[2];

    int len = 2;
    REPP(i,3,n) {
        while(len >= 2 && crossProduct(que[len] - que[len-1], pog[i] - que[len-1]) < 0) {
            len--;
        }
        que[++len] = pog[i];
    }

    // ------------------------------------------------------------------------------------------------
    que[++len] = pog[1];

    int res = 1;
    REP(i,3,len) {
        if(crossProduct(que[i-1]- que[i-2], que[i] - que[i-1]) != 0
            && crossProduct(que[i]- que[i-1], que[i+1] - que[i]) != 0) {
            res = 0;
            break;
        }
    } 
    if(res) {
        puts("YES");
    } else {
        puts("NO");
    }
}

int main() {   
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif
    init();
    // ios::sync_with_stdio(false);
     // cin.tie();
    int tm = 1;
    SA(tm);
    int cnt = 0;
    REPP(i,1,tm) {
        solve();
    }


    return 0;
}
