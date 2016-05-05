#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n,ans;
int flag[25];
int val[25][25];

void dfs(int step,int dir)
{
	flag[step]=dir;
	
	if(step==n)
	{
		int i,j,temp_ans,temp_max;
		temp_ans=0;
		
		for(i=1;i<=n;i++)
		{
			temp_max=0;
			for(j=1;j<=n;j++)
			{
				if(flag[i]==1)continue;
				if(i==j||flag[i]==flag[j])continue;
				temp_max=max(temp_max,val[i][j]);
			}
			temp_ans += temp_max;
		}
		ans=max(ans,temp_ans);

		temp_ans=0;
		for(i=1;i<=n;i++)
		{
			temp_max=0;
			for(j=1;j<=n;j++)
			{
				if(flag[i]==2)continue;
				if(i==j||flag[i]==flag[j])continue;
				temp_max=max(temp_max,val[i][j]);
			}
			temp_ans += temp_max;
		}
		ans=max(ans,temp_ans);
		return;
	}
	dfs(step+1,1);
	dfs(step+1,2);
}

int main()
{
	int i,j;
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&val[i][j]);
		}
	}
	ans=0;
	dfs(1,1);
	dfs(1,2);

	cout<<ans<<endl;
	return 0;
}
