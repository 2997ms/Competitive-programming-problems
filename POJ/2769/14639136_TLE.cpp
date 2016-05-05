#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num;
int Test,flag,i,j;
int bool_1[1000002];
int value[400];

int main()
{
	cin>>Test;

	while(Test--)
	{
		cin>>num;
		for(i=1;i<=num;i++)
		{
			scanf("%d",&value[i]);
		}
		for(i=num;;i++)
		{
			flag=0;
			memset(bool_1,0,sizeof(bool_1));
			for(j=1;j<=num;j++)
			{
				if(bool_1[value[j]%i]==0)
				{
					bool_1[value[j]%i]=1;
				}
				else
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				break;
		}
		cout<<i<<endl;
	}
	return 0;
}
