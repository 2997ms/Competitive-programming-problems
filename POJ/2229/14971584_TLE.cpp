#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
#include <map>
#include <cstdio>
#include <stdio.h>
using namespace std;
typedef long long ll;

ll res;
int n;
int dp[25];

void init()
{
	int i, j, k;
	dp[1] = 1;
	for (i = 2; i <= 22; i++)
	{
		dp[i] = dp[i - 1] * 2;
	}
}

void dfs(int k, int x)
{
	if (k == 0)
		return;
	if (x > n)
		return;
	if (x == n)
	{
		res++;
		return;
	}
	if (x + dp[k] <= n)
	{
		dfs(k, x + dp[k]);
	}
	dfs(k - 1, x);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	init();
	
	cin >> n;
	
	int i;
	for (i = 21; i >= 2; i--)
	{
		if (dp[i] <= n)
			break;
	}
	res = 0;

	dfs(i,0);

	cout << res << endl;
	//system("pause");
	return 0;
}