#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[40002];

struct Node{
	int h;
	int cant;
	int num;
}node[500];

bool cmp(Node no1,Node no2)
{
	return no1.cant < no2.cant;
}


int main()
{
	int count;
	int i;
	int sum[40002][7];
	cin>>count;
	for(i=1;i<=count;i++)
	{
		cin>>node[i].h>>node[i].cant>>node[i].num;
	}
	sort(node+1,node+1+count,cmp);

	memset(sum,0,sizeof(sum));
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	int j,ans=-1;
	for(i=1;i<=count;i++)
	{
		for(j=0;j<=node[i].cant;j++)
		{
			if(!dp[j]&&dp[j-node[i].h]&&sum[j-node[i].h][i]<node[i].num)
			{
				sum[j][i] = sum[j-node[j].h][i]+1;
				dp[j]=1;
				if(j>ans)
					ans=j;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}