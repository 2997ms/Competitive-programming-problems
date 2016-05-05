#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int N = 1000005;

int n,m,k;
int c[N];

struct no{
	int x;
	int y;
}node[N];

bool cmp(const no& n1,const no& n2)
{
	if(n1.x==n2.x)
		return n1.y<n2.y;
	else
		return n1.x<n2.x;
}
int lowbit(int x)
{
	return x&(-x);
}

void update(int x)
{
	while(x <= m)
	{
		c[x] += 1;
		x +=lowbit(x);
	}
}

int getsum(int x)
{
	int sum=0;
	while(x > 0)
	{
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
int main()
{
	int Test,i,j;
	scanf("%d",&Test);
	
	for(j=1;j<=Test;j++)
	{
		memset(c,0,sizeof(c));

		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&node[i].x,&node[i].y);
		}
		sort(node+1,node+k+1,cmp);
		
		long long ans=0;
		
		for(i=1;i<=k;i++)
		{
			update(node[i].y);
			ans += i-getsum(node[i].y);
		}
		cout<<"Test case "<<j<<": ";
		cout<<ans<<endl;
	}
	return 0;
}
