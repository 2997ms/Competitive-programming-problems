#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int count1,count2,count3,h[3005];
	cin>>count1;
	for(count2=1;count2<=count1;count2++)
	{
		memset(h,0,sizeof(h));
		int pre,cur;
		cin>>pre;
		for(count3=1;count3<count1;count3++)
		{
			cin>>cur;
			h[abs(cur-pre)]++;
			pre=cur;
		}
		for(count3=1;count3<count1;count3++)
		{
			if(!h[count3])
				break;
		}
		if(count3==count1)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;
	}
	return 0;
}




