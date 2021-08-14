// POJ 3074数独

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
const int maxn = 5e2 + 50;
const double PI = acos(-1.0);
#define mst(x, a) memset(x, a, sizeof(x))
const double eps = 1e-10;
/*************************************************************************/


void init() {
 
}

int ans[10][10], stk[maxn];

struct DLX {
  static const int MAXSIZE = 1e5 + 10;
  #define IT(i, A, x) for (i = A[x]; i != x; i = A[i])
  int n, m, tot, first[MAXSIZE + 10], siz[MAXSIZE + 10];
  int L[MAXSIZE + 10], R[MAXSIZE + 10], U[MAXSIZE + 10], D[MAXSIZE + 10];
  int col[MAXSIZE + 10], row[MAXSIZE + 10];
  void build(const int &r, const int &c) {
    n = r, m = c;
    for (int i = 0; i <= c; ++i) {
      L[i] = i - 1, R[i] = i + 1;
      U[i] = D[i] = i;
    }
    L[0] = c, R[c] = 0, tot = c;
    memset(first, 0, sizeof(first));
    memset(siz, 0, sizeof(siz));
  }
  void insert(const int &r, const int &c) {
    col[++tot] = c, row[tot] = r, ++siz[c];
    D[tot] = D[c], U[D[c]] = tot, U[tot] = c, D[c] = tot;
    if (!first[r])
      first[r] = L[tot] = R[tot] = tot;
    else {
      R[tot] = R[first[r]], L[R[first[r]]] = tot;
      L[tot] = first[r], R[first[r]] = tot;
    }
  }
  void remove(const int &c) {
    int i, j;
    L[R[c]] = L[c], R[L[c]] = R[c];
    IT(i, D, c) IT(j, R, i) U[D[j]] = U[j], D[U[j]] = D[j], --siz[col[j]];
  }
  void recover(const int &c) {
    int i, j;
    IT(i, U, c) IT(j, L, i) U[D[j]] = D[U[j]] = j, ++siz[col[j]];
    L[R[c]] = R[L[c]] = c;
  }
  bool dance(int dep) {
    int i, j, c = R[0];
    if (!R[0]) {
      for (i = 1; i < dep; ++i) {
        int x = (stk[i] - 1) / 9 / 9 + 1;
        int y = (stk[i] - 1) / 9 % 9 + 1;
        int v = (stk[i] - 1) % 9 + 1;
        ans[x][y] = v;
      }
      return 1;
    }
    IT(i, R, 0) if (siz[i] < siz[c]) c = i;
    remove(c);
    IT(i, D, c) {
      stk[dep] = row[i];
      IT(j, R, i) remove(col[j]);
      if (dance(dep + 1)) return 1;
      IT(j, L, i) recover(col[j]);
    }
    recover(c);
    return 0;
  }
} solver;
int GetId(int row, int col, int num) {
  return (row - 1) * 9 * 9 + (col - 1) * 9 + num;
}
void Insert(int row, int col, int num) {
  int dx = (row - 1) / 3 + 1;
  int dy = (col - 1) / 3 + 1;
  int room = (dx - 1) * 3 + dy;
  int id = GetId(row, col, num);
  int f1 = (row - 1) * 9 + num;            // task 1
  int f2 = 81 + (col - 1) * 9 + num;       // task 2
  int f3 = 81 * 2 + (room - 1) * 9 + num;  // task 3
  int f4 = 81 * 3 + (row - 1) * 9 + col;   // task 4
  solver.insert(id, f1);
  solver.insert(id, f2);
  solver.insert(id, f3);
  solver.insert(id, f4);
}

string st;
void solve() {
  solver.build(729, 324);
  for (int i = 1; i <= 9; ++i)
    for (int j = 1; j <= 9; ++j) {
        if(st[(i-1)*9+j-1] == '.') {
            ans[i][j] = 0;
        } else {
            ans[i][j] = st[(i-1)*9+j-1] - '0';
        }
      for (int v = 1; v <= 9; ++v) {
        if (ans[i][j] && ans[i][j] != v) continue;
        Insert(i, j, v);
      }
    }
  solver.dance(1);
  for (int i = 1; i <= 9; ++i)
    for (int j = 1; j <= 9; ++j) {
        printf("%d", ans[i][j]);
  }
  printf("\n");
}

int main() {   

    init();
    // ios::sync_with_stdio(false);
     // cin.tie();
    int tm = 1;
    // SA(tm);
    int cnt = 0;

    REPP(i,1,tm) {
        while(cin>>st) {
            if(st == "end") {
                break;
            }
            solve();
        }
    }

    return 0;
}




// POJ 3740
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
const int maxn = 5e2 + 50;
const double PI = acos(-1.0);
#define mst(x, a) memset(x, a, sizeof(x))
const double eps = 1e-10;
/*************************************************************************/


void init() {
 
}
const int N = 500 + 10;
int n, m, idx, ans;
int first[N], siz[N], stk[N];
struct DLXNODE {
  int lc, rc, up, dn, r, c;
};

struct DLX {
  static const int MAXSIZE = 1e5 + 10;
#define IT(i, A, x) for (i = A[x]; i != x; i = A[i])
  int n, m, tot, first[MAXSIZE + 10], siz[MAXSIZE + 10];
  int L[MAXSIZE + 10], R[MAXSIZE + 10], U[MAXSIZE + 10], D[MAXSIZE + 10];
  int col[MAXSIZE + 10], row[MAXSIZE + 10];
  void build(const int &r, const int &c) {
    n = r, m = c;
    for (int i = 0; i <= c; ++i) {
      L[i] = i - 1, R[i] = i + 1;
      U[i] = D[i] = i;
    }
    L[0] = c, R[c] = 0, tot = c;
    memset(first, 0, sizeof(first));
    memset(siz, 0, sizeof(siz));
  }
  void insert(const int &r, const int &c) {
    col[++tot] = c, row[tot] = r, ++siz[c];
    D[tot] = D[c], U[D[c]] = tot, U[tot] = c, D[c] = tot;
    if (!first[r])
      first[r] = L[tot] = R[tot] = tot;
    else {
      R[tot] = R[first[r]], L[R[first[r]]] = tot;
      L[tot] = first[r], R[first[r]] = tot;
    }
  }
  void remove(const int &c) {
    int i, j;
    L[R[c]] = L[c], R[L[c]] = R[c];
    IT(i, D, c) IT(j, R, i) U[D[j]] = U[j], D[U[j]] = D[j], --siz[col[j]];
  }
  void recover(const int &c) {
    int i, j;
    IT(i, U, c) IT(j, L, i) U[D[j]] = D[U[j]] = j, ++siz[col[j]];
    L[R[c]] = R[L[c]] = c;
  }
  bool dance(int dep) {
    if (!R[0]) {
      ans = dep;
      return 1;
    }
    int i, j, c = R[0];
    IT(i, R, 0) if (siz[i] < siz[c]) c = i;
    remove(c);
    IT(i, D, c) {
      stk[dep] = row[i];
      IT(j, R, i) remove(col[j]);
      if (dance(dep + 1)) return 1;
      IT(j, L, i) recover(col[j]);
    }
    recover(c);
    return 0;
  }
#undef IT
} solver;

void solve() {
   //n = read(), m = read();
  solver.build(n, m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        int x;
      SA(x);
      if (x) solver.insert(i, j);
    }
  if(solver.dance(1)) {
    printf("Yes, I found it\n");
  } else {
    printf("It is impossible\n" );
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
    // SA(tm);
    int cnt = 0;

    REPP(i,1,tm) {
        while(scanf("%d%d", &n, &m) != EOF)
            solve();
    }

    return 0;
}
