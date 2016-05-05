#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int color[100005];
int dis[100005];

queue<int> q;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int N,K;
	cin>>N>>K;
	
	if(N==K)
	{
		cout<<0<<endl;
	}
	else
	{
		memset(color,0,sizeof(color));
		memset(dis,0,sizeof(dis));

		q.push(N);
		while(!q.empty())
		{
			N=q.front();
			q.pop();
			if(N-1==K || N+1==K || 2*N==K)
			{
				cout<<dis[N]+1<<endl;
				break;
			}

			if(color[N-1]==0 && N-1>=0)
			{
				color[N-1]=1;
				dis[N-1]=dis[N]+1;
				q.push(N-1);
			}
			if(color[N+1]==0)
			{
				color[N+1]=1;
				dis[N+1]=dis[N]+1;
				q.push(N+1);
			}
			if(color[2*N]==0)
			{
				color[2*N]=1;
				dis[2*N]=dis[N]+1;
				q.push(2*N);
			}
		}
	}

	return 0;
}
