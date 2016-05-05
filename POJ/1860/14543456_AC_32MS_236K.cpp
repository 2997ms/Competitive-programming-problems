#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct E{
	int s;
	int e;
	double com;
	double l;
}edge[5205];

int N,M,S,edge_num;
double V;
double dis[505];

void addedge(int start,int end,double co,double len)
{
	edge_num++;

	edge[edge_num].s=start;
	edge[edge_num].e=end;
	edge[edge_num].com=co;
	edge[edge_num].l=len;
}

bool bellman_ford()
{
	int i,j;
	for(i=1;i<=N-1;i++)
	{
		int flag=0;
		for(j=1;j<=edge_num;j++)
		{
			if(dis[edge[j].e]<(dis[edge[j].s]-edge[j].com)*edge[j].l)
			{
				flag=1;
				dis[edge[j].e]=(dis[edge[j].s]-edge[j].com)*edge[j].l;
			}
		}
		if(flag==0)
			break;
	}

	for(j=1;j<=edge_num;j++)
	{
		if(dis[edge[j].e]<(dis[edge[j].s]-edge[j].com)*edge[j].l)
			return true;
	}

	return false;
}

int main()
{
	int i,start,end;
	double co,len;

	edge_num=0;
	memset(dis,0,sizeof(dis));

	cin>>N>>M>>S>>V;

	for(i=1;i<=M;i++)
	{
		cin>>start>>end>>len>>co;
		addedge(start,end,co,len);

		cin>>len>>co;
		addedge(end,start,co,len);
	}
	dis[S]=V;
	if(bellman_ford())
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}

	return 0;
}

