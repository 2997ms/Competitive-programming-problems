#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int dis[1000000];
int maxn, sum, v[10], vt[10], len, t;
char num[10];

void dfs(int x, int m, int cap)
{
	int i, y, flag;
	if (x > len - 1)
	{
		/*flag = 1;
		for (i = 0; i < cap; i++)
			if (vt[i] != v[i]) 
				flag = 0;*/

		if (maxn < m)
		{
			maxn = m;  
			sum = cap;
			for (i = 0; i < cap; i++) 
				vt[i] = v[i];
		}

		//if (flag == 0)
			dis[m]++;
		return;
	}
	y = 0;
	for (i = x; i < len; i++)
	{
		y = y * 10 + (num[i] - '0');
		if (y + m <= t)
		{
			v[cap] = y;
			dfs(i + 1, y + m, cap + 1);
		}
		else
			break;
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int s, i;
	while (scanf("%d%s", &t, num))
	{
		memset(v, 0, sizeof(v));
		memset(vt, 0, sizeof(vt));
		memset(dis, 0, sizeof(dis));
		len = strlen(num);

		if (t == 0 && len == 1 && num[0] == '0')
			break;

		s = 0;
		for (i = 0; i < len; i++)
			s += num[i] - '0';
		if (s > t)
		{
			printf("error\n");
			continue;
		}

		maxn = 0, sum = 0;
		dfs(0, 0, 0);

		if (dis[maxn] != 1)
			printf("rejected");
		else
		{
			printf("%d", maxn);
			for (i = 0; i < sum; i++)
				printf(" %d", vt[i]);
		}
		printf("\n");
	}
	return 0;
}