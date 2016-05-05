#include <iostream>
using namespace std;

int main()
{
	int count1,count2,count3,count4,count5;
	cin>>count1;
	for(count2=6;count2<=count1;count2++)
	{
		for(count3=2;count3<=count1;count3++)
		{
			for(count4=count3+1;count4<=count1;count4++)
			{
				for(count5=count4+1;count5<=count1;count5++)
				{
					if(count2*count2*count2==count5*count5*count5+count4*count4*count4+count3*count3*count3)
					{
						cout<<"Cube = "<<count2<<", Triple = ("<<count3<<','<<count4<<','<<count5<<')'<<endl;
					}
				}
			}
		}
	}
	return 0;
}

