#include <iostream>
 
using namespace std;
 
const int N = 3403;
const int M = 12881;
 
int dp[M] = {0};
 
int max(int x, int y)
{
	return x > y ? x : y;
}
 
int main()
{
	int n, m;
	int w[N], d[M];
 
	cin >> n >> m;
 
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> d[i];
	}
 
for (i = 1; i <= n; i++)
	{
		for (int j = m; j >= w[i]; j--)
		{
			dp[j] = max(dp[j-w[i]] + d[i], dp[j]);
		}
	}
 
	cout << dp[m] << endl;
 
	return 0;
}