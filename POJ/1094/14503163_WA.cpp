#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#pragma warning(disable:4996)
using namespace std;

int connect[30][30],indegree[30];
int queue[30];
int n,m,flag;

//我考虑的状况全是多余，不去想的情况全是考点

int solve()
{
	int i,j,loc,m,num=0,temp[30];
	for(i=1;i<=n;i++)
	{
		temp[i]=indegree[i];
	}

	for(j=1;j<=n;j++)
	{
		m=0;
		for(i=1;i<=n;i++)
		{
			if(temp[i]==0)
			{
				m++;
				loc=i;
			}
		}
		if(m==0)
			return -1;
		else if(m>1)
		{
			return 0;
		}
		queue[++num]=loc;
		temp[loc]=-1;
		for(i=1;i<=n;i++)
		{
			if(connect[loc][i]==1)
				temp[i]--;
		}
	}
	if(num==n)
		return 1;
	else
		return 0;
}

int main()
{
	int i;
	char test[10];
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n+m==0)
			break;

		flag=0;
		memset(indegree,0,sizeof(indegree));
		memset(connect,0,sizeof(connect));
		memset(queue,0,sizeof(queue));

		for(i=1;i<=m;i++)
		{
			scanf("%s",test);

			int x=test[0]-'A'+1;
			int y=test[2]-'A'+1;

			indegree[y]++;
			connect[x][y]=1;

			int result;
			if(flag==0)
			{
				result=solve();

				if(result==-1)
				{
					flag=-1;
					cout<<"Inconsistency found after "<<i<<" relations."<<endl;
				}
				else if(result==1)
				{
					flag=1;
					cout<<"Sorted sequence determined after "<<i<<" relations: ";
					int hk;
					for(hk=1;hk<=n;hk++)
					{
						char temp=queue[hk]+'A'-1;
						cout<<temp;
					}
					cout<<"."<<endl;
				}
			}
		}
		if(flag==0)
		{
			cout<<"Sorted sequence cannot be determined."<<endl;
		}
	}
	return 0;
}