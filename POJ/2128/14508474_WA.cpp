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
	int n,i,min,min_x,sum;
	cin>>n;

	dis[0]=0;
	min=1000000000;
	for(i=1;i<=n-1;i++)
	{
		cin>>dis[i];
		if(i==n-1)
			sum=dis[i];
		dis[i]=dis[i]-dis[i-1];
		if(dis[i]<min)
		{
			min=dis[i];
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
		cout<<0<<endl;
	}
	return 0;
}
