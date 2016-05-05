#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int test;
	cin>>test;

	while(test--)
	{
		int length,ant,ant_temp;
		int min_val=-1,max_val=-1;
		cin>>length>>ant;

		ant_temp=ant;
		while(ant_temp--)
		{
			int dis;
			cin>>dis;
			min_val=max(min_val,min(dis,length-dis));
			max_val=max(max_val,max(dis,length-dis));
		}
		cout<<min_val<<" "<<max_val<<endl;
	}
	return 0;
}