#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int island,R,count,island_x[1005],island_y[1005],result,count1,flag=0;
	float left[1005],right[1005],temp,radar;
	cin>>island>>R;
	while(island!=0&&R!=0)
	{
		for(count=1;count<=island;count++)
		{
			cin>>island_x[count]>>island_y[count];
			if(island_y[count]>R)
			{
				result=-1;
				cout<<"Case "<<++flag<<':'<<result<<endl;
				break;
			}
			else
			{
				left[count]=island_x[count]-sqrt(R*R-island_y[count]*island_y[count]);
				right[count]=island_x[count]+sqrt(R*R-island_y[count]*island_y[count]);
			}				
		}
		if(result!=-1)
		{
			for(count=1;count<=island;count++)
			{
				for(count1=count;count1<=island;count1++)
				{
					if(left[count1]>left[count1+1])
					{
						temp=left[count1];
						left[count1]=left[count1+1];
						left[count1+1]=temp;
						temp=right[count1];
						right[count1]=right[count1+1];
						right[count1+1]=temp;
					}
				}
			}
			radar=right[1];result=1;
			for(count=2;count<=island;count++)
			{
				if(left[count]>radar)
				{
					result++;
				}
				else if(right[count]<radar)
				{
					radar=right[count];
				}
			}
			cout<<"Case "<<++flag<<':'<<result<<endl;
		}
		cin>>island>>R;
	}
	return 0;
}

