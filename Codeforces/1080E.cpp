/*给出了一个矩阵，现在让你挑一个子矩阵。对这个子矩阵中的行中的字母可以任意排列，问有多少个子矩阵最终可以行和列都是回文
打比赛的时候已经到最后这里了。但是不知道有什么算法可以 "给定一个字符串，要在O(n)的时间内找到里面所有的回文字符串"
后来才知道马拉车可以。。。太弱了。。。
*/
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
const ll mod1 = 1e8 + 7;
const ll mod2 = 1e9 + 7;
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
void extgcd(ll a,ll b,ll& d,ll& x,ll& y){ if(!b){ d=a; x=1; y=0;} else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }}
ll inverse(ll a,ll n){ ll d,x,y;extgcd(a,n,d,x,y);return d==1?(x+n)%n:-1;}

void YES() { puts("YES"); exit(0); }
void Yes() { puts("Yes");}// exit(0); }
void NO() { puts("NO"); exit(0); }
void No() { puts("No");}// exit(0); }
void one() { puts("-1"); exit(0); }

int n,m;
int sz;
char val[255][255];
int pre[255][255][30];

int ges1[255][255][255];
int ges2[255][255][255];

long long h[600],b1[600],b2[600];
int dp1[1005];
int dp2[1005];


const long long key1=397,key2=419;


inline long long solve(int i1,int i2,int k1,int k2) {
    sz=0;

    for (int i=i1;i<=i2;++i) {
      ++sz;
      b1[sz]=ges1[i][k1][k2];
      b2[sz]=ges2[i][k1][k2];
    }
    long long res=0;
    int l=0,r=0,x;
    for (int i=1;i<=sz;++i) {
        if (i>r) x=1;
        else x=min(dp1[l+r-i],r-i);
        while (i-x>=1 && i+x<=sz && b1[i-x]==b1[i+x]&&b2[i-x]==b2[i+x]) ++x;
        dp1[i]=x;
        if (i+x-1>r) l=i-x+1,r=i+x-1;
        res+=x;
    }
    l=0,r=0;
    for (int i=1;i<=sz;++i) {
        if (i>r) x=0;
        else x=min(dp2[l+r-i+1],r-i+1);
        while (i-x-1>=1 && i+x<=sz && b1[i-x-1]==b1[i+x]&& b2[i-x-1]==b2[i+x]) ++x;
        dp2[i]=x;
        res+=x;
        if (i+x>=r) l=i-x,r=i+x-1;
    }
    return res;
}


void solve() {

  sa(n),sa(m);
  repp(i,1,n) {
    scanf("%s",val[i] + 1);
  }

  repp(i,1,n) {
    repp(j,1,m) {
      pre[i][j][val[i][j]-'a']++;
      repp(k,0,26) {
        pre[i][j][k] += pre[i][j-1][k];
      }
    }
  }

  repp(i,1,n) {
    repp(j,1,m) {
      repp(k,j,m) {
        int flag = 0;
        repp(x,0,25) {
          int cnt = pre[i][k][x] - pre[i][j-1][x];
          if(cnt&1) {
            flag++;
          }
          ges1[i][j][k] = ges1[i][j][k]*key1 + cnt;
          
          ges2[i][j][k] = ges2[i][j][k]*key2 + cnt;
         
        }
        if(flag>1) {
          ges1[i][j][k]=0;
          ges2[i][j][k]=0;
        }
      }
    }
  }
  ll ans = 0;
  repp(i,1,m) {
    repp(j,i,m) {
      int st = 1;
      int en = 1;

      while(st<=n) {
        int sz = 0;
        en=st;
        while(en<=n) {
          if(ges1[en][i][j]==0&&ges2[en][i][j]==0) {
            break;
          }
          sz++;
          en++;
        }
        if(sz) {
          ll tmp = solve(st,en-1,i,j);
          ans += tmp;
        }
        
        st = en+1;
      }
    }
  }
  printf("%lld\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    //freopen("OUTPUT_PATH", "w", stdout);
#endif
    //init();
    solve();

    return 0;
}
