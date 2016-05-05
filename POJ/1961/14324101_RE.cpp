#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

char a[105];
int next1[105];

void cal()
{
	int len = strlen(a);
	int i,j=-1;
	next1[0]=-1;
	for(i=0;i<len;)
	{
		if(j==-1||a[i]==a[j])
		{
			i++;
			j++;
			
			/*if(a[i]==a[j])
			{
				next1[i]=next1[j];
			}
			else
			{
				next1[i]=j;
			}*/
			next1[i]=j;
		}
		else
		{
			j=next1[j];
		}
	}
}

int main()
{
	int len,count=1;
	while(cin>>len)
	{
		if(len==0)
			break;
		
		memset(next1,0,sizeof(next1));

		cin>>a;
		cal();

		int i;
		
		cout<<"Test case #"<<count++<<endl;
		for(i=2;i<=strlen(a);i++)
		{
			if(i%(i-next1[i])==0 && (i)/(i-next1[i])>=2)
				cout<<i<<" "<<(i)/(i-next1[i])<<endl;
		}
		
		cout<<endl;
	}

	return 0;
}
