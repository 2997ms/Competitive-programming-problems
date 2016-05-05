#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int base;
string num;
string m;

int change(string n)
{
	int i;
	int sum = 0;
	int len = n.length();

	for (i = 0; i < len; i++)
	{
		sum = sum*base + n[i] - '0';
	}
	return sum;
}

void res(int mod)
{
	int i, n, a[500];
	int len = num.length();
	int res = 0;

	for (i = 0; i < len; i++)
	{
		res = (res*base + num[i] - '0') % mod;
	}
	//转换成base进制
	n = 0;
	if (res != 0)
	{
		while (res != 0)
		{
			a[n++] = res % base;
			res = res / base;
		}
		//printf("%d\n",res);
		for (i = n - 1; i >= 0; i--)
		{
			printf("%d", a[i]);
		}
	}
	else
	{
		printf("0");
	}
	printf("\n");
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int mod;
	while (cin >> base)
	{
		if (base == 0)
			break;
		cin >> num >> m;
		mod = change(m);

		res(mod);
	}
	//system("pause");
	return 0;
}