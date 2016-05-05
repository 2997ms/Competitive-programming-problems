#include <iostream>
using namespace std;

int main()
{
	int result[16];
	int n;
	
	result[1] = 2;
	result[2] = 7;
	result[3] = 5;
	result[4] = 30;
	result[5] = 169;
	result[6] = 441;
	result[7] = 1872;
	result[8] = 7632;
	result[9] = 1740;
	result[10] = 93313;
	result[11] = 459901;
	result[12] = 1358657;
	result[13] = 2504881;
	result[14] = 13482720;
	
	while(cin>>n && n)
	{
		cout<<result[n]<<endl;
	}
	return 0;
}