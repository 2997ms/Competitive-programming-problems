#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int num[20005];

int main()
{	
	int N,S,i,j;
	cin>>N>>S;
	int result=0;
	for(i=1;i<=N;i++)
	{
		cin>>num[i];
		if(num[i]<S)
		{
			for(j=1;j<i;j++)
			{
				if(num[i]+num[j]<=S)
				{
					result++;
				}
			}
		}
	}

	cout<<result<<endl;

	return 0;
}