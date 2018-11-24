/*三维偏序，CDQ分治。每次分治的时候发现唯一需要处理的一种特殊情况就是前面区间的a==后面区间的a，特判此情况即可*/
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
// ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
void YES() { puts("YES"); exit(0); }
void Yes() { puts("Yes");}// exit(0); }
void NO() { puts("NO"); exit(0); }
void No() { puts("No");}// exit(0); }
void one() { puts("-1"); exit(0); }

int n, m, ans[maxn], tree[maxn*4];
struct node{
    int a, b, c, s, ans; //s处理相同连续,ans比当前美丽值小个数
    node(){}
    node(int a, int b, int c, int s, int ans) : a(a), b(b), c(c), s(s), ans(ans) {}
    bool operator < (const node &rhs) const{ //按y排序
        if(b == rhs.b) return c < rhs.c;
        return b < rhs.b;
    }
}a[maxn], p[maxn];
bool cmp(node x, node y){ //按照x排序
    if(x.a == y.a && x.b == y.b) return x.c < y.c;
    if(x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}
namespace BIT{
    inline int lowbit(int x) {return x&-x;}
    inline void update(int x, int y){for(int i = x; i <= m; i+=lowbit(i)) tree[i] += y;}
    inline int query(int x){int res = 0; for(int i = x; i; i -= lowbit(i)) res += tree[i]; return res;}
}
using namespace BIT;


#define mygc(c) (c)=getchar()

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}


void CDQ(int l, int r)
{
    if(l == r) return;
    int mid = (l + r) >> 1;
    CDQ(l, mid);
    CDQ(mid+1, r);
    sort(p + l, p + mid + 1);
    sort(p + mid + 1, p + r + 1);
    int i = mid, j = r;
   int maxx = -1;


   int maxa = -1;
   int maxexa = -1;
   repp(i,l,mid) {
    maxa = max(maxa,p[i].a);
   }

   while(i>=l) {

    while(j>mid && p[i].b<p[j].b) {
      if(p[j].a!=maxa) {
        maxexa = max(maxexa,p[j].c);
      }
      maxx = max(maxx,p[j].c);
      j--;
    }
    if(p[i].a==maxa) {
      if(maxexa > p[i].c) {
        p[i].ans=1;
      }
    } else {
      if(maxx>p[i].c) {
        p[i].ans=1;
      }
    }

    i--;
   }
}

void solve() {
  int nn;
    scanf("%d", &nn);
    for(int i = 1; i <= nn; i++){
      //scanf("%d", &a[i].a);
      reader(&a[i].a);
    }
    for(int i = 1; i <= nn; i++){
        //scanf("%d", &a[i].b);
      reader(&a[i].b);
    }
    for(int i = 1; i <= nn; i++){
        //scanf("%d", &a[i].c);
      reader(&a[i].c);
    }
    sort(a + 1, a + nn + 1, cmp); //按照x排
    int cnt = 0; //unique
    for(int i = 1; i <= nn; i++){
        p[++n] = a[i];
        p[n].s = 1;
        // DE(a[i].a)
        // DE(a[i].b)
        // DE(a[i].c)
    }
    CDQ(1, n);
    int res = 0;
    repp(i,1,nn) {
      res+=p[i].ans;
    }
    printf("%d\n",res);
}

int main()
{

    int t;
    t = 1;
    //sa(t);
    repp(i,1,t) {
        solve();
    }

    return 0;
}