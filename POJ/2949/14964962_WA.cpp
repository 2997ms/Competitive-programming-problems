#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

#define INF 100000005
#define eps 1e-8
const int maxn = 700;

int n, k;

struct EDGE
{
	int v;
	int w;
	int next;
}edge[maxn * 2];

int head[maxn], vis[maxn], cnt[maxn], N;
double d[maxn];

void AddEdge(int u, int v, int w)
{
	edge[N].v = v;
	edge[N].w = w;
	edge[N].next = head[u];
	
	head[u] = N++;
}

bool SPFA(int u,double y)
{
	int x, i, e;
	for (i = 1; i <= k; i++)
	{
		d[i] = -INF;
		cnt[i] = 0;
		vis[i] = 0;
	}
	d[u] = 0;
	queue<int>q;
	q.push(u);

	while (!q.empty())
	{
		x = q.front();
		q.pop();
		vis[x] = 0;
		for (int e = head[x]; e != -1; e = edge[e].next)
		{
			if (d[edge[e].v] < d[x] + edge[e].w-y)
			{
				d[edge[e].v] = d[x] + edge[e].w-y;
				if (!vis[edge[e].v])
				{
					q.push(edge[e].v);
					vis[edge[e].v] = 1;

					cnt[edge[e].v]++;
					if (cnt[edge[e].v] > k)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool check(double x)
{
	int i;
	
	memset(vis, 0, sizeof(vis));
	for (i = 1; i <= k; i++)
	{
		if (SPFA(i,x))
			return 1;
	}
	return 0;
}

void input()
{
	memset(vis, 0, sizeof(vis));
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof((edge)));
	memset(d, 0, sizeof(d));

	int i, j, len;
	string s;

	k = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> s;
		len = s.length();
		if (len == 1)continue;

		int a = (s[0] - 'a') * 26 + (s[1] - 'a');
		int b = (s[len - 2] - 'a') * 26 + (s[len - 1] - 'a');
		if (vis[a] == 0)
		{
			vis[a] = ++k;
		}
		if (vis[b] == 0)
		{
			vis[b] = ++k;
		}
		AddEdge(vis[a], vis[b], len);
	}
}

void work()
{
	bool flag = 0;
	double le = 0, ri = 1001;

	double mid;
	while (ri - le > eps)
	{
		mid = (le + ri) / 2;
		if (check(mid))
		{
			flag = 1;
			le = mid;
		}
		else
		{
			ri = mid;
		}
	}
	if (flag == 0)
	{
		puts("No solution");
	}
	else
	{
		printf("%.2f\n", le);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		input();
		work();
	}
	//system("pause");
	return 0;
}