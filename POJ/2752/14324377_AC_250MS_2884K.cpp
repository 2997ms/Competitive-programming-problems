#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

char a[400005];
int next1[400005];
int len;
vector<int> result;

void cal()
{
	int i,j=-1;
	next1[0]=-1;
	for(i=0;i<len+1;)
	{
		if(j==-1||a[i]==a[j])
		{
			i++;
			j++;
			next1[i]=j;
		}
		else
		{
			j=next1[j];
		}
	}

}

int main()
{
	while(cin>>a)
	{
		len = strlen(a);
		cal();

		int temp = len;
		while(next1[temp])
		{
			result.push_back(next1[temp]);
			temp=next1[temp];
		}
		sort(result.begin(),result.end());

		int i;
		for(i=0;i<result.size();i++)
		{
			cout<<result[i]<<" ";
		}
		cout<<len<<endl;
		result.clear();
	}
	
	return 0;
}