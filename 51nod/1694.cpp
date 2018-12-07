/*就是去掉一条边的情况*/
//#pragma comment(linker, "/STACK:102400000,102400000")
//#include <initializer_list>
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
#include <cassert>
//#include <unordered_map>
//#include <unordered_set>
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
#define CASET           \
  int ___T, case_n = 1; \
  scanf("%d ", &___T);  \
  repp(i, 1, ___T)

const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};

const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 3e2 + 50;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 7;
// ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
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
/******************************************/

int n;
vector<int> edge[maxn];
int va[maxn], vb[maxn];
int dis[maxn];
set<int> pass[maxn][maxn];

void dfs(int x, int fa)
{
  if (x == fa)
  {
    dis[x] = 0;
  }
  else
  {
    dis[x] = dis[fa] + 1;
  }

  rep(i, 0, edge[x].size())
  {
    int nxt = edge[x][i];
    if (nxt == fa)
    {
      continue;
    }
    dfs(nxt, x);
  }
}

int getlen(int x)
{
  repp(i, 1, n)
  {
    dis[i] = -1;
  }
  dfs(x, -1);
  int maxx = 0;
  int p = -1;
  repp(i, 1, n)
  {
    if (dis[i] > maxx)
    {
      p = i;
      maxx = dis[i];
    }
  }
  if (maxx == -1)
  {
    return maxx;
  }
  repp(i, 1, n)
  {
    dis[i] = -1;
  }
  dfs(p, -1);

  repp(i, 1, n)
  {
    if (dis[i] > maxx)
    {
      p = i;
      maxx = dis[i];
    }
  }
  return maxx;
}

void solve()
{
  sa(n);
  repp(i, 1, n - 1)
  {
    sa(va[i]), sa(vb[i]);
  }
  int ans = 0;
  repp(i, 1, n - 1)
  {
    repp(j, 1, n)
    {
      edge[j].clear();
    }
    repp(j, 1, n - 1)
    {
      if (i == j)
        continue;
      edge[va[j]].push_back(vb[j]);
      edge[vb[j]].push_back(va[j]);
    }
    int x = getlen(va[i]);
    int y = getlen(vb[i]);
    x--;
    y--;
    // DE(x)
    // DE(y)

    if (x == -1 || y == -1)
    {
      continue;
    }
    ans = max(ans, x * y);
  }
  cout << ans << endl;
}

int main()
{
  int t;
  t = 1;
  //sa(t);
  repp(i, 1, t)
  {
    //printf("Case #%d: ",i);
    solve();
  }

  // system("pause");
  return 0;
}