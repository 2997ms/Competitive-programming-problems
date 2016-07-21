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
#define eps 1e-10
#define LL_INF 0x33ffffffffffffff
#define INF 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define sa(n) scanf("%d", &(n))
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
 
const int maxn = 500005;
const ll mod = 998244353;
const double PI = acos(-1.0);
 
struct no
{
	int le;
	int ri;
	int max_v;
}node[4 * maxn];
 
void build(int root, int le, int ri, int v)
{
	if (le == ri)
	{
		node[root].le = le;
		node[root].ri = ri;
		node[root].max_v = v;
		return;
	}
	int mid = (le + ri) >> 1;
	build(root << 1, le, mid, v);
	build((root << 1) | 1, mid + 1, ri, v);
	node[root].le = le;
	node[root].ri = ri;
	node[root].max_v = v;
}
 
int query(int root, int le, int ri)
{
	if (node[root].le == le&&node[root].ri == ri)
	{
		return node[root].max_v;
	}
	int mid = (node[root].le + node[root].ri) >> 1;
	if (mid >= ri)
	{
		return query(root << 1, le, ri);
	}
	else if (mid + 1 <= le)
	{
		return query(root << 1 | 1, le, ri);
	}
	else
	{
		return max(query(root << 1, le, mid), query(root << 1 | 1, mid + 1, ri));
	}
}
 
void update(int root, int k, int v)
{
	if (node[root].le == k&&node[root].ri == k)
	{
		node[root].max_v = v;
		return;
	}
	int mid = (node[root].le + node[root].ri) >> 1;
	if (k <= mid)
	{
		update(root << 1, k, v);
	}
	else
	{
		update(root << 1 | 1, k, v);
	}
	node[root].max_v = max(node[root << 1].max_v, node[root << 1 | 1].max_v);
}
 
int n, k;
int pos[maxn], out[maxn], res[maxn];
vector<int>ed[maxn];
priority_queue<int>que;
 
void solve()
{
	int i, j, m;
	sa(n), sa(k);
	for(i=1;i<=n;i++)
	{
		sa(m);
		pos[m] = i;
	}
	
	build(1, 1, n, -INF);
	for(i=1;i<=n;i++)
	{
		m = query(1, pos[i], min(n, pos[i] + k - 1));
		if (m != -INF)
		{
			int x = m;
			out[pos[x]]++;
			ed[pos[i]].push_back(pos[x]);
		}
		update(1, pos[i], i);
	}
 
	build(1, 1, n, -INF);
	for (i = n; i >= 1; i--)
	{
		m = query(1, pos[i], min(n, pos[i] + k - 1));
		if (m != -INF)
		{
			int x = -m;
			out[pos[i]]++;
			ed[pos[x]].push_back(pos[i]);
		}
		update(1, pos[i], -i);
	}
	
	for(i=1;i<=n;i++)
	{
		if (out[i] == 0)
		{
			que.push(i);
		}
	}
	for (i = n; i >= 1;i--)
	{
		int v = que.top();
		que.pop();
		res[v] = i;
		
		for(j=0;j<ed[v].size();j++)
		{
			out[ed[v][j]]--;
			if (out[ed[v][j]] == 0)
			{
				que.push(ed[v][j]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\n", res[i]);
	}
}
 
int main()
{
	solve();
	return 0;
}