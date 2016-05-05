#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n, m, s, v;
double gopher_x[105], gopher_y[105];
double hole_x[105], hole_y[105];

int grid[105][105];
int link[105];
int visit[105];
int V1, V2;
int result;

bool dfs(int x)
{
	int i;
	for (i = 1; i <= V2; i++)
	{
		if (grid[x][i] == 1 && visit[i] == 0)
		{
			visit[i] = 1;
			if (link[i] == -1 || dfs(link[i]))
			{
				link[i] = x;
				return true;
			}
		}
	}
	return false;
}

void Magyarors()
{
	int i;

	result = 0;
	memset(link, -1, sizeof(link));//！！这里不能是0  

	for (i = 1; i<=V1; i++)
	{
		memset(visit, 0, sizeof(visit));
		if (dfs(i))
			result++;
	}
	cout << n- result << endl;
}


int main()
{
	int i, j;
	double dis;
	while (scanf("%d%d%d%d", &n, &m, &s, &v) != EOF)
	{
		memset(grid, 0, sizeof(grid));
		for (i = 1; i <= n; i++)
		{
			cin >> gopher_x[i] >> gopher_y[i];
		}
		for (i = 1; i <= m; i++)
		{
			cin >> hole_x[i] >> hole_y[i];
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				dis = sqrt((gopher_x[i] - hole_x[j])*(gopher_x[i] - hole_x[j]) + ((gopher_y[i] - hole_y[j]))*((gopher_y[i] - hole_y[j])));
				if (dis <= (double)(s*v))
				{
					grid[i][j] = 1;
				}
			}
		}
		V1 = n;
		V2 = m;
		Magyarors();
	}
	return 0;
}
