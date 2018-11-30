/*注意边界情况。判断在一个线段的左边还是右边*/
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
const int maxn = 5e2 + 5;
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
pair<int,int>red[maxn],blue[maxn];
int cnt[maxn][maxn];

bool ri(pair<int,int>a, pair<int,int>b, pair<int,int>c) {
    double x1=a.first;
    double y1=a.second;
    double x2=b.first;
    double y2=b.second;
    double xx=c.first;
    double yy=c.second;

    double k = (y2-y1)/(x2-x1);
    double bt = y1-x1*k;

    double ys = k*xx+bt;
    return ys>yy;
}

void solve() {
    sa(n),sa(m);
    repp(i,1,n) {
        sa(red[i].first);
        sa(red[i].second);
    }
    repp(i,1,m) {
        sa(blue[i].first);
        sa(blue[i].second);
    }

    repp(i,1,n) {
        repp(j,1,n) {
            if(red[i].first >= red[j].first) continue;
            repp(k,1,m) {
                if (blue[k].first>red[i].first && blue[k].first<=red[j].first && ri(red[i],red[j],blue[k])) {
                    cnt[i][j]++;
                }
            }

            cnt[j][i] = -cnt[i][j];
        }
    }
    int ans = 0;
    repp(i,1,n) {
        repp(j,i+1,n) {
            repp(k,j+1,n) {
                if(cnt[i][j] + cnt[j][k] + cnt[k][i] == 0) {
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    //init();
    solve();

    return 0;
}
