#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int state[30]={0},count1,count2,count3,result,max;
	string con;
	while(cin>>count1&&count1)
	{
		cin>>con;
		result=0;
		max=-1;
		for(count2=0;con[count2];count2++)
		{
			state[con[count2]-'A'+1]=!state[con[count2]-'A'+1];
			for(count3=1;count3<=26;count3++)
			{
				if(state[count3])
				{
					result++;
				}
				if(result-count1>max)
					max=result-count1;
			}
			result=0;
		}
		if(max<=0)
		{
			cout<<"All customers tanned successfully."<<endl;
		}
		else
		{
		cout<<max<<" customer(s) walked away."<<endl;
		}
		memset(state,0,sizeof(state));
	}
	return 0;
}
				



