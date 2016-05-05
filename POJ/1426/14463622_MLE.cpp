#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

queue<long long> q;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	long long test,temp;
	while(1)
	{
		cin>>test;
		
		if(test==0)
			break;
		
		q.push(1);
		while(1)
		{
			temp=q.front();
			q.pop();
			if(temp%test==0)
			{
				cout<<temp<<endl;
				break;
			}
			else
			{
				q.push(temp*10);
				q.push(temp*10+1);
			}
		}
	}

	return 0;
}
