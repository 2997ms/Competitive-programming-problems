#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int dp[500][500];

int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		memset(dp,0,sizeof(dp));
		int len1=a.length();
		int len2=b.length();

		int i,j;

		for(i=0;i<len1;i++)
		{
			for(j=0;j<len2;j++)
			{
				if(a[i]==b[j])
					dp[i+1][j+1]=dp[i][j]+1;
				else
					dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
		}

		cout<<dp[len1][len2]<<endl;
	}
	

	return 0;
}