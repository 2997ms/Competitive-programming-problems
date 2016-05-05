#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int n,s;
int val[25][25];

int main()
{
	int i,j,cnt;
	while(cin>>n>>s)
	{
		memset(val,0,sizeof(val));
		cnt=s;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i<j)continue;
				if(cnt%10==0)
				{
					val[j][i]=1;
					cnt=2;
				}
				else
				{
					val[j][i]=cnt%10;
					cnt++;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(j==1)
				{
					if(val[i][j]==0)
						cout<<" ";
					else
						cout<<val[i][j];
				}
				else
				{
					if(val[i][j]==0)
						cout<<"  ";
					else
						cout<<" "<<val[i][j];
				}
			}
			cout<<endl;
		}

	}

	return 0;
}
