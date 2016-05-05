#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int number[10000004];
int n;

void find()
{
	memset(number,0,sizeof(number));
	int i,j,k;

	for(j=0;j<=n/2;j++)
	{
		int temp=j+1;
		for(k=j+1;j+temp<=n;k++)
		{
			number[j+temp]++;
			temp += k+1;
		}
	}

}
int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	cin>>n;
	
		memset(number,0,sizeof(number));
		find();
		cout<<number[n]<<endl;
	
	return 0;
}
