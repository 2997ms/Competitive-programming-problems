/*数量小，暴力。*/
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

int overlaps[50][50];
    string dp[1<<15][21];
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        memset(overlaps,0,sizeof(overlaps));
        for(int i=0;i<(1<<15);i++) {
            for(int j=0;j<15;j++) {
                dp[i][j]="";
            }
        }
        for (int i=0;i<A.size();i++) {
            for(int j=0;j<A.size();j++) {
                if(i==j)continue;
                for (int k = A[j].size();k>=1;k--) {
                    int num = A[i].find(A[j].substr(0,k),A[i].size()-k);
                    if (num>=0) {
                        overlaps[i][j]=k;
                        break;
                    }
                }
            }
        }

        int sz = A.size();
        for(int i=1;i<(1<<sz);i++) {
            for (int j=0;j<sz;j++) {
                if(i&(1<<j)) {
                    if(i==(1<<j)) {
                        dp[i][j] = A[j];
                    } else {
                        for (int k=0;k<sz;k++) {
                            if(k==j) {
                                continue;
                            } else {
                                if( (i&(1<<k))) {
                                    int cur = i-(1<<j);
                                    string x = dp[cur][k] + A[j].substr(overlaps[k][j]);
                                    if(dp[i][j]==""||dp[i][j].size()>x.size()) {
                                        dp[i][j] = x;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int minn = 0;
        for(int i=0;i<sz;i++) {
            if(dp[(1<<sz)-1][i].size()<dp[(1<<sz)-1][minn].size()) {
                minn=i;
            }
        }
        return dp[(1<<sz)-1][minn];
    }
};

