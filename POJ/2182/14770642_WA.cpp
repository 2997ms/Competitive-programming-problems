#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int val[8005];
int check[8005];
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
	memset(check,0,sizeof(check));
	
	for(j=n;j>=1;j--)
	{
		temp=val[j];
		for(i=1;i<=j;i++)
		{
			if(temp<=val[i])
			{
				val[i]++;
			}
		}
		while(check[val[j]]==1)
		{
			val[j]++;
		}
		check[val[j]]=1;
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\n",val[i]);
	}
	return 0;
}
