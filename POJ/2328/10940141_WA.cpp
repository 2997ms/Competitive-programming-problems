#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a,b;
	int result,max=100,min=-100;
	cin>>result;
	for(;result!=0;)
	{
		cin>>a>>b;
		if(b=="high")
		{
			max=result>max?result:max;
		}
	 if(b=="low")
		{
			min=result<min?result:min;
		}
		 if(b=="on")
		{
				if(result>=max||result<=min)
				{
					cout<<"Stan is dishonest "<<endl;
				}
			else
				cout<<"Stan may be honest "<<endl;	
			max=100;min=-100;
		}
		cin>>result;
	}
	return 0;
}



