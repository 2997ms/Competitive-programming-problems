#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

#define N 80002

long long a[N], stack[N], top;

int main()
{

	long long ans, tmp;
	int i, j, n;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%lld", a + i);
	}
	a[++n] = 1e9 + 7;
	top = 0;
	ans = 0;
	for (i = 1; i <= n; i++)
	{
		while (top >= 1 && a[i] >= a[stack[top - 1]])
		{
			--top;
		}
		ans = ans + top;
		if (top == 0 || a[i] < a[stack[top - 1]])
		{
			stack[top++] = i;
		}
	}
	printf("%lld\n", ans);

	//system("pause");  
	return 0;
}