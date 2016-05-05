#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;
typedef long long ll;

const ll maxn = 4294967295;

ll n;
ll f[20];
void init()
{
	f[1] = 1;
	f[2] = 9;
	f[3] = 18;

	int i;
	ll p = 18;
	for (i = 4;; i++)
	{
		if (i & 1)
		{
			f[i] = f[i - 1] * 2;
		}
		else
		{
			f[i] = f[i - 1] * 9;
		}
		if (f[i] > maxn)
			break;
	}
}

void solve()
{
	int pos = lower_bound(f, f + 20, n) - f;
	if (pos & 1 )
	{
		puts("Ollie wins.");
	}
	else
	{
		puts("Stan wins.");
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	init();
	while (scanf("%lld", &n) != EOF)
	{
		solve();
	}
	//system("pause");
	return 0;
}