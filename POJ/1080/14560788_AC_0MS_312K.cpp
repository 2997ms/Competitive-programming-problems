#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int matrix[5][5]={{5,-1,-2,-1,-3},
	              {-1,5,-3,-2,-4},
                  {-2,-3,5,-2,-2},
                  {-1,-2,-2,5,-1},
                  {-3,-4,-2,-1,0}
};
map<char,int>pair1;
int num1,num2;
char test1[150],test2[150];
int dp[150][150];

void cal()
{
	memset(dp,0,sizeof(dp));

	int i,j;
	for(i=0;i<num1;i++)
	{
		dp[i+1][0]=dp[i][0]+matrix[pair1[test1[i]]][pair1['-']];
	}
	for(j=0;j<num2;j++)
	{
		dp[0][j+1]=dp[0][j]+matrix[pair1['-']][pair1[test2[j]]];
	}
	for(i=0;i<num1;i++)
	{
		for(j=0;j<num2;j++)
		{
			dp[i+1][j+1]= max(dp[i][j]+matrix[pair1[test1[i]]][pair1[test2[j]]],
				              max(dp[i][j+1]+matrix[pair1[test1[i]]][pair1['-']],dp[i+1][j]+matrix[pair1['-']][pair1[test2[j]]]));
		}
	}
	cout<<dp[num1][num2]<<endl;
}

int main()
{	
	pair1['A']=0;
	pair1['C']=1;
	pair1['G']=2;
	pair1['T']=3;
	pair1['-']=4;

	int Test;
	scanf("%d",&Test);

	while(Test--)
	{
		cin>>num1>>test1;
		cin>>num2>>test2;
		
		cal();
	}
	return 0;
}
