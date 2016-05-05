#include <iostream>
using namespace std;

int main()
{
	char a[100],b[100];
	int high[10],low[10],result,count1=1,count2=1,count,flag=0;
	cin>>result;
	for(;result!=0;)
	{
		cin>>a>>b;
		if(b=="high")
		{
			high[count1++]=result;
		}
		else if(b=="low")
		{
			low[count2++]=result;
		}
		else if(a=="right")
		{
			for(count=1;count<count1;count++)
			{
				if(result>high[count])
				{
					cout<<"Stan is dishonest"<<endl;
					flag++;
					count1=1;
		            count2=1;
					break;
				}
			}
			for(count=1;count<count2;count++)
			{
				if(result<low[count])
				{
				    cout<<"Stan is dishonest"<<endl;
					flag++;
					count1=1;
		            count2=1;
					break;
				}
			}
			if(!flag)
			{	
				cout<<"Stan may be honest"<<endl;
			    count1=1;
		        count2=1;
			}
			flag=0;
		}
		cin>>result;
	}
	return 0;
}



