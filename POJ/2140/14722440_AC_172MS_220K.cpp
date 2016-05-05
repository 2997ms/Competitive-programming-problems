#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int count1;
int n;

void find()
{
    count1=0;
	int i,j,k;

	for(j=1;j<=n;j++)
	{
		int temp=j;
		for(k=j;temp<=n;k++)
		{
			if(temp==n)count1++;
			temp += k+1;
		}
	}

}
int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	cin>>n;
	find();
	cout<<count1<<endl;
	return 0;
}
