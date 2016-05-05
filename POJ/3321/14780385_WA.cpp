#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

#define MY_MAX 220000
int C[MY_MAX];
vector<vector<int>> G(MY_MAX/2);
int HasApple[MY_MAX/2];
int sta[MY_MAX];
int en[MY_MAX];
int ncount=0;
int n,m;

void dfs(int v)
{
	sta[MY_MAX] = ++ncount;
	for(int i=0;i<G[v].size();i++)
	{
		dfs(G[v][i]);
	}
	en[v] = ++ncount;
}

int lowbit(int x)  
{  
    return x&(-x);  
}  
  
void add(int x,int val)  
{  
    while(x<=en[1]+1)  
    {  
        C[x] = C[x] + val;  
        x=x+lowbit(x);  
    }  
}  
  
int sum(int x)  
{  
    int res=0;  
    while(x>0)  
    {  
        res+=C[x];  
        x=x-lowbit(x);
    }  
    return res;  
}  
int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int i,temp1,temp2;
	char oper[5];

	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		G[temp1].push_back(temp2);
		HasApple[i]=1;
	}
	HasApple[n]=1;
	dfs(1);
	scanf("%d",&m);
	memset(C,0,sizeof(C));
	for(i=1;i<=en[1]+1;i++)
	{
		add(i,1);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%s%d",oper,&temp1);
		if(oper[0]=='C')
		{
			if(HasApple[temp1])
			{
				HasApple[temp1]=0;
				add(sta[temp1]+1,-1);
				add(en[temp1]+1,-1);
			}
			else
			{
				HasApple[temp1]=1;
				add(sta[temp1]+1,1);
				add(en[temp1]+1,1);
			}
		}
		else if(oper[0]=='Q')
		{
			printf("%d\n",(sum(en[temp1])-sum(sta[temp1]))/2-1+HasApple[temp1]);
		}
	}

	//system("pause");
	return 0;
}