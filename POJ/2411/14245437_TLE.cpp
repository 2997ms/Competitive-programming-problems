#include <iostream>
#include <cstring>
using namespace std;

#define M 11

long long dp[1002][1<<M];
int n,m;

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

	memset(dp,0,sizeof(dp));

	for(count=0;count<=kongjian;count++)
	{
		if(init_ok(count))
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

	while(scanf_s("%d %d",&n,&m),n &&m)
	{
		int i,shang,xia;
		if(n < m)//将状态数取小，优化处理
			i = n ,n = m,m =i;
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

		cout<<dp[n-1][kongjian]<<endl;
	}

	return 0;
}