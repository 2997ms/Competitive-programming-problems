#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
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
#include <unordered_set>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define eps 1e-10
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define pper(i,n,m) for(int i = n;i >= m; i--)
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
 
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll po(ll a, ll b, ll mod) { ll res = 1; a %= mod; for (; b; b >>= 1) { if (b & 1)res = res*a%mod; a = a*a%mod; }return res; }
ll gcd(ll a, ll b) { if (a == 0) { return b; } else { return gcd(b%a, a); } }
 
 
int n;
vector<int>v;
vector<int>r;
pair < vector<int>, int>ans;
 
bool a_sml_b(int a, int b)
{
#ifdef DEBUG
    return v[a + 1] < v[b + 1];
#else 
    cout << "2 " << a + 1 << " " << b + 1 << endl;
    flush(cout);
    string res;
    cin >> res;
    flush(cout);
    return res == "Yes";
#endif
}
 
bool a_div_b(int a, int b,int d)
{
#ifdef DEBUG
    return abs(v[a + 1] - v[b + 1]) % d == 0;
#else
    cout << "1 " << a + 1 << " " << b + 1 << " " << d << endl;
    flush(cout);
    string res;
    cin >> res;
    flush(cout);
    return res == "Yes";
#endif
}
 
pair< vector<int>, int> cal(vector<int>t, int div)
{
    int n = t.size();
    if (n == 1)
    {
        vector<int>ans = { 1 };
        return make_pair(ans, t[0]);
    }
    else if (n == 2)
    {
        if (a_sml_b(t[0], t[1]))
        {
            vector<int>ans = { 1,2 };
            return make_pair(ans, t[0]);
        }
        else
        {
            vector<int>ans = { 2,1 };
            return make_pair(ans, t[1]);
        }
    }
    else
    {
        int sz = t.size();
        int m = t[0];
        vector<int>lef, rig;
        lef.push_back(t[0]);
        vector<int>lef_ind = { 0 };
        vector<int>rig_ind;
 
        for (int i = 1; i < sz; i++)
        {
            if (a_div_b(m, t[i], div))
            {
                lef.push_back(t[i]);
                lef_ind.push_back(i);
            }
            else
            {
                rig.push_back(t[i]);
                rig_ind.push_back(i);
            }
        }
 
        pair< vector<int>, int>res_lef;
        pair< vector<int>, int>res_rig;
        res_lef = cal(lef, div * 2);
        res_rig = cal(rig, div * 2);
 
        int lef_min = res_lef.second;
        int rig_min = res_rig.second;
        
        bool le_min = false;
        if (a_sml_b(lef_min, rig_min))
        {
            le_min = true;
        }
        vector<int>ans(n);
        for (int i = 0; i < lef_ind.size(); i++)
        {
            if (le_min)
            {
                ans[lef_ind[i]] = 2 * res_lef.first[i] - 1;
            }
            else
            {
                ans[lef_ind[i]] = 2 * res_lef.first[i];
            }
        }
        for (int i = 0; i < rig_ind.size(); i++)
        {
            if (le_min)
            {
                ans[rig_ind[i]] = 2 * res_rig.first[i];
            }
            else
            {
                ans[rig_ind[i]] = 2 * res_rig.first[i] - 1;
            }
        }
        return make_pair(ans, le_min ? res_lef.second : res_rig.second);
    }
}
 
void solve()
{
    v = {0,1,2,3,4,5,6,7,8 };
    cin >> n;
    flush(cout);
    r.clear();
    for (int i = 0; i < n; i++)
    {
        r.push_back(i);
    }
    ans = cal(r, 2);
    cout << "3";
    for (int i = 0; i < n; i++)
    {
        cout << " " << ans.first[i];
    }
    cout << endl;
    flush(cout);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    flush(cout);
    while (t--)
    {
        solve();
    }
    //system("pause");
    return 0;
}