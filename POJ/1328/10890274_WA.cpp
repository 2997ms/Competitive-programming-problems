#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 struct ss
 { 
	 double x,y; 
 }a[1005];
 int cmp(ss x,ss y) 
 { 
	 if(x.x==y.x)
		 return x.y<y.y;
	 else return x.x<y.x;
 }
int main()
{
	int island,count,result=0,flag=0,R,island_x[1005],island_y[1005];
	double radar;
	cin>>island>>R;
	while(island!=0||R!=0)
	{
		for(count=1;count<=island;count++)
		{
			cin>>island_x[count]>>island_y[count];
			if(island_y[count]>R||island_y[count]<0||R<=0)
			{
				result=-1;
			}
			else
			{
				a[count].x=island_x[count]-sqrt(1.0*(R*R-island_y[count]*island_y[count]));
				a[count].y=island_x[count]+sqrt(1.0*(R*R-island_y[count]*island_y[count]));
			}				
		}
		if(result!=-1)
		{
		    sort(a+1,a+island+1,cmp);
			radar=a[1].y;result=1;
			for(count=2;count<=island;count++)
			{
				if(a[count].x>radar)
				{
					result++;
					radar=a[count].y;
				}			
				else if(a[count].y<radar)
				{
					radar=a[count].y;
				}
			}
			cout<<"Case "<<++flag<<': '<<result<<endl;
			result=0;
		}
		else
		{
			cout<<"Case "<<++flag<<': '<<result<<endl;
			result=0;
		}
		cin>>island>>R;
	}
	return 0;
}


