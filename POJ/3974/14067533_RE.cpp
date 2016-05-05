#include <iostream>
#include <cstring>
using namespace std;

char test[1000005];
char testarr[1000005<<1];
int p[1000005<<1];
int min(int a,int b){
	return a>b?b:a;
}
int result()
{
	int maxLine = 0, maxresult = 0;
	int count;
	int ID =1,i=0;
	int lentemp = strlen(test);
	int len = (lentemp<<1);

	for(count=0;count<(1000005<<1);count++)
	{
		testarr[count]= '#';
		p[count]=0;
	}
	for(count =0;count<lentemp;count++)
	{
		testarr[((count+1)<<1)-1]=test[count];
	}
	for(i=1;i<len;i++)
	{
		if(i<maxLine)
		{
			p[i]= min(p[2*ID-1],maxLine-i);
		}
		else
		{
			p[i]=1;
		}
		while(testarr[i+p[i]] ==testarr[i-p[i]])
		{			
			p[i]++;
		}
		if(i+p[i]>maxLine)
		{
			   maxLine = i+p[i];
			   ID=i;
		}
		if(p[i]>maxresult)
			maxresult =p[i];
	}
	return maxresult-1;

}

int main()
{
	int count =1;
	
	while(true)
	{
		cin>>test;
		
		if(strcmp(test,"END")==0)
		{
			break;		
		}
		else
		{
			cout<<"Case "<<count<<": "<<result()<<endl;
		}
		count++;

	}
	
	return 0;
}