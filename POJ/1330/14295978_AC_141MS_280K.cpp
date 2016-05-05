#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int father[10005];

void result(int test1,int test2)
{
	int node1=test1;
	int node2=test2;
	while(father[test1]!=test1)
	{
		node2=test2;
		while(father[node2]!=node2)
		{
			if(test1==node2)
			{
				cout<<test1<<endl;
				return;
			}
			node2=father[node2];
		}
		test1=father[test1];
	}
	cout<<test1<<endl;
	return;
}

int main()
{	
	int count;
	cin>>count;

	while(count--)
	{
		int fa,son,node,i;
		cin>>node;

		for(i=1;i<10005;i++)
		{
			father[i]=i;
		}

		for(i=1;i<=node-1;i++)
		{
			cin>>fa>>son;
			father[son]=fa;
		}
		int test1,test2;
		cin>>test1>>test2;

		result(test1,test2);		
	}
	return 0;
}
