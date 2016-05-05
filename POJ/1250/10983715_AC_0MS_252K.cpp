#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int state[30]={0},bed[30]={0},count1,count2,count3,count4,flag,result,max;
	string con;
	while(cin>>count1&&count1)
	{
		cin>>con;
		result=0;
		max=-1;
		for(count2=0;con[count2];count2++)
		{
			flag=0;
			state[con[count2]-'A'+1]++;
			for(count3=1;count3<=count1;count3++)
			{
				if(!bed[count3])
				{
					if(state[con[count2]-'A'+1]==1)
					{
						bed[count3]=con[count2]-'A'+1;//3代表有床住的 4代表有床住的走了
						state[con[count2]-'A'+1]=3;
						break;
					}
				}
				if(state[bed[count3]]==4)
				{
					for(count4=1;count4<=26;count4++)
					{
						if(state[count4]==1)
						{
							bed[count3]=con[count2]-'A'+1;
							state[con[count2]-'A'+1]=3;
							flag=1;
							break;
						}
					}
				}
				if(flag)
					break;
			}
                for(count4=1;count4<=26;count4++)
				{
					if(state[count4]==2)
						result++;
				}
				if(result>max)
					max=result;
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
		memset(bed,0,sizeof(bed));
	}
	return 0;
}
