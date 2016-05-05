#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

char chess[15][15];
char test[15][15];
int m,n,flag;
vector<char>kefang[15][15];

bool pend(int row,int col,char value)
{
	int i,j,temp1,temp2;
	if(row%3==0)
		temp1=row/3;
	else
		temp1=row/3+1;
	if(col%3==0)
		temp2=col/3;
	else
		temp2=col/3+1;
	for(i=(temp1-1)*3+1;i<=temp1*3;i++)
	{
		for(j=(temp2-1)*3+1;j<=temp2*3;j++)
		{
			if(i==row&&j==col)continue;
			if(value==test[i][j])return false;
		}
	}

	for(i=1;i<=9;i++)
	{
		if( i!=col && value==test[row][i])
			return false;
	}
	for(i=1;i<=9;i++)
	{
		if( i!=row && value==test[i][col])
			return false;
	}

	return true;
}

void find(int i_r,int j_r)
{
	if(j_r==1)
	{
		for(m=i_r-1;m>=1;m--)
		{
			for(n=9;n>=1;n--)
			{
				if(chess[m][n]=='0')
					return;
			}
		}
	}
	else
	{
		m=i_r;
		for(n=j_r-1;n>=1;n--)
		{
			if(chess[m][n]=='0')
				return;
		}
		for(m=i_r-1;m>=1;m--)
		{
			for(n=9;n>=1;n--)
			{
				if(chess[m][n]=='0')
					return;
			}
		}
	}
	m=0;
	n=0;
}

void dfs(int i,int j,char u)
{
	if(flag)
		return;
	test[i][j]=u;

	if(i<=1&&j<=1)
	{
		int h,k;
		for(h=1;h<=9;h++)
		{
			for(k=1;k<=9;k++)
			{
				chess[h][k]=test[h][k];
			}
		}
		flag=1;
		return;
	}

	find(i,j);
	char temp_c;
	int m_temp=m;
	int n_temp=n;
	int size=kefang[m_temp][n_temp].size();
	int xu;
	for(xu=0;xu<size;xu++)
	{
		temp_c=kefang[m_temp][n_temp][xu];
		if(pend(m_temp,n_temp,temp_c))
		{
			dfs(m_temp,n_temp,temp_c);
		}
	}
	if(m==0&&n==0)
	{
		int h,k;
		for(h=1;h<=9;h++)
		{
			for(k=1;k<=9;k++)
			{
				chess[h][k]=test[h][k];
			}
		}
		flag=1;
		return;
	}

	test[i][j]='0';
}

void solve()
{		
	char temp_c;
	int i,j;
	for(i=9;i>=1;i--)
	{
		for(j=9;j>=1;j--)
		{
			if(chess[i][j]=='0')
			{
				int size=kefang[i][j].size();
				int xu;
				for(xu=0;xu<size;xu++)
				{
					temp_c=kefang[i][j][xu];
					if(pend(i,j,temp_c))
					{
						dfs(i,j,temp_c);
						if(flag)
							return;
					}
				}
			}
		}
	}

}

void init()
{
	int g,d;
	for(g=1;g<=9;g++)
	{
		for(d=1;d<=9;d++)
		{
			char temp_c;
			for(temp_c='1';temp_c<='9';temp_c++)
			{
				if(pend(g,d,temp_c))
				{
					kefang[g][d].push_back(temp_c);
				}
			}
		}
	}
}

int main()
{

	int Test,i,j;
	scanf("%d",&Test);

	while(Test--)
	{
		for(i=1;i<=9;i++)
		{
			scanf("%s",chess[i]+1);
			for(j=1;j<=9;j++)
			{
				test[i][j]=chess[i][j];
			}
		}
		for(i=1;i<=9;i++)
			for(j=1;j<=9;j++)
				kefang[i][j].clear();
		flag=0;
		init();
		solve();
		for(i=1;i<=9;i++)
		{
			cout<<chess[i]+1<<endl;
		}
	}

	//system("pause");
	return 0;
}
