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
int val[1005];
int flag[1005];
int N,M;

void Edmonds_Karp()  
{
	int u,t,result=0;
	queue <int> s;
	while(s.size())s.pop();

	while(1)
	{
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));

		a[0]=INF;
		s.push(0);

		while(s.size())
		{
			u=s.front();
			s.pop();

			for(t=0;t<=M+1;t++)
			{
				if(!a[t]&&flow[u][t]<cap[u][t])
				{
					s.push(t);
					p[t]=u;
					a[t]=min(a[u],cap[u][t]-flow[u][t]);//要和之前的那个点，逐一比较，到M时就是整个路径的最小残量
				}
			}
		}
		if(a[M+1]==0)
			break;
		result += a[M+1];

		for(u=M+1;u!=0;u=p[u])
		{
			flow[p[u]][u] += a[M+1];
			flow[u][p[u]] -= a[M+1]; 
		}
	}
	cout<<result<<endl;
}

int main()
{
	int i,j,num,out,u,v,value;
	while(scanf("%d%d",&N,&M)==2)
	{
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(flag,0,sizeof(flag));

		for(i=1;i<=N;i++)
		{
			scanf("%d",&val[i]);
		}
		
		for(i=1;i<=M;i++)
		{
			scanf("%d",&num);
			for(j=1;j<=num;j++)
			{
				scanf("%d",&value);
				if(!flag[value])
				{
					flag[value]=i;
					cap[0][i] += val[value];
				}
				else
				{
					cap[flag[value]][i] = INF;
					flag[value]=i;
				}
			}
			scanf("%d",&out);
			cap[i][M+1] += out;
		}
		Edmonds_Karp();  
	}
	return 0;
}
