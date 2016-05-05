#include <iostream>  
#include <string>
#include <cstring>
#include <queue>  
#pragma warning(disable:4996)
using namespace std;  

int head[10005],LOW[10005],DFN[10005],instack[10005],Stack[10005],Belong[10005],out[10005];
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
	init();

	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		addedge(u,v);
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
				out[Belong[i]]++;//计算缩点后每个点的出度
		}
	}
	int out_num=0,import;
	for(i=1;i<=Bcnt;i++)
	{
		if(!out[i])
		{
			out_num++;
			import=i;
		}
	}
	int temp=0;
	if(out_num==1)
	{
		for(i=1;i<=n;i++)
		{
			if(Belong[i]==import)
			{
				temp++;
			}
		}
		cout<<temp<<endl;
	}
	else
	{
		cout<<0<<endl;
	}

}

int main()  
{  
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	solve();  
	return 0;  
}  