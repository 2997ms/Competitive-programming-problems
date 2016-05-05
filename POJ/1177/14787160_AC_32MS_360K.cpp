#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct li
{
	int x,y1,y2;
	int bLeft;
}line[200005];

int y[200005];
int n;

struct no
{
	int L;
	int R;
	int cover;
	int Lcover;
	int Rcover;
	int interval;
	int m;
}tree[200005];

void buildtree(int root,int L,int R)
{
	tree[root].L=L;
	tree[root].R=R;
	tree[root].cover=0;
	tree[root].Lcover=0;
	tree[root].Rcover=0;
	tree[root].interval=0;
	tree[root].m=0;

	if(L!=R)
	{
		int mid = (L+R)/2;
		buildtree(root*2+1,L,mid);
		buildtree(root*2+2,mid+1,R);
	}
}

void insert(int root,int L,int R)
{
	if(tree[root].L==L&&tree[root].R==R)
	{
		tree[root].cover++;
		tree[root].m = y[R+1]-y[L];
		tree[root].Lcover=1;
		tree[root].Rcover=1;
		tree[root].interval=1;
		return;
	}
	else
	{
		int mid = (tree[root].L + tree[root].R)/2;
		if(R<=mid)
		{
			insert(root*2+1,L,R);
		}
		else if(L>=mid+1)
		{
			insert(root*2+2,L,R);
		}
		else
		{
			insert(root*2+1,L,mid);
			insert(root*2+2,mid+1,R);
		}
	}
	if(tree[root].cover==0)
	{
		tree[root].m = tree[root*2+1].m +tree[root*2+2].m;
		tree[root].Lcover=tree[root*2+1].Lcover;
		tree[root].Rcover=tree[root*2+2].Rcover;
		tree[root].interval=tree[root*2+1].interval+tree[root*2+2].interval-tree[root*2+1].Rcover*tree[root*2+2].Lcover;
	}
}

void dele(int root,int L,int R)
{
	if(tree[root].L==L&&tree[root].R==R)
	{
		tree[root].cover--;
	}
	else
	{
		int mid = (tree[root].L + tree[root].R)/2;
		if(R<=mid)
		{
			dele(root*2+1,L,R);
		}
		else if(L>=mid+1)
		{
			dele(root*2+2,L,R);
		}
		else
		{
			dele(root*2+1,L,mid);
			dele(root*2+2,mid+1,R);
		}
	}
	if(tree[root].cover<=0&&tree[root].L==tree[root].R)
	{
		tree[root].m=0;
		tree[root].Lcover=0;
		tree[root].Rcover=0;
		tree[root].interval=0;
	}
	else if(tree[root].cover<=0)
	{
		tree[root].m = tree[root*2+1].m +tree[root*2+2].m;
		tree[root].Lcover=tree[root*2+1].Lcover;
		tree[root].Rcover=tree[root*2+2].Rcover;
		tree[root].interval=tree[root*2+1].interval+tree[root*2+2].interval-tree[root*2+1].Rcover*tree[root*2+2].Lcover;
	}
}

bool cmp(struct li line1, struct li line2)
{
	if (line1.x == line2.x)
		return line1.bLeft > line2.bLeft;
	return (line1.x < line2.x);
}

template <class F,class T>  
F bin_search(F s,F e,T val)  
{  
	F L = s;  
	F R = e-1;  

	while(L<=R)  
	{  
		F mid = L + (R-L)/2;  
		if(!(*mid<val || val < *mid))  
		{  
			return mid;  
		}  
		else if(val < *mid)  
		{  
			R = mid -1;  
		}  
		else  
		{  
			L= mid + 1;  
		}  
	}  
}  

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,x1,x2,y1,y2,yc,lc;
	scanf("%d",&n);

	yc=0;
	lc=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		y[yc++]=y1;
		y[yc++]=y2;

		line[lc].x=x1;
		line[lc].y1=y1;
		line[lc].y2=y2;
		line[lc].bLeft = 1;
		lc++;

		line[lc].x=x2;
		line[lc].y1=y1;
		line[lc].y2=y2;
		line[lc].bLeft = 0;
		lc++;
	}
	sort(line,line+lc,cmp);
	sort(y,y+yc);
	yc=unique(y,y+yc)-y;

	buildtree(0,0,yc-1-1);
	int preme=0;
	int now_m=0;
	int now_line=0;
	for(i=0;i<=lc-1;i++)
	{
		int L=bin_search(y,y+yc,line[i].y1)-y;  
		int R=bin_search(y,y+yc,line[i].y2)-y;  

		if(line[i].bLeft)  
		{  
			insert(0,L,R-1);  
		}  
		else  
		{  
			dele(0,L,R-1);  
		}
		if(i>=1)
			preme += 2*now_line*(line[i].x-line[i-1].x);
		preme += abs(tree[0].m-now_m);
		now_m=tree[0].m;
		now_line=tree[0].interval;
	}
	printf("%d\n",preme);
	//system("pause");
	return 0;
}
