#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#pragma warning(disable:4996)
using namespace std;

vector<char>topo[28];
list<char>first;
int flag[28],finnish[28],zongflag;
int n,m,time;

void dfs(int i)
{
	first.push_front(i+'A');
	int j;
	time++;
	for(j=0;j<topo[i].size();j++)
	{
		if(flag[topo[i][j]-'A']<flag[i]&&flag[topo[i][j]-'A']!=0&&0==finnish[topo[i][j]-'A'])
		{
			zongflag=-1;
			return;
		}
		if(flag[topo[i][j]-'A']==0)
		{
			flag[topo[i][j]-'A']=flag[i]+1;
			dfs(topo[i][j]-'A');
		}
	}
	finnish[i]=time;
}

void solve(int round)
{
	//Sorted sequence determined after 4 relations: ABCD.
	//Inconsistency found after 2 relations.
	int i,j,result;
	for(i=0;i<26;i++)
	{
		first.clear();
		result=0;
		time=0;
		memset(flag,0,sizeof(flag));
		memset(finnish,0,sizeof(finnish));

		flag[i]=1;
		dfs(i);
		vector<int>p;
		for(j=0;j<26;j++)
		{
			if(flag[j])
			{
				p.push_back(flag[j]);
				result++;
			}
		}

		if(result==n)
		{
			int flag_p=1;
			sort(p.begin(),p.end());
			for(int o=1;o<p.size();o++)
			{
				if(p[o]-p[o-1]!=1)
				{
					flag_p=0;
				}
			}
			if(flag_p)
				zongflag=1;
			break;
		}
	}
	if(zongflag==-1)
		cout<<"Inconsistency found after "<<round<<" relations."<<endl;
	else if(zongflag==1)
	{
		cout<<"Sorted sequence determined after "<<round<<" relations: ";
		int temp=first.size();
		for(i=0;i<temp;i++)
		{
			cout<<first.back();
			first.pop_back();
		}
		cout<<endl;
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i;
	char test[10];
	while(cin>>n>>m)
	{
		if(n+m==0)
			break;
		for(i=0;i<26;i++)topo[i].clear();
		zongflag=0;
		for(i=1;i<=m;i++)
		{
			scanf("%s",test);
			topo[test[0]-'A'].push_back(test[2]);
			if(zongflag==0)
				solve(i);
		}
		if(zongflag==0)
			cout<<"Sorted sequence cannot be determined."<<endl;
	}
	return 0;
}
