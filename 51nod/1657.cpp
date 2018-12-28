/*记忆化dp*/
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
const int maxn = 5e5 + 50;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mod1 = 1e9 + 7;
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
string x;
int n;
int dp[220][2][220][55]; //走到第pos位置，用了x次修改，朝向dir方向，走到第serial个字母的时候
int dfs(int pos, int dir, int serial, int n)
{
  if (n < 0)
    return 0;
  if (serial == x.length())
  {
    return n % 2 == 1 ? 0 : abs(pos);
  }
  if (dp[pos + 100][dir][serial][n] != -1)
  {
    return dp[pos + 100][dir][serial][n];
  }
  dp[pos + 100][dir][serial][n] = 0;
  if (x[serial] == 'T')
  {
    dp[pos + 100][dir][serial][n] = max(dp[pos + 100][dir][serial][n], dfs(pos, 1 - dir, serial + 1, n));
    dp[pos + 100][dir][serial][n] = max(dp[pos + 100][dir][serial][n], dfs(pos + (dir == 1 ? 1 : -1), dir, serial + 1, n - 1));
  }
  else
  {
    dp[pos + 100][dir][serial][n] = max(dp[pos + 100][dir][serial][n], dfs(pos + (dir == 1 ? 1 : -1), dir, serial + 1, n));
    dp[pos + 100][dir][serial][n] = max(dp[pos + 100][dir][serial][n], dfs(pos, 1 - dir, serial + 1, n - 1));
  }
  return dp[pos + 100][dir][serial][n];
}

void solve()
{
  memset(dp, -1, sizeof(dp));
  cin >> x >> n;
  int ans = 0;

  ans = max(ans, dfs(0, 1, 0, n));

  cout << ans << endl;
}
int main()
{
  solve();
  // system("pause");
  return 0;
}