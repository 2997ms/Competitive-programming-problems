#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#pragma warning(disable:4996)
using namespace std;

double n,m;

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	cin>>n;
	while(cin>>m)
	{
		if(m==999)
			break;
		cout<<fixed<<setprecision(2)<<m-n<<endl;
		n=m;
	}
	cout<<"End of Output"<<endl;
	return 0;
}
