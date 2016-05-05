#include <iostream>
using namespace std;

int main()
{
	int length,count,count1,count2,count3,sum[101],flag[101]={0},max=0,min,k;
	char code[101][51];
	cin>>length>>count;
	for(count1=1;count1<=count;count1++)
	{
		cin>>code[count1];

		sum[count1]=0;

		for(count2=0;count2<length;count2++)
		{
			for(count3=count2+1;count3<length;count3++)
			{
				if(code[count1][count2]>code[count1][count3])
				{
					sum[count1]++;
				}
			}
		}
		if(sum[count1]>max)
			max=sum[count1];
	}
	for(count1=1;count1<=count;count1++)
	{
		min=max+1;

		for(count2=1;count2<=count;count2++)
		{
			if(sum[count2]<min&&flag[count2]==0)
			{
				min=sum[count2];

				k=count2;
			}
		}
		flag[k]++;
		cout<<code[k]<<endl;
	}
	return 0;
}



