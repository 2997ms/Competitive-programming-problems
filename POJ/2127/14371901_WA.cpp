#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int dp[505][505];
vector <int> same;

int main()
{
	int s[505],t[505];
	int len1,len2;
	int i,j;

	memset(dp,0,sizeof(dp));

	cin>>len1;
	for(i=1;i<=len1;i++)
		cin>>s[i];

	cin>>len2;
	for(i=1;i<=len2;i++)
		cin>>t[i];

	same.clear();

	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(s[i]==t[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				same.push_back(s[i]);
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	cout<<dp[len1-1][len2-1]<<endl;
	for(i=1;i<dp[len1-1][len2-1];i++)
		cout<<same[i]<<" ";
	cout<<endl;

	return 0;
}