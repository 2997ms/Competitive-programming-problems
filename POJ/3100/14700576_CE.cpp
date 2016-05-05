#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int A,N,i,temp1,temp2;
	while(cin>>A>>N)
	{
		if(A==0&&N==0)
			break;
		for(i=1;;i++)
		{
			temp1=(int)pow(i,N);
			temp2=(int)pow(i+1,N);
			if(temp1<=A&&temp2>=A)
			{
				break;
			}
		}
		if(abs(temp1-A)>abs(temp2-A))
		{
			cout<<i+1<<endl;
		}
		else
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
