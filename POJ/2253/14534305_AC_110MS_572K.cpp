#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int num;
double stone[205][3];
double dis[205][205];

int main()
{
	int i,j,k,ist=1;
	while(cin>>num)
	{
		if(num==0)
			break;
		cout<<"Scenario #"<<ist<<endl;
		ist++;
		cout<<"Frog Distance = ";

		for(i=1;i<=num;i++)
		{
			cin>>stone[i][1]>>stone[i][2];
		}
		
		for(i=1;i<=num;i++)
		{
			for(j=i+1;j<=num;j++)
			{
				dis[j][i]=dis[i][j]=(double)sqrt((stone[i][1]-stone[j][1])*(stone[i][1]-stone[j][1])+(stone[i][2]-stone[j][2])*(stone[i][2]-stone[j][2]));
			}
		}

		for(k=1;k<=num;k++)
		{
			for(i=1;i<=num;i++)
			{
				for(j=1;j<=num;j++)
				{	
					dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
				}
			}
		}

		printf("%.3f",dis[1][2]);
		cout<<endl;
		cout<<endl;
	}
	return 0;
}
