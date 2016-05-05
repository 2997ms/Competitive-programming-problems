#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct E{
	int s;
	int e;
	double l;
}edge[5205];

int N,M,W,edge_num;
double dis[505];
map<string,int>name_num;

void addedge(int start,int end,double len)
{
	edge_num++;

	edge[edge_num].s=start;
	edge[edge_num].e=end;
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
			if(dis[edge[j].e]<dis[edge[j].s]*edge[j].l)
			{
				flag=1;
				dis[edge[j].e]=dis[edge[j].s]*edge[j].l;
			}
		}
		if(flag==0)
			break;
	}
	for(j=1;j<=edge_num;j++)
	{
		if(dis[edge[j].e]<dis[edge[j].s]*edge[j].l)
		{
			return true;
		}
	}
	return false;
}

int main()
{	
	int i_num=1;
	int map_i,i;
	
	string temp1,temp2;
	double temp_d;

	while(cin>>N)
	{
		if(N==0)
			break;
		cout<<"Case "<<i_num<<": ";
		
		i_num++;
		name_num.clear();

		for(map_i=1;map_i<=N;map_i++)
		{
			cin>>temp1;
			name_num[temp1]=map_i;
		}
		cin>>M;
		edge_num=0;
		for(i=1;i<=N;i++)
		{
			dis[i]=0;
		}

		for(i=1;i<=M;i++)
		{
			cin>>temp1>>temp_d>>temp2;
			addedge(name_num[temp1],name_num[temp2],temp_d);
		}
		dis[edge[1].s]=100;
		if(bellman_ford())
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}


