#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;
typedef long long ll;

ll n;

void solve()
{
	n = n % 18 + 1;
	if (n <= 9)
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

	while (scanf("%lld", &n)!=EOF)
	{
		solve();
	}
	//system("pause");
	return 0;
}