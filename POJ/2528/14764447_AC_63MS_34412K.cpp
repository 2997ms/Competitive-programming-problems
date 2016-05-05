#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n;
struct CPost
{
	int L,R;
};
CPost posters[10100];
int x[20200];
int hash_m[10000010];

struct Cnode
{
	int L,R;
	bool bCovered;
	Cnode *pleft,*pright;
};
Cnode Tree[1000000];
int nNodeCount;

void buildtree(Cnode *tree,int L,int R)
{
	tree->L=L;
	tree->R=R;

	tree->bCovered=false;

	if(L!=R)
	{
		nNodeCount++;
		tree->pleft = Tree + nNodeCount;

		nNodeCount++;
		tree->pright = Tree + nNodeCount;

		buildtree(tree->pleft,L,(L+R)/2);
		buildtree(tree->pright,(L+R)/2+1,R);
	}
}

bool Post(Cnode *proot,int L,int R)
{
	if(proot->bCovered) return false;
	if(proot->L==L && proot->R==R)
	{
		proot->bCovered = true;
		return true;
	}
	bool bresult;
	if(R <= (proot->L+proot->R)/2)
	{
		bresult = Post(proot->pleft,L,R);
	}
	else if(L >= (proot->L+proot->R)/2+1)
	{
		bresult = Post(proot->pright,L,R);
	}
	else
	{
		bool b1 = Post(proot->pleft,L,(proot->L+proot->R)/2);
		bool b2 = Post(proot->pright,(proot->L+proot->R)/2+1,R);

		bresult = b1||b2;
	}
	if(proot->pleft->bCovered && proot->pright->bCovered)
		proot->bCovered = true;
	return bresult;
}

int main()
{	

	int test;
	int i,j,k,nCaseNo=0;

	scanf("%d",&test);
	while(test--)
	{
		nNodeCount=0;
		nCaseNo++;

		scanf("%d",&n);
		int ncount=0;
		
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&posters[i].L,&posters[i].R);

			x[ncount++] = posters[i].L;
			x[ncount++] = posters[i].R;
		}

		sort(x,x+ncount);
		ncount = unique(x,x+ncount) - x;

		int nintervalno = 0;

		for(i=0;i<ncount;i++)
		{
			hash_m[x[i]]= nintervalno;
			if(i<ncount-1)
			{
				if(x[i+1]-x[i]==1)
				{
					nintervalno++;
				}
				else
				{
					nintervalno += 2;
				}
			}
		}
		buildtree(Tree,0,nintervalno);
		int nsum=0;

		for(i=n-1;i>=0;i--)
		{
			if(Post(Tree,hash_m[posters[i].L],hash_m[posters[i].R]))
			{
				nsum++;
			}
		}
		printf("%d\n",nsum);
	}
	return 0;
}
