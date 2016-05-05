#include <iostream>
#include <cstring>
using namespace std;

#define M 12

long long dp[12][1<<M];
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

bool match(int i, int j)
{
	int k;
	for(k = 0; k < m; )
	{
		if((i & (1<<k)) == 0)
		{
			if((j & (1<<k)) == 0)//如果第i行为0，则第j行一定得为1
				return false;
			k ++;
		}
		else
		{
			if(j & (1<<k))
				if(k == m-1 || ((i & (1<<(k+1))) && (j & (1<<(k+1)))) == 0)//我就是在这里倒的霉
					//k == w-1 || ((i & (1<<(k+1))) || (j & (1<<(k+1))))这样就少考虑了一种情况，哎呀，不爽！！
						return false;
				else k +=2;
			else k++;
		}
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