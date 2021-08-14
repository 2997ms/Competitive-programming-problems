// CF1526 C2

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
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
// #include <unordered_map>
// #include <bitset>
// #include <iomanip>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define EPS 1e-9
#define LL_INF 0x3fffffffffffffff
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
// #define DBG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// #else
// #define DBG(...) 42
// #endif
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[8] = {0, 0, 1,-1,1,-1,0};
const int dy4[8] = {1, -1, 0,0,1,-1,0};
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
const int maxn = 2e6 + 150;
const double PI = acos(-1.0);
#define mst(x, a) memset(x, a, sizeof(x))
const double eps = 1e-10;
/*************************************************************************/


#define MAXN 200010
#define inf 0x3f3f3f3f

ll dp[maxn];
struct node{  
    int l,r;//区间[l,r]  
    ll add;//区间的延时标记  
    ll sum;//区间和  
    ll mx; //区间最大值  
    ll mn; //区间最小值  
}tree[MAXN<<2];//一定要开到4倍多的空间  
  
void pushup(int index){  
    tree[index].sum = tree[index<<1].sum+tree[index<<1|1].sum;  
    tree[index].mx = max(tree[index<<1].mx,tree[index<<1|1].mx);  
    tree[index].mn = min(tree[index<<1].mn,tree[index<<1|1].mn);  
}  
void pushdown(int index){  
    //说明该区间之前更新过  
    //要想更新该区间下面的子区间，就要把上次更新该区间的值向下更新  
    if(tree[index].add){  
        //替换原来的值  
        /* 
        tree[index<<1].sum = (tree[index<<1].r-tree[index<<1].l+1)*tree[index].add; 
        tree[index<<1|1].sum = (tree[index<<1|1].r-tree[index<<1|1].l+1)*tree[index].add; 
        tree[index<<1].mx = tree[index].add; 
        tree[index<<1|1].mx = tree[index].add; 
        tree[index<<1].mn = tree[index].add; 
        tree[index<<1|1].mn = tree[index].add; 
        tree[index<<1].add = tree[index].add; 
        tree[index<<1|1].add = tree[index].add; 
        tree[index].add = 0;*/  
        //在原来的值的基础上加上val  
          
        tree[index<<1].sum += (tree[index<<1].r-tree[index<<1].l+1)*tree[index].add;  
        tree[index<<1|1].sum +=(tree[index<<1|1].r-tree[index<<1|1].l+1)*tree[index].add;  
        tree[index<<1].mx += tree[index].add;  
        tree[index<<1|1].mx += tree[index].add;  
        tree[index<<1].mn += tree[index].add;  
        tree[index<<1|1].mn += tree[index].add;  
        tree[index<<1].add += tree[index].add;  
        tree[index<<1|1].add += tree[index].add;  
        tree[index].add = 0;  
  
    }  
}  
void build(int l,int r,int index){  
    tree[index].l = l;  
    tree[index].r = r;  
    tree[index].add = 0;//刚开始一定要清0  
    if(l == r){  
        //scanf("%d",&tree[index].sum);  
        tree[index].mn = tree[index].mx = tree[index].sum = dp[l];  
        return ;  
    }  
    int mid = (l+r)>>1;  
    build(l,mid,index<<1);  
    build(mid+1,r,index<<1|1);  
    pushup(index);  
}  
void updata(int l,int r,int index,ll val){  
    if(l <= tree[index].l && r >= tree[index].r){  
        /*把原来的值替换成val,因为该区间有tree[index].r-tree[index].l+1 
        个数，所以区间和 以及 最值为： 
        */  
        /*tree[index].sum = (tree[index].r-tree[index].l+1)*val; 
        tree[index].mn = val; 
        tree[index].mx = val; 
        tree[index].add = val;//延时标记*/  
        //在原来的值的基础上加上val,因为该区间有tree[index].r-tree[index].l+1  
        //个数，所以区间和 以及 最值为：  
        tree[index].sum += (tree[index].r-tree[index].l+1)*val;  
        tree[index].mn += val;  
        tree[index].mx += val;  
        tree[index].add += val;//延时标记  
  
        return ;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    if(l <= mid){  
        updata(l,r,index<<1,val);  
    }  
    if(r > mid){  
        updata(l,r,index<<1|1,val);  
    }  
    pushup(index);  
}  
ll query(int l,int r,int index){  
    if(l <= tree[index].l && r >= tree[index].r){  
        //return tree[index].sum;  
        return tree[index].mn;  
        //return tree[index].mn;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    ll ans = 0;  
    ll Max = 0;  
    ll Min = 1e18;  
    // DE(Min)
    if(l <= mid){  
        // ll 
        // ans += query(l,r,index<<1);  
        // Max = max(query(l,r,index<<1),Max);  
        Min = min(query(l,r,index<<1),Min);  
    }  
    if(r > mid){  
        // ans += query(l,r,index<<1|1);  
        // Max = max(query(l,r,index<<1|1),Max);  
        Min = min(query(l,r,index<<1|1),Min);  
    }  
    //return ans;  
    return Min;  
    //return Min;  
}  

int n;
int val[maxn];
std::vector< pair<ll,int> > v;
inline bool scan_d(int &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
void solve() {
    scan_d(n);
    int ans = 0;
    ll cur = 0;
    REPP(i,1,n) {
        scan_d(val[i]);
        if(val[i] >= 0) {
            ans++;
            cur += val[i];
        } else {
            v.push_back(MP(val[i], i));
        }
        dp[i] = cur;
    }
    build(1,n,1);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int p = 0;
    REP(i,0,v.size()) {
        ll vs = v[i].first;
        int pos = v[i].second;
        if(pos <= p) {
            continue;
        }
        ll minn = query(pos, n, 1);
        // cout<<vs<<" "<<pos<<" "<<minn<<endl;
        if(minn + vs >= 0) {
            ans++;
            updata(pos, n,1, vs);
        } else {
            p = max(p, pos);
        }
    }
    printf("%d\n", ans);
}

int main() {   
#ifndef ONLINE_JUDGE
    //freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
#endif
     // ios::sync_with_stdio(false);
     // cin.tie();
    int t = 1;
    // SA(t);
    REPP(i,1,t) {
        solve();
    }

    // std::vector<std::vector<int> > v = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    // std::vector<int> q = {2,3};
    return 0;
}
