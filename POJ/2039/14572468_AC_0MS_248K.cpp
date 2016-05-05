#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int column;
char value[201][201];
string test;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,j,num;
	int len,row;
	while(cin>>column)
	{
		if(column==0)
			break;
		cin>>test;

		len=test.length();
		row=len/column;
		num=0;

		for(i=1;i<=row;i++)
		{
			if(i%2)
			{
				for(j=1;j<=column;j++)
				{
					value[i][j]=test[num];
					num++;
				}
			}
			else
			{
				for(j=column;j>=1;j--)
				{
					value[i][j]=test[num];
					num++;
				}
			}
		}
		for(j=1;j<=column;j++)
		{
			for(i=1;i<=row;i++)
			{
				cout<<value[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}
