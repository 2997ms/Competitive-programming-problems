#include <iostream>
using namespace std;
int findmin(int m)
{
	int count,countm=0,flag[5]={0},wang[5],result,sum=0;
	if(m<1000)
	{
		countm++;
		if(m<100)
			countm++;
		if(m<10)
			countm++;
	}
	wang[1]=m%10;
	result=m/10;
	wang[2]=result%10;
	result=result/10;
	wang[3]=result%10;
	result=result/10;
	wang[4]=result%10;
	for(count=1;count<=4-countm;count++)
	{
		result=-1;
		if(result<wang[1]&&!flag[1])result=wang[1];
		if(result<wang[2]&&!flag[2])result=wang[2];
		 if(result<wang[3]&&!flag[3])result=wang[3];
		if(result<wang[4]&&!flag[4])result=wang[4];
		if(result==wang[1]&&!flag[1]){flag[1]++;sum=sum*10+wang[1];}
		else if(result==wang[2]&&!flag[2]){flag[2]++;sum=sum*10+wang[2];}
		else if(result==wang[3]&&!flag[3]){flag[3]++;sum=sum*10+wang[3];}
		else if(result==wang[4]&&!flag[4]){flag[4]++;sum=sum*10+wang[4];}
	}
	return sum;
}
int findmax(int m)
{
	int count,flag[5]={0},wang[5],result,sum=0;
	wang[1]=m%10;
	result=m/10;
	wang[2]=result%10;
	result=result/10;
	wang[3]=result%10;
	result=result/10;
	wang[4]=result%10;
	for(count=1;count<=4;count++)
	{
		result=10;
		if(result>wang[1]&&!flag[1])result=wang[1];
		if(result>wang[2]&&!flag[2])result=wang[2];
		if(result>wang[3]&&!flag[3])result=wang[3];
		if(result>wang[4]&&!flag[4])result=wang[4];
		if(result==wang[1]&&!flag[1]){flag[1]++;sum=sum*10+wang[1];}
		else if(result==wang[2]&&!flag[2]){flag[2]++;sum=sum*10+wang[2];}
		else if(result==wang[3]&&!flag[3]){flag[3]++;sum=sum*10+wang[3];}
		else if(result==wang[4]&&!flag[4]){flag[4]++;sum=sum*10+wang[4];}
	}
	return sum;
}

int main()
{
	int oper,cha=-1,count=0,m,n;
	while(cin>>oper&&oper!=-1)
	{
		cha=-1;
		cout<<"N="<<oper<<':'<<endl;
		for(count=0;;count++)
		{
			m=findmin(oper);
			n=findmax(oper);
			if((count==0&&m==n)||(count==0&&oper<1000)||(count==0&&oper>9999))
			{
				cout<<"No!!"<<endl;
				break;
			}
			cout<<m<<'-'<<n<<'='<<m-n<<endl;
			oper=m-n;
			m=findmin(oper);
			n=findmax(oper);
			if(m-n==0||m-n==6174)
			{	
				cout<<m<<'-'<<n<<'='<<m-n<<endl;
				cout<<"Ok!! "<<count+2<<" times"<<endl;
				break;
			}
		}
	}
	return 0;
}


			



