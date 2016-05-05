#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct node
{
	int start;
	int end;

}node_one[10005];

vector<int>start1;
vector<int>end1;

int N,P,i,j,Q1,Q2,Qmin,Qmax,ans,h;

bool cmp(node node1,node node2)
{
	if(node1.start == node2.start)
		return node1.end< node2.end;

	return node1.start<node2.start;
}

void solve()
{
	int pre_s,pre_e;
	if(P==1)
	{
		start1.push_back(node_one[1].start);
		end1.push_back(node_one[1].end);
		return;
	}
	for(i=1;i<=P;i++)
	{
		if(i==1)
		{			
			pre_s=node_one[1].start;
			pre_e=node_one[1].end;
		}
		else
		{
			if(node_one[i].start>pre_e)
			{
				start1.push_back(pre_s);
				end1.push_back(pre_e);

				pre_s=node_one[i].start;
				pre_e=node_one[i].end;
			}
			else 
			{
				pre_e=node_one[i].end;
			}
		}
	}
	start1.push_back(pre_s);
	end1.push_back(pre_e);

	int len=start1.size();
	int result=0;

	for(i=0;i<len;i++)
	{
		result += end1[i]-start1[i];
	}
	ans = min(result,ans);
}

void solve_2(int duan1,int duan2)
{
	int to[10005];
	memset(to,0,sizeof(to));

	for(i=1;i<=P;i++)
	{
		if(node_one[i].start<=duan1&&node_one[i].end>=duan2)
		{
			to[1]=max(to[1],node_one[i].start);
			to[node_one[i].end] = N+1;
		}
		else
		{
			to[node_one[i].start]=max(node_one[i].end,to[node_one[i].start]);
		}
	}
	
	int result=0,duandian=0;
	for(i=1;i<=N;i++)
	{
		if(to[i]==0) continue;
		if(i>duandian)
		{
			result += to[i]-i;
			duandian=to[i];
		}
		else if(to[i]>duandian)
		{
			result+=to[i]-duandian;
			duandian =to[i];
		}
	}
	ans=min(ans,result);
}

int main()
{
	cin>>N>>P;

	for(i=1;i<=P;i++)
	{
		cin>>Q1>>Q2;
		node_one[i].start = min(Q1,Q2);
		node_one[i].end = max(Q1,Q2);
	}
	sort(node_one+1,node_one+P+1,cmp);

	ans=0x3f3f3f3f;

	//solve();
	for(i=1;i<=N;i++)
	{
		solve_2(i,i+1);
	}
	cout<<ans<<endl;
	
	//system("pause");
	return 0;
}
