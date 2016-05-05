#include <iostream>
#include <vector>
using namespace std;

int dp[7][120002];//dp[i][j]代表选第i中宝石时，j是否可能取到
//dp[i][j]=dp[i-1][j-i*x]
int marible[7];
int total=0;

void init()
{
	int count;
	total=0;
	for(count=1;count<=6;count++)
	{
		cin>>marible[count];
		total += marible[count]*count;
	}
}

void cal()
{
	int i,j,x;

	memset(dp,0,sizeof(dp));
	dp[1][0]=1;
	for(i=1;i<=marible[1];i++)
		dp[1][i]=1;

	for(i=2;i<=6;i++)
	{
		for(j=total;j>=0;j--)
		{
			for(x=0;x<=marible[i];x++)
			{
				if(j+x*i>total)
					return ;
				dp[i][j]=dp[i-1][j];
				if(dp[i-1][j])
				{
					dp[i][j+x*i]=dp[i-1][j];
				}

			}
		}
	}

}

int main()
{
	bool end = true;
	int t=0;
	while(end)
	{
		t++;
		cout<<"Collection #"<<t<<":"<<endl;

		init();
		if(total==0)
		{
			return 0;
		}
		if(total%2)
		{
			cout<<"Can't be divided"<<endl<<endl;
		}
		else
		{
			total /=2;
			cal();
			if(dp[6][total])
				cout<<"Can be divided"<<endl<<endl;
			else
				cout<<"Can't be divided"<<endl<<endl;
		}
	}
	return 0;
}