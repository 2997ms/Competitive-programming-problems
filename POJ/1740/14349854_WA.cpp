#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n[105];

int main()
{
	int num;
	while(cin>>num)
	{
		if(!num)
			break;
		memset(n,0,sizeof(n));

		int i,temp;

		if(num%2)
		{
			for(i=1;i<=num;i++)
				cin>>temp;
			cout<<1<<endl;
		}
		else
		{
			for(i=1;i<=num;i++)
			{
				cin>>temp;
				n[temp]++;
			}
			int flag=0;
			for(i=0;i<=104;i++)
			{
				if(n[num]%2)
					flag=1;
			}
			if(flag)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}

	system("pause");
	return 0;
}