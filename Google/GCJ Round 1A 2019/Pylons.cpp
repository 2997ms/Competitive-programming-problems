//#pragma comment(linker,"/STACK:102400000,102400000")
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
#define CASET             \
    int ___T, case_n = 1; \
    scanf("%d ", &___T);  \
    repp(i, 1, ___T)

const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};

const int dx4[5] = {0, 1, 0, -1};
const int dy4[5] = {1, 0, -1, 0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
const int maxn = 5e5 + 100;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const ll mod1 = 1e8 + 7;
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
void extgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
ll inverse(ll a, ll n)
{
    ll d, x, y;
    extgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
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

/*************************************************************************/

int r,c;
int con[505][505];
void solve(){
    memset(con,0,sizeof(con));
    sa(r),sa(c);
    repp(i,1,r) {
        repp(j,1,c) {
            repp(x,1,r) {
                repp(y,1,c) {
                    if(i==x||j==y)continue;
                    if(i+j==x+y)continue;
                    if(i-j==x-y)continue;
                    int f1 = (i-1)*c + j-1;
                    int f2 = (x-1)*c + y-1;
                    con[f1][f2]=1;
                }
            }
        }
    }
    int n = r*c;
    vector<int>v;
    rep(i,0,n) {
        v.push_back(i);
    }
    repp(i,1,1000) {
        random_shuffle(v.begin(),v.end());
        int flag=0;
        rep(i,0,n-1) {
            int k = i+1;
            for(;k<n;k++) {
                if(con[v[i]][v[k]]) {
                    swap(v[k],v[i+1]);
                    break;
                }
            }
            if(k>=n) {
                flag = 1;
            }
        }
        if(flag == 0){
            cout<<"POSSIBLE"<<endl;
            rep(i,0,n) {
                int x = v[i]/c + 1;
                int y = v[i]%c + 1;
                cout<<x<<" "<<y<<endl;
            }
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif
    int t;
    sa(t);
    repp(i,1,t) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
