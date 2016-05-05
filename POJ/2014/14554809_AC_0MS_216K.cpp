#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int zong_weight,num;
int weight[20],height[20];

int main()
{	
	int i,sum,length,zong_length,max_weight;
	while(scanf("%d",&zong_weight)==1)
	{
		if(zong_weight==0)
			break;
	    
		num=1;
		sum=0;
		length=0;
		zong_length=0;
		max_weight=0;
		
		while(scanf("%d%d",&weight[num],&height[num])==2)
		{
			if(weight[num]+height[num]==-2)
				break;
			num++;
		}

		for(i=1;i<=num;i++)
		{
			if(sum+weight[i]<=zong_weight)
			{
				sum += weight[i];
				length=max(length,height[i]);
				max_weight=max(max_weight,sum);
			}
			else
			{
				sum=weight[i];
				zong_length += length;
				length=height[i];
			}
		}
		zong_length += length;
		cout<<max_weight<<" x "<<zong_length<<endl;
	}
	return 0;
}
