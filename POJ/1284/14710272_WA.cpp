#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int euler(int n)
{
	int res = n, a = n;
	for (int i = 2; i*i < a; i++)
	{
		if (a%i == 0)
		{
			res = res / i*(i - 1);
			while (a%i == 0)a /= i;
		}
	}
	if (a > 1)res = res / a*(a - 1);
	return res;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		cout << euler(n-1) << endl;
	}
	return 0;
}