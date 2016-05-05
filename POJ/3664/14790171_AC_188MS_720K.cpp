#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#pragma warning(disable:4996)  
using namespace std;

int n,k;
struct no
{
	int a,b;
	int pos;
}node[50005];

bool cmp1(no n1,no n2)
{
	return n1.a>n2.a;
}

bool cmp2(no n1,no n2)
{
	return n1.b>n2.b;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	
	int i;
	scanf("%d%d",&n,&k);

	for(i=0;i<n;i++)
	{
		scanf("%d%d",&node[i].a,&node[i].b);
		node[i].pos=i+1;
	}
	sort(node,node+n,cmp1);
	sort(node,node+k,cmp2);

	printf("%d\n",node[0].pos);
	return 0;
}