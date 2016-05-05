#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
using namespace std;

int y[20010];

struct li
{
	int x,y1,y2;
	bool bleft;
}lines[20010];

struct no
{
	int L,R;
	int len;
	int cover;

}tree[20010];

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

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int i,yc,lc;
	int x1,x2,y1,y2;
	while(true)
	{
		yc=0;
		lc=0;
		for(i=1;;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(i==1&&x1==-1&&y1==-1&&x2==-1&&y2==-1)
			{
				return 0;
			}
			else if(x1==-1&&y1==-1&&x2==-1&&y2==-1)
			{
				break;
			}
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
		int Area=0;

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
		printf("%d\n",Area);
	}

	//system("pause");
	return 0;
}