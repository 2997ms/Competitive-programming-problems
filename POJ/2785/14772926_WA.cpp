#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int a[4005],b[4005],c[4005],d[4005];
int sum1[4005*4005],sum2[4005*4005];
int n;

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,j;
	
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
	}

	int num1=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			sum1[++num1] = -(a[i]+b[j]);
			sum2[num1] = (c[i]+d[j]);
		}
	}
	sort(sum1+1,sum1+1+num1);
	sort(sum2+1,sum2+1+num1);

	int ans=0;
	for(i=1;i<=num1;i++)
	{
		int left=1;
		int right = num1;
		int mid;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(sum2[i]<=sum1[mid])
			{
				right=mid-1;
			}
			else
			{
				left= mid+1;
			}
		}
		while(sum2[i]==sum1[left])
		{
			ans++;
			left++;
		}
	}

	printf("%d\n",ans);
	//system("pause");
	return 0;
}
