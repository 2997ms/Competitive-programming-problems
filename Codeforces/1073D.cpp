/*取模之后一个数字一定减少一半以上。。。。知道这个就好办了*/
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
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define slla(n) scanf("%lld", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define DE(val) cout<<#val<<": "<<val<<endl;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); repp(i,1,___T)

const int dx44[5] = { 0,-1,-1,1,1 };
const int dy44[5] = { 0,-1,1,-1,1 };

const int dx4[5] = { 0,-1,0,1,0 };
const int dy4[5] = { 0,0,1,0,-1 };
const int dx8[9] = { 0,-1,0,1,0,1,1,-1,-1 };
const int dy8[9] = { 0,0,1,0,-1,1,-1,1,-1 };
const int maxn = 5e5 + 50;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
void YES() { puts("YES"); exit(0); }
void Yes() { puts("Yes");}// exit(0); }
void NO() { puts("NO"); exit(0); }
void No() { puts("No");}// exit(0); }
void one() { puts("-1"); exit(0); }

ll n,T;
ll val[maxn];

void solve() {
  slla(n),slla(T);
  ll minx = 1e9;
  ll ans = 0;

  repp(i,1,n) {
    slla(val[i]);
    minx = min(minx,val[i]);
  }
  while(T>=minx) {
    ll t = 0;
    ll sum = 0;
    ll now = T;
    repp(i,1,n) {
      if(now>=val[i]) {
        t++;
        now -= val[i];
        sum += val[i];
      }
    }
   
    ans += t*(T/sum);
    T=T%sum;
 
  }
  cout<<ans<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("i.txt", "r", stdin);
  //freopen("o.txt", "w", stdout);
#endif
    // ios::sync_with_stdio(false);

  int t;
  t = 1;
  //sa(t);
  repp(i,1,t) {
    //printf("Case #%d: ",i);
    solve();
  }
   
    // system("pause");
    return 0;
}