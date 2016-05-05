#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int reward[400][1005];
int best[400][1005]={0};
int n;

void Dongtai()
{
	int i,j;
	int result=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			best[i][j]=max(best[i-1][j],best[i-1][j-1])+reward[i][j];
		}
	}

	for(i=1;i<=n;i++)
	{
		if(best[n][i]>result)
			result= best[n][i];

	}
	cout<<result<<endl;
}
int main()
{
	int count1,count2;
	
	cin>>n;

	for(count1=1;count1<=n;count1++)
	{
		for(count2=1;count2<=count1;count2++)
		{
			cin>>reward[count1][count2];
		}
	}
	Dongtai();

	return 0;

}