#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int N,M;
int value[100000];

int solve(int mid)
{
	int i,sum=0,result=1;
	if(mid==501)
		i=1;
	for(i=1;i<=N;i++)
	{
		if(value[i]+sum<=mid)
		{
			sum += value[i];
		}
		else
		{
			sum=value[i];
			result++;
		}
	}
	if(result==M)
	{
		return 0;
	}
	else if(result<M)
	{
		return -1;
	}
	else
		return 1;
}

int main()
{
	int i,sum,max_x;
	cin>>N>>M;

	sum=0;
	max_x=0;
	for(i=1;i<=N;i++)
	{
		cin>>value[i];
		sum += value[i];
		max_x=max(max_x,value[i]);
	}
	
	int mid=(sum+max_x)/2;
	int temp;
	while(1)
	{
		temp=solve(mid);
		if(temp==0)
		{
			cout<<mid<<endl;
			break;
		}
		else if(temp==1)
		{
			mid=(mid+sum)/2;
		}
		else
			mid=(mid+max_x)/2;
	}
	return 0;
}
