#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	double Vs,R,C,w;
	int n,i;
	cin>>Vs>>R>>C>>n;

	for(i=1;i<=n;i++)
	{
		cin>>w;
		printf("%.3f",sqrt(1.0/(1+C*C*w*w*R*R))*C*w*R*Vs);
		cout<<endl;
	}
    return 0;
}