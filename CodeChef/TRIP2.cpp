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
 
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[6] = {0, 1, 0,-1};
const int dy4[6] = {-1, 0, 1,0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
/*************************************************************************/

int n,k;
int val[maxn];
void solve() {
    sa(n),sa(k);
    memset(val,0,sizeof(val));
    repp(i,1,n) {
        sa(val[i]);
    }

    if(k>=3) {
        int flag = 1;
        repp(i,1,n) {
            int p1 = -1;
            int p2 = -1;
            if(i-1>=1) {
                p1 = val[i-1];
            }
            if(i+1<=n) {
                p2 = val[i+1];
            }
            if(val[i] != -1) {
                if(val[i] == p1 || val[i] == p2) {
                    flag = 0;
                    break;
                }
                continue;
            }
            repp(s,1,k) {
                if(s == p1 || s == p2) continue;
                val[i] = s;
                break;
            }
            if(val[i]==-1) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("YES\n");
            repp(i,1,n) {
                printf("%d ", val[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    } else {
        int s0 = -1;
        int s1 = -1;
        int flag = 1;
        repp(i,1,n) {
            if(val[i] == -1) continue;
            if(i%2) {
                if(s1 == -1) {
                    s1 = val[i];
                } else {
                    if(s1 != val[i]) {
                        flag = 0;
                    } 
                }
            } else {
                if(s0 == -1) {
                    s0 = val[i];
                } else {
                    if(s0 != val[i]) {
                        flag = 0;
                    } 
                }
            }
        }
        if(!flag) {
            printf("NO\n");
            return;
        }
        if(s1 == -1 && s0 != -1) {
            s1 = 3 - s0;
        } else if(s1 != -1 && s0 == -1) {
            s0 = 3 - s1;
        } else if(s1 == -1 && s0 == -1) {
            s1 = 1;
            s0 = 2;
        } else {
            if(s0 == s1) {
               printf("NO\n");
                return; 
            }
        }
        printf("YES\n");
        repp(i,1,n) {
            if(i%2) {
                val[i] = s1;
            } else {
                val[i] = s0;
            }
            printf("%d ", val[i]);
        }
    }
}

int main()
{
    int t;
    sa(t);
    repp(i,1,t) {
        solve();
    }
    return 0;
}

