#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int xx,yy,yue;
int a,b,d;
vector <int> x_value;
vector <int> y_value;

void ex_gcd(int a,int b, int &xx,int &yy)
{
	if(b==0)
	{
		xx=1;
		yy=0;
		yue=a;
	}
	else
	{
		ex_gcd(b,a%b,xx,yy);

		int t=xx;
		xx=yy;
		yy=t-(a/b)*yy;

	}
}

void cal()
{
	int i;
	int min=abs(x_value[0])+abs(y_value[0]);
	int min_x=abs(x_value[0]),min_y=abs(y_value[0]);

	for(i=1;i<2;i++)
	{
		if(abs(x_value[i])+abs(y_value[i])==min)
		{
			if((abs(x_value[i])*a+abs(y_value[i])*b)<(min_x*a+min_y*b))
			{
				min_x=abs(x_value[i]);
				min_y=abs(y_value[i]);
			}
		}
		if(abs(x_value[i])+abs(y_value[i])<min)
		{
			min=abs(x_value[i])+abs(y_value[i]);
			min_x=abs(x_value[i]);
			min_y=abs(y_value[i]);
		}
	}
	cout<<min_x<<" "<<min_y<<endl;
}

int main()
{
	while(cin>>a>>b>>d)
	{
		if(a==0 && b==0 && d==0)
			break;
		ex_gcd(a,b,xx,yy);

		x_value.clear();
		y_value.clear();

		xx=xx*(d/yue);
		yy=yy*(d/yue);

		int r=a/yue;
		yy=(yy%r+r)%r;
		int xx0,yy0=yy;
		xx0=(d-yy*b)/a;
		x_value.push_back(xx0);
		y_value.push_back(yy);

		r=b/yue;
		xx=(xx%r+r)%r;
		x_value.push_back(xx);
		yy=(d-xx*a)/b;
		y_value.push_back(yy);
		cal();
	}

	return 0;
}
