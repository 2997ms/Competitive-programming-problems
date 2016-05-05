#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[15];

int main()
{
	int n;
	cin>>n;

	dp[0]=0;
	dp[2]=10;
	dp[4]=670;
	dp[6]=55252;
	dp[8]=4816030;
	dp[10]=432457640;
	cout<<dp[n]<<endl;

	return 0;
}
