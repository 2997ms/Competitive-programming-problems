#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

const int N = 500005;
int n;
int c[N],reflect[N];

struct no{
	int val;
	int pos;
}node[N];

bool cmp(const no& x1,const no& x2)//引用，比方说int&
{
	return x1.val<x2.val;
}

int lowbit(int x)
{
	return x&(-x);
}

void update(int x)
{
	while(x <= n)
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
	int i;

	while(scanf("%d",&n)==1)
	{
		if(n==0)break;
		memset(c,0,sizeof(c));

		for(i=1;i<=n;i++)
		{
			scanf("%d",&node[i].val);
			node[i].pos=i;
		}
		
		sort(node+1,node+n+1,cmp);

		for(i=1;i<=n;i++)
		{
			reflect[node[i].pos]=i;
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			update(reflect[i]);
			ans += i-getsum(reflect[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}