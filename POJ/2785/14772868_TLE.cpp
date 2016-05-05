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
int sum1[4005*4005];
int n;
map<int,int>hash_m;

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
	hash_m.clear();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			hash_m[-(a[i]+b[j])]++;
		}
	}

	int ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(hash_m[c[i]+d[j]])
			{
				ans += hash_m[c[i]+d[j]];
			}
		}
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}
