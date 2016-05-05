#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;
typedef long long ll;

int n, k;

int cal(int x, int y)
{
	if (x == 0 && y == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void solve()
{
	int res = 1;
	while (n&&k)
	{
		res = res*cal(n % 2, k % 2);
		n = n / 2;
		k = k / 2;
		if (res == 0)
			break;
	}
	printf("%d\n", res);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	while (scanf("%d%d", &n, &k) != EOF)
	{
		solve();
	}

	//system("pause");
	return 0;
}