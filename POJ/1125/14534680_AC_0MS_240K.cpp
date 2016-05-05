#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num;
int dis[105][105];
int dis_max[105];

void init()
{
	int i,j;
	for(i=1;i<=num;i++)
	{
		for(j=1;j<=num;j++)
		{
			if(i==j)
			{
				dis[i][j]=0;
			}
			else
			{
				dis[i][j]=1005;
			}
		}
	}
}
int main()
{
	int i,j,k,i_num;
	while(cin>>num)
	{
		if(num==0)
			break;
		init();
		for(i=1;i<=num;i++)
		{
			cin>>i_num;
			int x,x_dis;
			for(j=1;j<=i_num;j++)
			{
				cin>>x>>x_dis;
				dis[i][x]=x_dis;
			}
		}
		for(k=1;k<=num;k++)
		{
			for(i=1;i<=num;i++)
			{
				for(j=1;j<=num;j++)
				{
					if(dis[i][k]+dis[k][j]<dis[i][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		for(i=1;i<=num;i++)
		{
			dis_max[i]=0;
			for(k=1;k<=num;k++)
			{
				if(k==i)continue;
				dis_max[i]=max(dis_max[i],dis[i][k]);
			}
		}
		int max_one=1005,max_c=0;
		for(i=1;i<=num;i++)
		{
			if(dis_max[i]<max_one&&dis_max[i]<=1001)
			{
				max_one=dis_max[i];
				max_c=i;
			}
		}
		if(max_c==0)
		{
			cout<<"disjoint"<<endl;
		}
		else
		{
			cout<<max_c<<" "<<max_one<<endl;
		}
	}
	return 0;
}
