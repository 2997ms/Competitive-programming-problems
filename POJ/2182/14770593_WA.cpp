#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int val[8005];
int n,i,j,temp;

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	scanf("%d",&n);
	
	val[1]=0;
	for(i=2;i<=n;i++)
	{
		scanf("%d",val+i);
	}
	for(j=n;j>=1;j--)
	{
		temp=val[j];
		for(i=j;i>=1;i--)
		{
			if(temp<=val[i])
			{
				val[i]++;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\n",val[i]);
	}
	return 0;
}
