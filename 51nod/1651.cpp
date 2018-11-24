/*发现k并不大，可以暴力求第k大的子串。*/
//#pragma comment(linker,"/STACK:102400000,102400000")
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
// #include <cassert>
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

const int dx4[5] = { 0,1,0,-1 };
const int dy4[5] = { 1,0,-1,0 };
const int dx8[9] = { 0,-1,0,1,0,1,1,-1,-1 };
const int dy8[9] = { 0,0,1,0,-1,1,-1,1,-1 };
const int dx82[9] = { 0,-1,-1,1,1, 2,2,-2,-2 };
const int dy82[9] = { 0,2,-2,2,-2, 1,-1,1,-1 };
const int maxn = 3e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;

ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
void extgcd(ll a,ll b,ll& d,ll& x,ll& y){ if(!b){ d=a; x=1; y=0;} else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }}
ll inverse(ll a,ll n){ ll d,x,y;extgcd(a,n,d,x,y);return d==1?(x+n)%n:-1;}

void YES() { puts("YES"); exit(0); }
void Yes() { puts("Yes");}// exit(0); }
void NO() { puts("NO"); exit(0); }
void No() { puts("No");}// exit(0); }
void one() { puts("-1"); exit(0); }

string x;
int k;
priority_queue< pair<string,int> , vector< pair<string,int> >, greater< pair<string,int> > >que;
    string tmp;
void solve() {
  cin>>x>>k;
  rep(i,0,x.length()) {
    tmp=x[i];
    que.push(mp(tmp,i));
  }
  string ans;
  while(k>=0&&!que.empty()) {

    pair<string,int>now = que.top();
    que.pop();
    if(k==1) {
      cout<<now.first<<endl;
      return;
    }
    //DE(now.first)
    k--;
    if(now.second+1<x.length()) {
      que.push(mp(now.first+x[now.second+1],now.second+1));
    }
  }

  puts("No such line.");
}

int main()
{
    solve();

    return 0;
}
