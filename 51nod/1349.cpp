/*计算每个数作为最大值的区间，维护一个递增的单调栈*/
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

int n,q;
int a[maxn],k[maxn];
ll ans[maxn],suf[maxn],pre[maxn];

void solve() {
    sa(n);
    repp(i,1,n) {
        sa(a[i]);
        pre[i]=i;
        suf[i]=i;
    }
    stack<int>st;

    repp(i,1,n) {
        while(st.size()&&a[st.top()]<=a[i]) {
            st.pop();
        }
        if(st.size()==0) {
            pre[i]=1;
        } else {
            pre[i] = st.top()+1;
        }
        st.push(i);
    }

    while(st.size()) st.pop();

    for(int i=n;i>=1;i--) {
        while(st.size()&&a[st.top()]<a[i]) {
            st.pop();
        }
        if(st.size()==0) {
            suf[i]=n;
        } else {
            suf[i] = st.top()-1;
        }
        st.push(i);
    }


    repp(i,1,n) {
        ans[a[i]] += 1LL*(i-pre[i]+1)*(suf[i]-i+1);
    }
    for(int i=100000;i>=1;i--) {
        ans[i]+=ans[i+1];
    }
    sa(q);
    repp(i,1,q) {
        int x;
        sa(x);
        printf("%lld\n",ans[x]);
    }
}

int main()
{

    //init();
    solve();

    return 0;
}
