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
	double dis=0;
	int h,m,s,v=0,pre_h=0,pre_m=0,pre_s=1;
	char temp;

	while(scanf("%d:%d:%d",&h,&m,&s)==3)
	{
		scanf("%c",&temp);
		if(temp==' ')
		{
			dis +=(double)v*((h-pre_h)*3600+(m-pre_m)*60+(s-pre_s))/3600;
			scanf("%d",&v);
		}
		else
		{
			dis +=(double)v*((h-pre_h)*3600+(m-pre_m)*60+(s-pre_s))/3600;
			printf("%02d:%02d:%02d %.2f km\n",h,m,s,dis);
		}
		pre_h=h;
		pre_m=m;
		pre_s=s;
	}
	return 0;
}
