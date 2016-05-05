#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int dis[50002];

int main()
{
	int n,i,min,min_x,pre,sum;
	cin>>n;

	dis[0]=0;
	min=1000000000;
	for(i=1;i<=n-1;i++)
	{
		cin>>dis[i];
		if(i==n-1)
			sum=dis[i];
		if(dis[i]-dis[i-1]<min)
		{
			min=dis[i]-dis[i-1];
			min_x=i;
		}
	}
	if(n>=4)
	{
		cout<<sum+min<<endl;
		cout<<min_x+1<<" "<<1<<" "<<n<<" "<<min_x<<endl;
	}
	else
	{
		cout<<0;
	}
	return 0;
}