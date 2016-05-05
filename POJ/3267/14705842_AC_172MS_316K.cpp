#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int W, L;
string message;
string word[605];
int len[605];
int dp[305];

int main()
{	
	int i, j, k;
	cin >> W >> L;
	cin >> message;

	for (i = 1; i <= W; i++)
	{
		cin >> word[i];
		len[i] = word[i].length();
	}
	for (i = 0; i < L; i++)
	{
		if (i == 0)
			dp[0] = 1;
		else
			dp[i] = dp[i - 1] + 1;
		
		for (k = 1; k <= W; k++)
		{
			int subs = len[k] - 1;
			int temp = i;
			if (subs > i)
				continue;
			while (subs >= 0 && temp >= 0 && temp>=subs)
			{
				if (message[temp] == word[k][subs])
					subs--;
				temp--;
			}
			if (subs < 0)
			{
				dp[i] = min(dp[i],i-temp-len[k]+dp[temp]);
			}
		}
	}
	cout << dp[i - 1] << endl;
	return 0;
}