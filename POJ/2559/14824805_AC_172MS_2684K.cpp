#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

#define N 100002

long long a[N], lef[N], stack[N], top;
long long sum[N];

int main()
{
	long long ans = -1, tmp;
	int i, j, n;
	int ll, rr;

	while (scanf("%lld", &n) != EOF)
	{
		if (n == 0)
			break;
		memset(sum, 0, sizeof(sum));
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", a + i);
		}
		a[++n] = -1;
		top = 0;
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			if (top == 0 || a[i] > a[stack[top - 1]])
			{
				stack[top++] = i;
				lef[i] = i;
				continue;
			}
			if (a[i] == a[stack[top - 1]])
				continue;
			while (top >= 1 && a[i] < a[stack[top - 1]])
			{
				--top;
				tmp = 1LL*a[stack[top]] * (i - lef[stack[top]]);

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

		printf("%lld\n", ans);
	}
	//system("pause");  
	return 0;
}