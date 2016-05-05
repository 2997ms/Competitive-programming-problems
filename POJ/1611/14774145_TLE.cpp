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
int son[30002];

set <int> son2[30002];
set <int>::iterator s;

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
	son[pre_x]=pre_y;
	for(s = son2[pre_y].begin(); s!= son2[pre_y].end(); s++)
	{
		son2[pre_x].insert(*s);
	}
}

int findson(int x)
{
	int res = 0;
	while(x!=son[x])
	{
		res++;
		x=son[x];
	}
	return res;
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
			son[i]=i;
			son2[i].clear();
			son2[i].insert(i);
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
		printf("%d\n",son2[0].size());
	}

	//system("pause");
	return 0;
}
