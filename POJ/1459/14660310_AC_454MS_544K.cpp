#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int sum = 200;
const int INF = 99999999;  
int cap[sum][sum],flow[sum][sum],a[sum],p[sum];

int n,np,nc,m;

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

			for(t=0;t<=n+1;t++)
			{
				if(!a[t]&&flow[u][t]<cap[u][t])
				{
					s.push(t);
					p[t]=u;
					a[t]=min(a[u],cap[u][t]-flow[u][t]);//要和之前的那个点，逐一比较，到M时就是整个路径的最小残量
				}
			}
		}
		if(a[n+1]==0)
			break;
		result += a[n+1];

		for(u=n+1;u!=0;u=p[u])
		{
			flow[p[u]][u] += a[n+1];
			flow[u][p[u]] -= a[n+1]; 
		}
	}
	cout<<result<<endl;
}

int main()
{	
	int i,u,v,value;
	char *temp=NULL;
	
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)==4)
	{
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));

		for(i=1;i<=m;i++)
		{
			scanf(" (%d,%d)%d",&u,&v,&value);
			//scanf("%s",&temp);
			//sscanf(temp,"(%d,%d)%d",&u,&v,&value);
			cap[u+1][v+1] += value;
		}
		for(i=1;i<=np;i++)
		{
			//scanf("%s",temp);
			//sscanf(temp,"(%d)%d",&u,&value);
			scanf(" (%d)%d",&u,&value);
			cap[0][u+1] += value;
		}
		for(i=1;i<=nc;i++)
		{
			//scanf("%s",temp);
			//sscanf(temp,"(%d)%d",&v,&value);
			scanf(" (%d)%d",&v,&value);
			cap[v+1][n+1] += value;
		}
		Edmonds_Karp();  
	}
	return 0;
}
