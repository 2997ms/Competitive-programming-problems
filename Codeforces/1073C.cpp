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

int n;
char val[maxn];
int x,y;

int pre[maxn][6];// R L U D
int suf[maxn][6];

bool check(int len) {
  int flag = 0;
  repp(i,1,n) {
    int j = i + len - 1;
    if (j>n) {
      break;
    }

    int right = pre[i-1][1] + suf[j+1][1];
    int left = pre[i-1][2] + suf[j+1][2];
    int up = pre[i-1][3] + suf[j+1][3];
    int down = pre[i-1][4] + suf[j+1][4];

    int ny = up-down;
    int nx = right-left;
    
    int disx = abs(x - nx);
    int disy = abs(y - ny);

    int lent = len;
    lent -= disx;
    lent -= disy;

    if (lent<0) {
      continue;
    } 

    if(lent%2==0) {
      flag=1;
    }
  }
  return flag;
}

void solve() {
  sa(n);
  scanf("%s",val+1);
  sa(x),sa(y);

  repp(i,1,n) {
    repp(k,1,4) {
      pre[i][k] = pre[i-1][k];
    }    
    if (val[i]=='R') {
      pre[i][1]++;
    } else if (val[i] == 'L') {
      pre[i][2]++;
    } else if (val[i] == 'U') {
      pre[i][3]++;
    } else {
      pre[i][4]++;
    }

  }

  for(int i=n;i>=1;i--) {
    repp(k,1,4) {
      suf[i][k] = suf[i+1][k];
    }    
    if (val[i]=='R') {
      suf[i][1]++;
    } else if (val[i] == 'L') {
      suf[i][2]++;
    } else if (val[i] == 'U') {
      suf[i][3]++;
    } else {
      suf[i][4]++;
    }
  }
  if(check(0)) {
    cout<<0<<endl;
    return;
  }
  int le=1,ri=n;

  while(le<ri) {
    int mid = (le + ri)/2;
    if (check(mid)) {
      ri = mid;
    } else {
      le = mid+1;
    }
  }

  if (check(le)) {
    cout<<le<<endl;
  } else {
    puts("-1");
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("i.txt", "r", stdin);
  //freopen("o.txt", "w", stdout);
#endif
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