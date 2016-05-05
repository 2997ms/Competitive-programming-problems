#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,fenzi,fenmu,fenzi1,fenmu1;
	char op;
	while(scanf("%d/%d%c%d/%d",&a,&b,&op,&c,&d)!=EOF)
	{
	      if(op=='+')
		  {
			  fenmu=b*d;
			  fenzi=a*d+b*c;
			  if(fenzi==0)
			  {
				  cout<<'0'<<endl;
				  continue;
			  }
			  if(fenmu==1)
			  {
				  cout<<fenzi<<endl;
			      continue;
			  }
			  fenzi1=fenzi;
			  fenmu1=fenmu;
			  for(int count=2;count<=fenzi&&count<fenmu;count++)
			  {
				  while(fenzi1%count==0&&fenmu1%count==0)
				  {
					  fenzi1=fenzi1/count;
					  fenmu1=fenmu1/count;
				  }
			  }
			  if(fenmu1==1)
				  cout<<fenzi1<<endl;
			  else
			  cout<<fenzi1<<'/'<<fenmu1<<endl;
		  }
		  else
		  {
			  fenmu=b*d;
			  fenzi=a*d-b*c;
			  if(fenzi==0)
			  {
				  cout<<'0'<<endl;
				  continue;
			  }
			  if(fenmu==1)
			  {
				  cout<<fenzi<<endl;
				  continue;
			  }
			  fenzi1=fenzi;
			  fenmu1=fenmu;
			  for(int count=2;count<=abs(fenzi)&&count<fenmu;count++)
			  {
				  while(abs(fenzi1)%count==0&&fenmu1%count==0)
				  {
					  fenzi1=fenzi1/count;
					  fenmu1=fenmu1/count;
				  }
			  }
			  if(fenmu1==1)
			  {
				  cout<<fenzi1<<endl;
			  }
			  else
			  cout<<fenzi1<<'/'<<fenmu1<<endl;
		  }
		  }
	return 0;
}
		  

