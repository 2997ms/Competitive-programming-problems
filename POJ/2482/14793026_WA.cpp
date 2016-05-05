#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

#define maxn 50002

struct no
{
	int le,re;
	long long max_value,sing_value;
}tree[maxn*5];

struct li
{
	double x,y1,y2;
	int value;
	bool end;
}line[maxn*2];

struct sta
{
	int x,y,value;
}star[maxn];

int lcount,dycount;
double dy[maxn*2];
map<double,int>map_m;
long long n,w,h;

bool cmp_double(double a,double b)
{
	return a<b;
}

bool cmp_x(const li a,const li b)
{
	if(a.x==b.x)
		return a.end;
	else
		return a.x<b.x;
}

void buildtree(int root,int L,int R)
{
	tree[root].le=L;
	tree[root].re=R;
	tree[root].max_value=0;
	tree[root].sing_value=0;

	if(L!=R)
	{
		int mid = (L+R)/2;
		buildtree(root*2+1,L,mid);
		buildtree(root*2+2,mid+1,R);
	}
}

void add_tree(int root,int L,int R,int c)
{
	if(tree[root].le==L&&tree[root].re==R)
	{
		tree[root].sing_value+=c;
		tree[root].max_value+=c;
		return;
	}

	int mid = (tree[root].le+tree[root].re)/2;
	if(R<=mid)
	{
		add_tree(root*2+1,L,R,c);
	}
	else if(L>=mid+1)
	{
		add_tree(root*2+2,L,R,c);
	}
	else 
	{
		add_tree(root*2+1,L,mid,c);
		add_tree(root*2+2,mid+1,R,c);
	}
	tree[root].max_value = max(tree[2*root+1].max_value,tree[2*root+2].max_value)+tree[root].sing_value;
}

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int i,L1,R1;
	long long ans;
	double xx,yy;
	scanf("%lld%lld%lld",&n,&w,&h);
	xx=w/2.0;
	yy=h/2.0;

	lcount=0;
	dycount=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&star[i].x,&star[i].y,&star[i].value);
		
		line[lcount].x= star[i].x-xx;
		line[lcount].y1=star[i].y-yy;
		line[lcount].y2=star[i].y+yy;
		line[lcount].value=star[i].value;
		line[lcount].end=false;
		lcount++;

		line[lcount].x=star[i].x+xx;
		line[lcount].y1=star[i].y-yy;
		line[lcount].y2=star[i].y+yy;
		line[lcount].value=star[i].value;
		line[lcount].end=true;
		lcount++;

		dy[dycount++]=star[i].y-yy;
		dy[dycount++]=star[i].y+yy;
	}
	sort(line,line+lcount,cmp_x);
	sort(dy,dy+dycount,cmp_double);
	dycount=unique(dy,dy+dycount)-dy;

	buildtree(0,0,dycount-1);

	for(i=0;i<dycount;i++)
	{
		map_m[dy[i]]=i;
	}

	ans=0;
	for(i=0;i<lcount;i++)
	{
		L1=map_m[line[i].y1];
		R1=map_m[line[i].y2];

		if(!line[i].end)
		{
			add_tree(0,L1,R1,line[i].value);
			ans=max(tree[0].max_value,ans);
		}
		else
		{
			add_tree(0,L1,R1,-1*line[i].value);
		}
	}
	cout<<ans<<endl;
	//system("pause");
	return 0;
}
