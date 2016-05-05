#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int stu[15];
string name[15];

int main()
{	
	int num,i;
	while(cin>>num)
	{
		if(num==-1)
			break;
		int temp1,temp2,temp3;
		for(i=1;i<=num;i++)
		{
			cin>>temp1>>temp2>>temp3>>name[i];
			stu[i]=temp1*temp2*temp3;
		}
		int min_n=700,min_x;
		int max_n=-1,max_x;
		
		for(i=1;i<=num;i++)
		{
			if(stu[i]>max_n)
			{
				max_x=i;
				max_n=stu[i];
			}
			if(stu[i]<min_n)
			{
				min_x=i;
				min_n=stu[i];
			}
		}
		cout<<name[max_x]<<" took clay from "<<name[min_x]<<"."<<endl;
	}
	return 0;
}
