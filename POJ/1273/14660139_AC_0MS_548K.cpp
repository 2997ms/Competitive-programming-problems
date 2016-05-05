#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int sum = 201;
const int INF = 99999999;  
int cap[sum][sum],flow[sum][sum],a[sum],p[sum];

int N,M;

void Edmonds_Karp()  
{
	int u,t,start=1,result=0;
	queue <int> s;
	while(s.size())s.pop();

	while(1)
	{
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));

		a[1]=INF;
		s.push(1);

		while(s.size())
		{
			u=s.front();
			s.pop();

			for(t=1;t<=M;t++)
			{
				if(!a[t]&&flow[u][t]<cap[u][t])
				{
					s.push(t);
					p[t]=u;
					a[t]=min(a[u],cap[u][t]-flow[u][t]);//要和之前的那个点，逐一比较，到M时就是整个路径的最小残量
				}
			}
		}
		if(a[M]==0)
			break;
		result += a[M];

		for(u=M;u!=1;u=p[u])
		{
			flow[p[u]][u] += a[M];
			flow[u][p[u]] -= a[M]; 
		}
	}
	cout<<result<<endl;
}

int main()
{
	int i,u,v,value;
	while(scanf("%d%d",&N,&M)==2)
	{
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));

		for(i=1;i<=N;i++)
		{
			scanf("%d%d%d",&u,&v,&value);
			cap[u][v] += value;
		}
		Edmonds_Karp();  
	}
	return 0;
}
