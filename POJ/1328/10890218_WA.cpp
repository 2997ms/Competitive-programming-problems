#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int island,count,result=0,count1,flag=0,R,island_x[1005],island_y[1005];
	double left[1005],right[1005],temp,radar;
	cin>>island>>R;
	while(island!=0||R!=0)
	{
		for(count=1;count<=island;count++)
		{
			cin>>island_x[count]>>island_y[count];
			if(island_y[count]>R||island_y[count]<0||R<=0)
			{
				result=-1;
			}
			else
			{
				left[count]=island_x[count]-sqrt(1.0*(R*R-island_y[count]*island_y[count]));
				right[count]=island_x[count]+sqrt(1.0*(R*R-island_y[count]*island_y[count]));
			}				
		}
		if(result!=-1)
		{
			for(count=1;count<=island;count++)
			{
				for(count1=count;count1<island;count1++)
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
					radar=right[count];
				}			
				if(right[count]<radar)
				{
					radar=right[count];
				}
			}
			cout<<"Case "<<++flag<<':'<<result<<endl;
			result=0;
		}
		else
		{
			cout<<"Case "<<++flag<<':'<<result<<endl;
			result=0;
		}
		cin>>island>>R;
	}
	return 0;
}


