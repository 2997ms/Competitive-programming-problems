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
	cin>>count;
	for(i=1;i<=count;i++)
	{
		cin>>node[i].h>>node[i].cant>>node[i].num;
	}
	sort(node+1,node+1+count,cmp);

	memset(dp,0,sizeof(dp));
	int j,k,ans=0;
	for(i=1;i<=count;i++)
	{
		for(j=node[count].cant;j>=0;j--)
		{
			int num = 0;
			for(k=0;k<=node[i].num;k++)
			{	
				if(j-k*node[i].h<0)
			         break;
				if(j-k*node[i].h>=0&&max(dp[j],dp[j-k*node[i].h]+k*node[i].h)<=node[i].cant)
					dp[j]=max(dp[j],dp[j-k*node[i].h]+k*node[i].h);
				if(dp[j]>ans)
					ans = dp[j];
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}