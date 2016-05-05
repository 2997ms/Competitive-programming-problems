#pragma warning(disable:4996)
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
#include <ctime>;
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define INF 0x3fffffff
#define rep(i,n) for(int i=0;i<n;i++)  
#define rep1(i,n) for(int i=1;i<=n;i++) 

const ll mod = 1e9 + 7;
const int maxn = 100005;

int n;
double x[6][maxn];
double minn[40], mann[40];

void input()
{
	int i, j, k;
	scanf("%d", &n);

	memset(minn, 0, sizeof(minn));
	memset(mann, 0, sizeof(mann));

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			scanf("%lf", &x[j][i]);
		}
		if (i == 1)
		{
			for (j = 0; j <= 15; j++)
			{
				double r = x[1][i];
				for (k = 0; k < 4; k++)
				{
					if ((j >> k) & 1)
					{
						r += x[k + 2][i];
					}
					else
					{
						r -= x[k + 2][i];
					}
				}
				mann[j] = r;
				minn[j] = r;
			}
		}
		else
		{
			for (j = 0; j <= 15; j++)
			{
				double r = x[1][i];
				for (k = 0; k < 4; k++)
				{
					if ((j >> k) & 1)
					{
						r += x[k + 2][i];
					}
					else
					{
						r -= x[k + 2][i];
					}
				}
				mann[j] = max(mann[j], r);
				minn[j] = min(minn[j], r);
			}
		}
	}
	double res = mann[0] - minn[0];
	for (j = 1; j <= 15; j++)
	{
		res = max(res, mann[j] - minn[j]);
	}
	printf("%.2f\n", res);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	input();
	return 0;
}