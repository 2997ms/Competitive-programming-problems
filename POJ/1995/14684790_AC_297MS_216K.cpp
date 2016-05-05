#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

long long getresult(long long m,long long n,long long k)
{
	long long b = 1;
	while (n > 0)
	{
		if (n & 1)
			b = (b*m) % k;
		n = n >> 1;
		m = (m*m) % k;
	}
	return b;
}
int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	long long Test,i,n,k,temp1,temp2,result;
	cin>>Test;
	
	while(Test--)
	{
		result = 0;
		
		cin >> k >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> temp1 >> temp2;
			result += getresult(temp1, temp2, k);
			result = result%k;
		}
		cout << (result%k) << endl;
	}
	return 0;
}
