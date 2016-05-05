#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
#define MY_MAX 1100

int tree[MY_MAX*3][MY_MAX*3];
int n,t;

int lowbit(int x)
{
	return x&(-x);
}

int get_num(int x,int y)
{
	int sum=0;
	for(;x>0;x=x-lowbit(x))
	{
		for(;y>0;y=y-lowbit(y))
		{
			sum += tree[x][y]; 
		}
	}
	return sum;
}

void cal(int x,int y)
{
	int i,j;
	for(i=x;i<=n;i=i+lowbit(i))
	{
		for(j=y;j<=n;j=j+lowbit(j))
		{
			tree[i][j]++;
		}
	}
}

int main()
{	
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int test,i,x1,y1,x2,y2,x,y;
	char oper[10];
	scanf("%d",&test);

	while(test--)
	{
		scanf("%d%d",&n,&t);
		memset(tree,0,sizeof(tree));
		for(i=1;i<=t;i++)
		{
			scanf("%s",oper);
			if(oper[0]=='C')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				cal(x2+1,y2+1);
				//cal(x2+1,y1);
				//cal(x1,y2+1);
				//cal(x1,y1);
				cal(x1,y1);
				cal(x1,y2+1);
				cal(x2+1,y1);
			}
			else if(oper[0]=='Q')
			{
				scanf("%d%d",&x,&y);
				printf("%d\n",get_num(x,y)%2);
			}
		}
	}
	//system("pause");
	return 0;
}
