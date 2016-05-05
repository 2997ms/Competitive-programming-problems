#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int num[1030];

int main()
{
	int Test,N,Q,i;
	cin>>Test;
	while(Test--)
	{
		cin>>N>>Q;
		for(i=0;i<N;i++)
			cin>>num[i];
		for(i=1;i<=Q;i++)
			 next_permutation(num,num+N);
		for(i=0;i<N;i++)
			cout<<num[i]<<" ";
		cout<<endl;
	}

	return 0;
}