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
#include <iomanip>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define EPS 1e-8
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f3f3f3f3f
#define MEM(a, b) memset(a, b, sizeof(a))
#define PPER(i, n, m) for (int i = n; i >= m; i--)
#define REPP(i, n, m) for (int i = n; i <= m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define PER(i, n, m) for (int i = n; i > m; i--)
#define SA(n) scanf("%d", &(n))
#define SLLA(n) scanf("%lld", &(n))
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define DE(val) cout << #val << ": " << val << endl;
 
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[6] = {0, 1, 0,-1};
const int dy4[6] = {1, 0, -1,0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};

void update(ll& x,ll v){
    if(x==-1)x=v;
    else if(x>v)x=v;
}
 
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
const int maxn = 2e5 + 15;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
/*************************************************************************/

class Solution {
public:
    ll str_to_ll(string ip) {
        std::vector<ll> v;
        int cur = 0;
        for(int i=0;i<ip.size();i++) {
            if(ip[i]== '.') {
                v.push_back(cur);
                cur = 0;
            } else {
                cur = cur * 10 + ip[i] - '0';
            }
        }
        v.push_back(cur);
        ll ans = 0;
        ans |= v[0] << 24;
        ans |= v[1] << 16;
        ans |= v[2] << 8;
        ans |= v[3];
        return ans;
    }

    // string cal(int x) {
    //     string ans = "";
    //     while(x > 0) {
    //         ans.push_back(x % 2 + '0');
    //         x /= 2; 
    //     }
    //     while(ans.length() < 8) {
    //         ans.push_back('0');
    //     }
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
    string ll_to_str(ll ip) {
        ll t1 = (ip >> 24) & 255;
        ll t2 = (ip >> 16) & 255;
        ll t3 = (ip >> 8) & 255;
        ll t4 = (ip) & 255;
        return gao(t1) + "." + gao(t2) + "." + gao(t3) + "." + gao(t4);
    }

    string gao(int x) {
        if(x == 0) {
            return "0";
        }
        string ans = "";
        while(x > 0) {
            ans.push_back(x % 10 + '0');
            x /= 10; 
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
    vector<string> ipToCIDR(string ip, int n) {
        ll now = str_to_ll(ip);
        vector<string> ans;
        while(n) {
            ll cur = now;
            int cnt = 0;
            for(int i=1;i<=32;i++) {
                if(now & (1<<cnt)) {
                    break;
                }
                cnt++;
            }
            while((1<<cnt) > n) {
                cnt--;
            }
            // DE(ll_to_str(cur) + "/" + gao(32 - (cnt)))
            n-=(1<<cnt);
            ans.push_back(ll_to_str(cur) + "/" + gao(32 - (cnt)));
            now = now + (1<<cnt);
        }
        return ans;
    }
}t;