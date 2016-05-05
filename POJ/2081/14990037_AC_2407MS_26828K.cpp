#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

long long a[500005];
map<long long, int>vis;

void init()
{
	a[0] = 0;
	
	int i;
	for (i = 1; i <= 500000; i++)
	{
		if (a[i - 1] - i > 0 && vis[a[i - 1] - i] == 0)
		{
			a[i] = a[i - 1] - i;
			vis[a[i]] = 1;
		}
		else
		{
			a[i] = a[i - 1] + i;
			vis[a[i]] = 1;
		}
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	init();
	
	int k;
	while (cin >> k)
	{
		if (k == -1)
			break;
		cout << a[k] << endl;
	}
	return 0;
}