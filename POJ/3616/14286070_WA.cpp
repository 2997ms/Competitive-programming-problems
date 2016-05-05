#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int start;
	int end;
	int ef;
}eff[1005];

int dp[1000005];
//int dp[105];
bool cmp(struct node node1,struct node node2)
{
	if(node1.start==node2.start)
		return node1.end<node2.end;
	else
		return node1.start<node2.start;
}

int main()
{
	int N,M,R;
	cin>>N>>M>>R;

	int i,j;
	for(i=1;i<=M;i++)
	{
		cin>>eff[i].start>>eff[i].end>>eff[i].ef;
		eff[i].end+=R;
	}
	sort(eff+1,eff+M+1,cmp);

	memset(dp,0,sizeof(dp));

	for(i=1;i<=M;i++)
	{
		dp[eff[i].end]=eff[i].ef;
	}

	for(i=1;i<=M;i++)
	{
		dp[eff[i].end]=max(dp[eff[i].end],dp[eff[i].start]+eff[i].ef);

		for(j=eff[i].end;j<=N;j++)
			dp[j]=max(dp[j],dp[eff[i].end]);

	}
	cout<<dp[eff[M].end]<<endl;


	return 0;
}