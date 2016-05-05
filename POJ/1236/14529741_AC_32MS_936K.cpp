#include <iostream>  
#include <string>
#include <cstring>
#include <queue>  
#pragma warning(disable:4996)
using namespace std;  

int head[10005],LOW[10005],DFN[10005],instack[10005],Stack[10005],Belong[10005],out[10005],in[10005];
int n,m,edge_num,Dindex,Stop,Bcnt;

struct edge{
	int to;
	int next;
}Edge[50005];

void init()
{
	edge_num=0;
	Stop=Bcnt=Dindex=0;

	memset(Edge,-1,sizeof(Edge));
	memset(head,-1,sizeof(head));
	memset(LOW,0,sizeof(LOW));
	memset(DFN,0,sizeof(DFN));
	memset(instack,0,sizeof(instack));
	memset(Stack,0,sizeof(Stack));
	memset(Belong,0,sizeof(Belong));
	memset(out,0,sizeof(out));
	memset(in,0,sizeof(in));
}

void addedge(int u,int v)
{
	Edge[edge_num].to=v;
	Edge[edge_num].next=head[u];
	head[u]=edge_num;
	edge_num++;
}

void tarjan(int i)
{
	int j;
	DFN[i]=LOW[i]=++Dindex;
	instack[i]=true;
	Stack[++Stop]=i;

	for(j=head[i];j!=-1;j=Edge[j].next)
	{
		int v=Edge[j].to;
		if(DFN[v]==0)
		{
			tarjan(v);
			LOW[i]=min(LOW[i],LOW[v]);
		}
		else if(instack[v]==1)
		{
			LOW[i]=min(LOW[i],DFN[v]);
		}
	}

	if(DFN[i]==LOW[i])
	{
		Bcnt++;
		do
		{
			j=Stack[Stop--];
			instack[j]=false;
			Belong[j]=Bcnt;
		}
		while(j!=i);
	}
}

void solve()
{
	int i,j,u,v;

	cin>>n;
	init();
	m=0;

	for(i=1;i<=n;i++)
	{
		while(1)
		{
			cin>>v;

			if(v==0)
				break;

			addedge(i,v);
			m++;
		}
	}

	for(i=1;i<=n;i++)
	{
		if(!DFN[i])
			tarjan(i);
	}

	for(i=1;i<=n;i++)
	{
		for(j=head[i];j!=-1;j=Edge[j].next)
		{
			if(Belong[i]!=Belong[Edge[j].to])
				in[Belong[Edge[j].to]]++;//计算缩点后每个点的入度
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=head[i];j!=-1;j=Edge[j].next)
		{
			if(Belong[i]!=Belong[Edge[j].to])
				out[Belong[i]]++;//计算缩点后每个点的出度
		}
	}
	int result1=0,result2=0;
	for(i=1;i<=Bcnt;i++)
	{
		if(out[i]==0)
		{
			result1++;
		}
	}
	for(i=1;i<=Bcnt;i++)
	{
		if(in[i]==0)
		{
			result2++;
		}
	}
	if(Bcnt==1)
	{
		cout<<1<<endl;
		cout<<0<<endl;
	}
	else
	{
		cout<<result2<<endl;
		cout<<max(result1,result2)<<endl;
	}
}

int main()  
{  
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	solve();
	return 0;  
}  