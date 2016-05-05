#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996) 
using namespace std;

int value[150][150];

int main()
{
	int N,i,j,h,k,g,f;
	int ans=-100;
	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&value[i][j]);
			if(value[i][j]>ans)
				ans=value[i][j];
		}
	}

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			for(h=i+1;h<=N;h++)
			{
				for(k=j+1;k<=N;k++)
				{
					int s=0;
					for(g=i;g<=h;g++)
						for(f=j;f<=k;f++)
							s += value[g][f];
					if(s>ans)
						ans=s;
				}
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}