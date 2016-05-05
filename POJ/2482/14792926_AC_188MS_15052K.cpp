#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define maxn 100005

struct no
{
	int le,re,value,c;
	no *pleft,*pright;
}tree[maxn*6];

struct li
{
	double le,re,x;
	int value;
	bool end;
}line[maxn*2];

int n,ax,ay;
double dy[maxn*2];
int lcount,ncount,tot;

bool operator <(const li&a,const li&b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.end;
}

void input()
{
	lcount=0;
	tot=0;
	for(int i=0;i<n;i++)
	{
		int x,y,c;
		double xx=ax/2.0-0.1;
		double yy=ay/2.0-0.1;
		scanf("%d%d%d",&x,&y,&c);

		line[lcount].le=y-yy;
		line[lcount].re=y+yy;
		line[lcount].x=x-xx;
		line[lcount].value=c;
		line[lcount].end=false;

		dy[tot++]=line[lcount].le;
		dy[tot++]=line[lcount].re;
		lcount++;

		line[lcount].le=y-yy;
		line[lcount].re=y+yy;
		line[lcount].x=x+xx;
		line[lcount].value=c;
		line[lcount].end=true;
		lcount++;
	}
}

void buildtree(no *proot,int le,int re)
{
	proot->le=le;
	proot->re=re;
	proot->value=0;
	proot->c=0;

	if(le!=re)
	{
		int mid = (le+re)/2;
		ncount++;
		proot->pleft = tree + ncount;

		ncount++;
		proot->pright = tree + ncount;

		buildtree(proot->pleft,le,mid);
		buildtree(proot->pright,mid+1,re);
	}
}

int binarysearch(double a)
{
	int le=0;
	int re=tot-1;

	while(le<re)
	{
		int mid = (le+re)/2;
		if(dy[mid]<a)
		{
			le = mid+1;
		}
		else
		{
			re = mid;
		}
	}
	return le;
}

void add(no *proot,int le,int re,int c)
{
	if(le > proot->re || re < proot->le)
		return;
	if(le <= proot->le && re >= proot->re)
	{
		proot->c += c;
		proot->value +=c;
		return;
	}
	add(proot->pleft,le,re,c);
	add(proot->pright,le,re,c);
	proot->value = max(proot->pleft->value,proot->pright->value) +proot->c;
}

void work()
{
	ncount=0;
	buildtree(tree,0,tot-1);
	
	int ans=0;
	for(int i=0;i<lcount;i++)
	{
		int le=binarysearch(line[i].le);
		int re=binarysearch(line[i].re);

		if(!line[i].end)
		{
			add(tree,le,re,line[i].value);
			ans=max(ans,tree[0].value);
		}
		else
		{
			add(tree,le,re,-line[i].value);
		}
	}
	printf("%d\n",ans);
}


int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	while(scanf("%d%d%d",&n,&ax,&ay)!=EOF)
	{
		memset(tree,0,sizeof(tree));
		input();
		sort(line,line+lcount);
		sort(dy,dy+tot);
		tot=unique(dy,dy+tot)-dy;

		work();
	}

	//system("pause");
	return 0;
}
