#include <iostream>
#include <cstring>
using namespace std;

#define M 11

long long dp[1002][1<<M]={0};
int n,m;

bool ok(int a)
{
	int x = 1;
	int count = 0;
	for (int i = 0; i < m; i++, x <<= 1)
	{
		if (a & x)
			count++;
		else
		{
			if (count & 1)
				return false;
			count = 0;
		}
	}
	return !(count & 1);
}

int init_ok(int i)
{
	int count;
	for(count=m-1;count>=0;)
	{
		if((i>>count)&1)
		{
			if((i>>(count-1))&1)
			{
				count= count-2;
				continue;
			}
			else
			{
				count--;
				return 0;
			}
		}
		else
		{
			if(count==1&&(i&1))
				return 0;
			else
			{
				count--;
				continue;
			}
		}

	}
	return 1;
}

void init()
{
	int count;
	int kongjian = (1<<m)-1;

	for(count=0;count<=kongjian;count++)
	{
		if(ok(count))
			dp[0][count]=1;
	}
}

bool match(int a, int b)
{
	for (int i = 1; i < 1 << m;)
	{
		if (((a & i) == 0) && ((b & i) == 0))
			return false;
		if ((a & i) && (b & i))
		{
			if ((a & (i << 1)) && ((b & (i << 1))))
			{
				i <<= 2;
				continue;
			}
			else
				return false;
		}
		i <<= 1;
	}
	return true;
}



int main()
{
	while(scanf("%d %d",&n,&m),n && m)
	{
	cin>>n>>m;

	int i,shang,xia;
	int kongjian = (1<<m)-1;

	init();

	for(i=1;i<n;i++)
	{
		for(xia = 0;xia<=kongjian;xia++)
		{
			for(shang=0;shang<=kongjian;shang++)
			{
				if(match(shang,xia) )
					dp[i][xia]+=dp[i-1][shang];

			}
		}
	
	}
	cout<<dp[n-1][kongjian]%1000000007<<endl;
	}
	return 0;
}
//两处错误
//shang xia 上下颠倒
//从左到右 从右至左