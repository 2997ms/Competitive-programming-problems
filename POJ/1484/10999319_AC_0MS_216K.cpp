#include <iostream>
using namespace std;

int main()
{
	int num,oper,resultmax,everyre[100],falg[100],count1,count2,count3=0,count4,max=0,flag=0,result=0;
	while(cin>>num>>oper>>resultmax)
	{
		if(num==0&&oper==0&&resultmax==0)
            break;
	    count3++;
		memset(everyre,0,sizeof(everyre));
		memset(falg,0,sizeof(falg));
		for(count1=1;count1<=num;count1++)
		{
		   cin>>everyre[count1];
		}
		for(count1=1;count1<=oper;count1++)
		{
		   cin>>count4;
		   if(flag) continue;
		   falg[count4]=(falg[count4]+1)%2;
		   for(count2=1;count2<=num;count2++)
		   {
				   result=result+everyre[count2]*falg[count2];
			}
			if(result>=max)
			{
				max=result;
				if(max>resultmax)
					flag=1;
			}
			result=0;
		  }
		if(!flag)
			cout<<"Sequence "<<count3<<endl<<"Fuse was not blown."<<endl<<"Maximal power consumption was "<<max<<" amperes."<<endl<<endl;
		else 
			cout<<"Sequence "<<count3<<endl<<"Fuse was blown."<<endl<<endl;
		result=0;
		flag=0;
		max=0;
	}
	return 0;
}
