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

int m, k;
int pri[1000005];

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	gcd(b%a, a);
}

void solve()
{
	int i, j;
	j = 0;
	for (i = 1; i <= m; i++)
	{
		if (gcd(i, m) == 1)
		{
			pri[j++] = i;
		}
	}
	if (k%j == 0)
	{
		printf("%d\n", (k / j - 1)*m + pri[j - 1]);
	}
	else
	{
		printf("%d\n", k / j*m + pri[k%j - 1]);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d%d", &m, &k) != EOF)
	{
		solve();
	}

	//system("pause");
	return 0;
}