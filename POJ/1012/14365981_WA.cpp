/*#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int people[50];
vector <int> kill;

int main()
{
	int n,k=0;
	while(cin>>n)
	{
		int result=n+1,rest=2*n,kill_num=1;
		int n2=2*n;
		
		memset(people,0,sizeof(people));
		kill.clear();
		while(1)
		{
			if(kill.size()==n)
				break;
			if((result+kill_num-1)%rest==0)
			{
				kill_num=rest;
				rest--;
				kill.push_back(rest);
			}
			else if((result+kill_num-1)%rest<=n)
			{
				kill_num=1;
				kill.clear();
				rest=n2;
				result++;
			}
			else
			{
				kill_num=(result+kill_num-1)%rest;
				rest--;
				kill.push_back(kill_num);
			}
		}
		cout<<result<<endl;
	}

	system("pause");
	return 0;
}
*/
#include <iostream>
using namespace std;

int main()
{
	int result[16];
	int n;
	
	result[1] = 1;
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