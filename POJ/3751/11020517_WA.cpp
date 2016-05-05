#include <iostream>
using namespace std;

int main()
{
	int count,year,month,day,hour,minute,second;
	cin>>count;
	while(count--)
	{
		scanf("%d/%d/%d-%d:%d:%d",&year,&month,&day,&hour,&minute,&second);
if(hour>=0&&hour<12)
		{if(hour>=0&&hour<1) hour=hour+12;
	
			   printf("%02d/%02d/%d-%02d:%02d:%02dam\n",month,day,year,hour+12,minute,second);
		}
else if(hour>=12)
		{
			if(hour>=13) hour=hour-12;
			   printf("%02d/%02d/%d-%02d:%02d:%02dpm\n",month,day,year,hour,minute,second);
	
		}



	}
	return 0;
}
