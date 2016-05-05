#include <iostream>
using namespace std;

int main()
{
	int people,party,count1,temp,count2,h[105],flag;
	while(cin>>people>>party&&(people||party))
	{
		flag=0;
		memset(h,0,sizeof(h));
      for(count1=1;count1<=party;count1++)
	  {

		for(count2=1;count2<=people;count2++)
		{
			cin>>temp;
			if(temp)
				h[count2]++;
		}
	  }
	  for(count2=1;count2<=people;count2++)
	  {
		if(h[count2]==people)
		{
			cout<<"yes"<<endl;
			flag=1;
			break;
		}
	  }
	  if(!flag)
		  cout<<"no"<<endl;
	}
	return 0;
}

