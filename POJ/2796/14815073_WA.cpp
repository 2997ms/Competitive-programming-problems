#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define N 100001

int a[N], lef[N], stack[N], top;
long long sum[N];

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	long long ans = -1, tmp;
	int i, j, n;
	int ll, rr;

	scanf("%d", &n);
	memset(sum, 0, sizeof(sum));
	for (i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		sum[i] = sum[i - 1] + a[i];
	}
	a[++n] = -1;
	top = 0;
	for (i = 1; i <= n; i++)
	{
		if (top == 0 || a[i] > a[stack[top - 1]])
		{
			stack[top++] = i;
			lef[i] = i;
			continue;
		}
		if (i == stack[top - 1])
			continue;
		while (top >= 1 && a[i] < a[stack[top - 1]])
		{
			--top;
			tmp = 1LL*a[stack[top]] * (sum[i - 1] - sum[lef[stack[top]] - 1]);

			if (tmp > ans)
			{
				ll = lef[stack[top]];
				rr = i - 1;
				ans = tmp;
			}
		}
		lef[i] = lef[stack[top]];
		stack[top++] = i;
	}

	printf("%lld\n%d %d\n", ans, ll, rr);
	//system("pause");
	return 0;
}
