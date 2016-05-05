#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

short int dp[5002][5002];
char b[5002];
string b_reverse;
int num;

void cal()
{
	int i,j,max_value=0;

	memset(dp,0,sizeof(dp));

	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(b[i]==b_reverse[j])
			{
				dp[i+1][j+1]=dp[i][j]+1;
			}
			else
			{
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
			max_value=max(max_value,(int)dp[i+1][j+1]);
		}
	}
	cout<<num-max_value<<endl;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	scanf("%d",&num);
	scanf("%s",b);

	b_reverse=b;
	reverse(b,b+num);

	cal();

	return 0;
}
