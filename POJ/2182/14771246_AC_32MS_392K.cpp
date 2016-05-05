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
	int len;
}tree[32005];

void buildtree(int root,int L,int R)
{
	tree[root].L=L;
	tree[root].R=R;

	tree[root].len = R-L+1;

	if(L!=R)
	{
		int mid = (L+R)>>1;
		buildtree((root<<1)+1,L,mid);
		buildtree((root<<1)+2,mid+1,R);
	}
}

int query(int root,int num)
{
	tree[root].len--;
	if(tree[root].L==tree[root].R)
	{
		return tree[root].L;
	}
	if(tree[(root<<1)+1].len >= num)
	{
		return query((root<<1)+1,num);
	}
	else
	{
		return query((root<<1)+2,num-tree[(root<<1)+1].len);
	}

}

int n;
int val[8005];
int ans[8005];

int main()
{
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		buildtree(0,1,n);
		val[1]=0;

		for(i=2;i<=n;i++)
		{
			scanf("%d",val+i);
		}
		for(i=n;i>=1;i--)
		{
			ans[i]=query(0,val[i]+1);
		}
		for(i=1;i<=n;i++)
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}