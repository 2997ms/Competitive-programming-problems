#include <iostream>
using namespace std;

#define  N  11+1
#define  S   (1<<12)
#define  LL  long long
LL dp[N][S];

int kongjian,n,m;

bool Ok(int i)//初始化第1行状态为i时是否容许
{
	int count;
	for(count=m-1;count>0;)
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

bool Pk(int i,int j)//判断i和j状态有无冲突
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
				if(k == m-1 || ((i & (1<<(k+1))) && (j & (1<<(k+1)))) == 0)					
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
		int i,j,k;

		if(n < m)//将状态数取小，优化处理
			i = n ,n = m,m =i;

		kongjian = (1<<m)-1;
		memset(dp,0,sizeof(dp));

		for(i = 0 ; i <= kongjian; i++)//初始化第1行
		{
			if(Ok(i))
				dp[n][i] =1;
		}

		for(k = n-1 ; k >=1; k --)//枚举第k行
		{
			for(j = 0 ; j <= kongjian; j++)//当前行的状态
			{
				for(i = 0; i <= kongjian ;i++)//前一行的状态
				{
					if(Pk(i,j))
						dp[k][i] +=dp[k+1][j];
				}
			}
		}

		cout<<dp[1][kongjian]<<endl;
	}
	return 0;
}