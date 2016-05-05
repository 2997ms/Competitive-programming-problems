#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int num[20005];

int main()
{	
	int N,S,i,j;
	scanf("%d%d",&N,&S);
	int result=0;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&num[i]);
	}

	sort(num+1,num+N+1);

	for(i=1;i<=N;i++)
	{
		for(j=1;j<i;j++)
		{
			if(num[i]+num[j]<=S)
			{
				result++;
			}
			else
			{
				break;
			}
		}
	}

	printf("%d\n",result);

	return 0;
}