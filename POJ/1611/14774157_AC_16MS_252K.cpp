#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#pragma warning(disable:4996)
using namespace std;

int n,m;
int pre[30002];

int findpre(int x)
{
	while(x!=pre[x])
	{
		x=pre[x];
	}
	return x;
}

void union_set(int x,int y)
{
	int pre_x = findpre(x);
	int pre_y = findpre(y);

	if(pre_x == pre_y)
		return;
	else if(pre_x>pre_y)
	{
		int temp = pre_x;
		pre_x = pre_y;
		pre_y = temp;
	}

	pre[pre_y]=pre_x;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,j,num,temp1,temp;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			pre[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d",&num);
			for(j=1;j<=num;j++)
			{
				if(j==1)
				{
					scanf("%d",&temp1);
					continue;
				}
				else
				{
					scanf("%d",&temp);
					union_set(temp,temp1);
				}
			}
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
			if(findpre(i)==0)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}

	//system("pause");
	return 0;
}
