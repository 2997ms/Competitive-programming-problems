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

const int mod = 1e9;

int n;
int dp[1000001];

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int i;
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	for (i = 2; i <= n; i++)
	{
		if (i & 1)
			dp[i] = dp[i - 1];
		else
			dp[i] = (dp[i - 1] + dp[i >> 1]) % mod;
	}
	cout << dp[n] << endl;
	//system("pause");
	return 0;
}