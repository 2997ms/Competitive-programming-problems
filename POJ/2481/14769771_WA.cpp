#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int n;
int ans[100005];
int cnt[100005];

struct no
{
	int s,e;
	int pos;
}node[100005];

bool cmp(no n1,no n2)
{
	if(n1.e == n2.e)
	{
		return n1.s>n2.s;
	}
	else
	{
		return n1.e>n2.e;
	}
}

int lowbit(int x)
{
	return x&(-x);
}

void add(int x)
{
	while(x<=n)
	{
		ans[x]++;
		x=x+lowbit(x);
	}
}

int sum(int x)
{
	int res=0;
	while(x>0)
	{
		res+=ans[x];
		x=x-lowbit(x);
	}
	return res;
}

int main()
{
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&node[i].s,&node[i].e);
			node[i].pos=i;
		}
		memset(ans,0,sizeof(ans));
		memset(cnt,0,sizeof(cnt));
		sort(node+1,node+n+1,cmp);
		
		for(i=1;i<=n;i++)
		{
			if(node[i].e == node[i-1].e && node[i].s == node[i-1].s)
			{
				cnt[node[i].pos] = cnt[node[i-1].pos];
			}
			else
			{
				cnt[node[i].pos] = sum(node[i].s+1);
			}
			add(node[i].s+1);
		}
		
		for(i=1;i<=n;i++)
		{
			if(i==1)
			{
				printf("%d",cnt[1]);
			}
			else
			{
				printf(" %d",cnt[i]);
			}
		}
		printf("\n");
	}
	return 0;
}