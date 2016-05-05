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

	int max;
	for(i=1;i<=M;i++)
	{
		max=0;
		int max_num=0;
		for(j=1;j<i;j++)
		{
			if(eff[j].end<=eff[i].start)
			{
				if(dp[eff[j].end]>max)
				{
					max_num=j;
					max=dp[eff[j].end];
				}				
			}
		}
		dp[eff[i].end]=max+eff[i].ef;
	}
	max=0;
	for(i=1;i<=M;i++)
	{
		if(dp[eff[i].end]>max)
		{
			max=dp[eff[i].end];
		}	
	}
	cout<<max<<endl;

	return 0;
}