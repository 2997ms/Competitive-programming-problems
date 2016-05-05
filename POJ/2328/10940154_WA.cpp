#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a,b;
	int result,max=-100,min=100;
	cin>>result;
	for(;result!=0;)
	{
		cin>>a>>b;
		if(b=="high")
		{
			max=result<min?result:min;
		}
	    if(b=="low")
		{
			min=result>max?result:max;
		}
		 if(b=="on")
		{
				if(result>max&&result<min)
				{
					cout<<"Stan may be honest "<<endl;	
				}
			else
					cout<<"Stan is dishonest "<<endl;
			max=-100;min=100;
		}
		cin>>result;
	}
	return 0;
}



