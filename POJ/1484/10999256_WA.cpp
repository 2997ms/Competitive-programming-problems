#include <iostream>
using namespace std;

int main()
{
	int num,oper,resultmax,everyre[100],falg[100],count1,count2,count3=0,count4,max=-1,flag=0,result=0;
	while(cin>>num>>oper>>resultmax&&num&&oper&&resultmax)
	{
			count3++;
			memset(everyre,0,sizeof(everyre));
		   for(count1=1;count1<=num;count1++)
		   {
			cin>>everyre[count1];
		   }
		   memset(falg,0,sizeof(falg));
		   for(count1=1;count1<=oper;count1++)
		   {
			cin>>count4;
			falg[count4]++;
			for(count2=1;count2<=num;count2++)
			{
				if(falg[count2]==1)
				{
					result=result+everyre[count2];
				}
			}
			if(result>resultmax)
			{
				flag=1;
			}
			else if(result>max)
			{
				max=result;
			}
			result=0;
		   }
		if(!flag)
			cout<<"Sequence "<<count3<<endl<<"Fuse was not blown."<<endl<<"Maximal power consumption was "<<max<<" amperes."<<endl<<endl;
		if(flag==1)
			cout<<"Sequence "<<count3<<endl<<"Fuse was blown."<<endl<<endl;
		result=0;
		flag=0;
		max=-1;
	}
	return 0;
}
