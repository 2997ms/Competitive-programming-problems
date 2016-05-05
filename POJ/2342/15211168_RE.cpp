#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
int n;
bool vis[6005];
int dp[6005][2], pre[6005];
using namespace std;
void tree_dp(int x)
{
	vis[x] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && pre[i] == x)
		{
			tree_dp(i);
			dp[x][1] += dp[i][0];
			dp[x][0] += max(dp[i][0], dp[i][1]);
		}
	}
}
int find(int x)
{
	int r = x;
	while (pre[r])
		r = pre[r];
	return r;
}
int main()
{
	while (cin >> n)
	{
		int a, b, q;
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		for (int i = 1; i <= n; i++)
		{
			cin >> dp[i][1];
		}
		while (cin >> a >> b)
		{
			//cin>>a>>b;
			if (a == 0 && b == 0)
				break;
			pre[a] = b;
			q = a;
		}
		// cout<<q<<endl;
		int t = find(q);
		// cout<<t<<endl;
		//for(int i=1;i<=n;i++)
		//cout<<pre[i]<<endl;
		tree_dp(t);
		cout << max(dp[t][0], dp[t][1]) << endl;

	}
	return 0;
}