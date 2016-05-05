#include <iostream>
#include <cstring>
using namespace std;

#define M 12

long long dp[12][1<<M];
int n,m;

int init_ok(int i)
{
	for(int k = 0 ; k <m; )
	{
		if(i & (1<<k))
		{
			if(k == m-1 || !(i & (1<<(k+1))))
				return false;

			k+= 2;
		}
		else k ++;
	}
	return true;
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

	while(scanf_s("%d%d",&n,&m),n&&m)
	{
		int i,shang,xia;
		int kongjian = (1<<m)-1;

		if(n < m)//将状态数取小，优化处理
			i = n ,n = m,n =i;
		
		int k,j;
		memset(dp,0,sizeof(dp));

		for(i = 0 ; i <= kongjian; i++)//初始化第1行
		{
			if(init_ok(i))
				dp[n][i] =1;
		}
		for(k = n-1 ; k >=1; k --)//枚举第k行
		{
			for(i = 0 ; i <= kongjian; i++)//当前行的状态
			{
				for(j = 0; j <= kongjian ;j++)//前一行的状态
				{
					if(match(i,j))
						dp[k][i] +=dp[k+1][j];
				}
			}
		}
		cout<<dp[1][kongjian]<<endl;
	}

	return 0;
}