#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int n,m;
char state[15][15];
long long result[15][(1<<13)-1];

bool pend_ok(int pend,char row[])
{
	int i;
	for(i=n;i>=1;i--)
	{
		int wei =pend & 1;
		if(row[i]=='0'&&wei==1)//11001
		{
			return false;
		}

		pend = pend>>1;
		
		int wei2=pend&1;
		
		if(wei&&wei2)
			return false;
	}
	return true;
}

bool pend(int j,int k )
{
	int i;
	for(i=1;i<=n;i++)
	{
		int wei1 = j&1;
		int wei2 = k&1;

		if(wei1==1&&wei2==1)
		{
			return false;
		}
		j=j>>1;
		k=k>>1;
	}
	return true;
}

int main()
{

	
	int i,j,k;
	cin>>m>>n;

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf_s(" %c ",&state[i][j]);
		}
	}

	int n1=(1<<n)-1;

	memset(result,0,sizeof(result));

	for(j=0;j<=n1;j++)
	{
		if(pend_ok(j,state[1]))
		{
			result[1][j]=1;
		}
	}

	for(i=2;i<=m;i++)
	{
		for(j=0;j<=n1;j++)
		{
			for(k=0;k<=n1;k++)
			{
				if(pend_ok(k,state[i-1])&&pend_ok(j,state[i])&&pend(j,k))
				{
					result[i][j] += result[i-1][k];
				}
			}
		}
	}
	int max=0;
	for(j=0;j<=n1;j++)
	{
		max +=result[m][j];
	}
	
	cout<<max%100000000<<endl;

	return 0;
}
