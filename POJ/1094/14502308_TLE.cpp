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

vector<char>connect[30];
list<char>first;
vector<char>second;
int n,m,time,flag;
int color[30];
int finnish[30];
int start[30];

struct n
{
	int start;
	int finnish;
}node[30];

bool cmp(struct n node1,struct n node2)
{
	return node1.finnish>node2.finnish;
}

void dfs(int i,int round)
{
	if(flag==-1||flag==1)
		return;
	first.push_front(i+'A');
	color[i]=1;
	time=time+1;
	node[i].start=time;

	int j;
	for(j=0;j<connect[i].size();j++)
	{
		if(color[connect[i][j]-'A']==1)
		{
			flag=-1;
			break;
		}
		else
		{
			dfs(connect[i][j]-'A',round);
		}
	}
	time=time+1;
	color[i]=0;
	node[i].finnish=time;

	if(first.size()==n)
	{
		flag=1;
		return;
	}
	first.pop_front();
}

void solve(int round)
{
	int i,j;
	for(i=25;i>=0;i--)
	{
		if(connect[i].size()==0)continue;
		first.clear();
		second.clear();
		memset(color,0,sizeof(color));
		memset(node,0,sizeof(node));
		time=0;

		dfs(i,round);
		if(flag==-1)
		{
			cout<<"Inconsistency found after "<<round<<" relations."<<endl;
			break;
		}
		else if(flag==1)
		{
			int h,k;
			/*for(h=0;h<26;h++)
			{
			if(node[h].finnish==0)continue;
			for(k=0;k<26;k++)
			{
			if(node[k].finnish==0)continue;
			if(node[h].start<node[k].start)
			{
			if(node[h].finnish<node[k].finnish)
			{
			xiaoflag=0;
			break;
			}
			}
			}
			}*/
			int temp=first.size();
			cout<<"Sorted sequence determined after "<<round<<" relations: ";
			int hk;
			for(hk=0;hk<temp;hk++)
			{
				cout<<first.back();
				first.pop_back();
			}
			cout<<"."<<endl;
			break;
		}
	}
}

int main()
{
	int i;
	char test[10];
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n+m==0)
			break;
		for(i=0;i<26;i++)connect[i].clear();
		flag=0;
		for(i=1;i<=m;i++)
		{
			scanf("%s",test);
			connect[test[0]-'A'].push_back(test[2]);
			if(flag==0)
				solve(i);
		}
		if(flag==0)
		{
			cout<<"Sorted sequence cannot be determined."<<endl;
		}
	}
	return 0;
}