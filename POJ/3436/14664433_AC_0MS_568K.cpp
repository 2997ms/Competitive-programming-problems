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
int cap[sum][sum],flow[sum][sum],in[sum][sum],a[sum],p[sum];

int p2,n;

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
	cout<<result<<" ";
}

int main()
{
	int i,j,k,u,v,value;
	while(scanf("%d%d",&p2,&n)==2)
	{
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));

		for(j=0;j<=2*p2+1;j++)
		{
			in[0][j]=0;
			in[n+1][j]=1;
		}

		for(i=1;i<=n;i++)
		{
			for(j=0;j<2*p2+1;j++)
			{
				scanf("%d",&in[i][j]);
			}
		}
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=n+1;j++)
			{
				if(i==j)continue;

				bool f = true;
				for(k=1;k<=p2;k++)
				{
					if(!(in[j][k]==2||in[i][k+p2]==in[j][k]))
						f=false;
				}
				if(f&&i==0)
				{
					cap[i][j]=in[j][0];
				}
				else if(f&&j==n+1)
				{
					cap[i][j]=in[i][0];
				}
				else if(f)
				{
					cap[i][j]+=min(in[i][0],in[j][0]);
				}
			}
		}
		Edmonds_Karp();  

		int cnt=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(flow[i][j]>0)
					cnt++;
			}
		}
		cout<<cnt<<endl;

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(flow[i][j]>0)
				{
					cout<<i<<" "<<j<<" "<<flow[i][j]<<endl;
				}
			}
		}
	}
	return 0;
}

