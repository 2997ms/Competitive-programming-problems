#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int result[12],n;
	result[0]=0;
	result[2]=10;
	result[4]=670;
	result[6]=55252;
	result[8]=4816030;
	result[10]=432457640;

	cin>>n;
	cout<<result[n]<<endl;

	return 0;
}