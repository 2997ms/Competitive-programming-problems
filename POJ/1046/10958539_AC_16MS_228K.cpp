#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a[17],b[17],c[17],count1,a1,b1,c1,finala,finalb,finalc;
	double result,min;
	for(count1=1;count1<=16;count1++)
	{
		cin>>a[count1]>>b[count1]>>c[count1];
	}
	while(cin>>a1>>b1>>c1&&(a1!=-1||b1!=-1||c1!=-1))
	{
		min=10000000;
		for(count1=1;count1<=16;count1++)
		{
     		result=sqrt((float)(a1-a[count1])*(a1-a[count1])+(b1-b[count1])*(b1-b[count1])+(c1-c[count1])*(c1-c[count1]));
			if(result<min)
			{
				min=result;
				finala=a[count1];finalb=b[count1];finalc=c[count1];
			}
		}
		cout<<'('<<a1<<','<<b1<<','<<c1<<") maps to ("<<finala<<','<<finalb<<','<<finalc<<')'<<endl;
	}
	return 0;
}
