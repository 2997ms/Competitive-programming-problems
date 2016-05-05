#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct no
{
	int L,R;
	int col;
	bool inc;
}tree1[1000000];

int L1,T,O;

void buildtree(int root,int L,int R)
{
	tree1[root].L=L;
	tree1[root].R=R;

	tree1[root].col=1;
	tree1[root].inc=false;

	if(L!=R)
	{
		buildtree((root<<1)+1,L,(L+R)/2);
		buildtree((root<<1)+2,(L+R)/2+1,R);
	}
}

void insert(int root,int L,int R,int color)
{
	if(tree1[root].L==L&&tree1[root].R==R)
	{
		tree1[root].inc=true;
		tree1[root].col= (1<<(color-1));
		return ;
	}
	if(tree1[root].inc)
	{
		tree1[root].inc=false;

		tree1[(root<<1)+1].col = tree1[root].col;
		tree1[(root<<1)+2].col = tree1[root].col;

		tree1[(root<<1)+1].inc = true;
		tree1[(root<<1)+2].inc = true;
	}
	int mid = (tree1[root].L + tree1[root].R)/2;
	if(R<=mid)
	{
		insert((root<<1)+1,L,R,color);
	}
	else if(L>=mid+1)
	{
		insert((root<<1)+2,L,R,color);
	}
	else
	{
		insert((root<<1)+1,L,(L+R)/2,color);
		insert((root<<1)+2,(L+R)/2+1,R,color);
	}
	tree1[root].col = tree1[(root<<1)+1].col | tree1[(root<<1)+2].col;
}

int query(int root,int L,int R)
{
	if(tree1[root].inc==true ||tree1[root].L==L && tree1[root].R==R)
	{
		return tree1[root].col;
	}
	int mid = (tree1[root].L + tree1[root].R)/2;
	if(R<=mid)
	{
		return query((root<<1)+1,L,R);
	}
	else if(L>=mid+1)
	{
		return query((root<<1)+2,L,R);
	}
	else
	{
		return query((root<<1)+1,L,mid)|query((root<<1)+1,mid+1,R);
	}
}

void out(int x)
{
	int cnt=0;
	while(x!=0)
	{
		cnt += (x&1);
		x=x>>1;
	}
	printf("%d\n",cnt);
}

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,s,e,color_s;
	string op;
	scanf("%d%d%d",&L1,&T,&O);

	buildtree(0,1,L1);
	for(i=1;i<=O;i++)
	{
		cin>>op;
		if(op=="C")
		{
			scanf("%d%d%d",&s,&e,&color_s);
			insert(0,s,e,color_s);
		}
		else
		{
			scanf("%d%d",&s,&e);
			int res=query(0,s,e);
			out(res);
		}
	}

	//system("pause");
	return 0;
}
