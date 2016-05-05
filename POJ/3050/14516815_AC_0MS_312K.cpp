#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int value[7][7];
vector<int>road;

void dfs(int i,int j,int step,int test)
{
	if(step==6)
	{
		test = test*10+value[i][j];
		road.push_back(test);
		return;
	}
	test = test*10+value[i][j];

	if(i>1)
	{
		dfs(i-1,j,step+1,test);
	}
	if(j>1)
	{
		dfs(i,j-1,step+1,test);
	}
	if(i<5)
	{
		dfs(i+1,j,step+1,test);
	}
	if(j<5)
	{
		dfs(i,j+1,step+1,test);
	}
}

int main()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			cin>>value[i][j];
		}
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			dfs(i,j,1,0);
		}
	}
	sort(road.begin(), road.end());
	vector<int>::iterator iter =unique(road.begin(),road.end());
	road.erase(iter,road.end());

	cout<<road.size()<<endl;
	return 0;
}
