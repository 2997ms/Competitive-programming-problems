/*
 题意是给出一棵树，要求树的直径小于等于k，求删去的点的最小数量。
 对每一个点，每一条边进行搜索，超过k/2的记录点的个数，求最小值。
 */
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
using namespace std;
typedef long long ll;
typedef pair<int, ll> pill;

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

const int maxn = 2005;
const ll mod = 1000000007;
const double PI = acos(-1.0);

int n,k;
vector<int>edge[maxn];
int u[maxn],v[maxn];

int dfs(int x,int fa,int dis)
{
    int res=(dis<0);
    int sz=edge[x].size();

    int k=0;
    rep(i,0,sz)
    {
        k=edge[x][i];
        if(k==fa)continue;
        
        res += dfs(k,x,dis-1);
    }
    return res;
}

void solve()
{
    sa(n),sa(k);
    int i,j;
    
    repp(i,1,n-1)
    {
        sa(u[i]),sa(v[i]);
        edge[u[i]].push_back(v[i]);
        edge[v[i]].push_back(u[i]);
    }
    
    int res=n;
    
    repp(i,1,n)
    {
        res = min( res, dfs(i, -1 , k/2));
    }
    repp(i,1,n-1)
    {
        res=min( res , dfs( u[i] , v[i] , (k-1)/2 ) + dfs( v[i] , u[i] , (k-1)/2 ));
    }
    printf("%d\n", res);
}

int main()
{

    solve();
    return 0;
}
