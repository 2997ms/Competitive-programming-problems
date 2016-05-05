#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int Test,x,y;
	cin>>Test;
	
	while(Test--)
	{
		cin>>x>>y;
		if((x==y||x-2==y)&&x>=0&&y>=0)
		{
			if(x==y)
			{
			    if(x%2)
				{
					cout<<x*2-1<<endl;
				}
				else
				{
					cout<<x*2<<endl;
				}
			}
			else
			{
				if(x%2)
				{
					cout<<x*2-3<<endl;
				}
				else
				{
					cout<<x*2-2<<endl;
				}
			}
		}
		else
		{
			cout<<"No Number"<<endl;
		}
	}
	return 0;
}
