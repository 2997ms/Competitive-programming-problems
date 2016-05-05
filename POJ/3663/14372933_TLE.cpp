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

	for(i=1;i<=N;i++)
		cin>>num[i];

	int result=0;
	for(i=1;i<=N;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			if(num[i]+num[j]<=S)
			{
				result++;
			}
		}
	}
	cout<<result<<endl;

	return 0;
}