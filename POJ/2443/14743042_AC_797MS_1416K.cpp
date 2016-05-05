#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int a[32][10001];
int n,q;

int main()
{
	int i,j,f,h,k,num;
	bool flag;
	memset(a,0,sizeof(0));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&f);
		h=i%32;
		k=i/32;
		for(j=1;j<=f;j++)
		{
			scanf("%d",&num);
			a[h][num] = a[h][num]|(1<<k);
		}
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&h,&k);
		flag=false;
		for(j=0;j<32;j++)
		{
			if(a[j][h]&a[j][k])
			{
				flag=true;
				break;
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
  
	return 0;
}
