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

int m;
long long t[305];
long long w[305];

void init()
{
	int i, j;
	t[1] = 1;
	for (i = 2; i <= 300; i++)
	{
		t[i] = t[i - 1] + i;
	}
	for (i = 1; i <= 300; i++)
	{
		long long r = 0;
		for (int k = 1; k <= i; k++)
		{
			r += k*t[k + 1];
		}
		w[i] = r;
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	init();

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N;i++)
	{
		cin >> m;
		cout << i << " " << m << " " << w[m] << endl;
	}

	return 0;
}