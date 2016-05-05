#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
using namespace std;

double y[210];

struct li
{
	double x,y1,y2;
	bool bleft;
}lines[210];

struct no
{
	int L,R;
	double len;
	int cover;

}tree[500];

bool operator < (const li &n1,const li &n2)
{
	return n1.x<n2.x;
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

void buildtree(int root,int L,int R)
{
	tree[root].L=L;
	tree[root].R=R;

	tree[root].len=0;
	tree[root].cover=0;

	if(L!=R)
	{
		int mid = (L+R)/2;
		buildtree(root*2+1,L,mid);
		buildtree(root*2+2,mid+1,R);
	}
}

void inse(int root,int L,int R)
{
	if(tree[root].L==L&&tree[root].R==R)
	{
		tree[root].cover++;
		tree[root].len= y[R+1] - y[L];
		return;
	}
	int mid = (tree[root].L + tree[root].R)/2;
	
	if(R<=mid)
	{
		inse(root*2+1,L,R);
	}
	else if(L>=mid+1)
	{
		inse(root*2+2,L,R);
	}
	else
	{
		inse(root*2+1,L,mid);
		inse(root*2+2,mid+1,R);
	}
	if(tree[root].cover==0)
	{
		tree[root].len = tree[root*2+1].len + tree[root*2+2].len;
	}
}

void dele(int root,int L,int R)
{
	if(tree[root].L == L && tree[root].R == R)
	{
		tree[root].cover--;
		if(tree[root].cover==0)
		{
			if(tree[root].L == tree[root].R)
			{
				tree[root].len=0;
			}
			else
			{
				tree[root].len = tree[root*2+1].len + tree[root*2+2].len; 
			}
		}
		return;
	}

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

	if(tree[root].cover==0)
	{
		tree[root].len = tree[root*2+1].len + tree[root*2+2].len; 
	}
}
int n;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int i,yc,lc,t;
	double x1,x2,y1,y2;
	t=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		t++;
		yc=0;
		lc=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			y[yc++]=y1;
			y[yc++]=y2;

			lines[lc].x=x1;
			lines[lc].y1=y1;
			lines[lc].y2=y2;
			lines[lc].bleft=true;
			lc++;

			lines[lc].x=x2;
			lines[lc].y1=y1;
			lines[lc].y2=y2;
			lines[lc].bleft=false;
			lc++;
		}
		sort(lines,lines+lc);
		sort(y,y+yc);
		yc=unique(y,y+yc)-y;

		buildtree(0,0,yc-1-1);
		double Area=0;

		for(i=0;i<lc-1;i++)
		{
			int L=bin_search(y,y+yc,lines[i].y1)-y;
			int R=bin_search(y,y+yc,lines[i].y2)-y;

			if(lines[i].bleft)
			{
				inse(0,L,R-1);
			}
			else
			{
				dele(0,L,R-1);
			}
			Area += tree[0].len*(lines[i+1].x-lines[i].x);
		}
		printf("Test case #%d\n",t);
		printf("Total explored area: %.2lf\n",Area);
		printf("\n");
	}

	//system("pause");
	return 0;
}