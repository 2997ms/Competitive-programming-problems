#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct R
{
	int x;
	int y;
	int dir;
}Robot[110];

enum{ E,N,W,S };
enum{ L=1,R=-1};
int map_f[200][200];
int move_x[5]={1,0,-1,0};
int move_y[5]={0,1,0,-1};
int Test,X,Y,Robot_n,Q,i,flag;
string temp;

void solve()
{
	int cal_n,cishu,k;
	string manu;
	cin>>cal_n>>manu>>cishu;

	if(flag==0)
		return;

	if(manu=="F")
	{
		map_f[Robot[cal_n].x][Robot[cal_n].y]=0;

		for(k=1;k<=cishu;k++)
		{
			Robot[cal_n].x = Robot[cal_n].x + move_x[Robot[cal_n].dir];
			Robot[cal_n].y = Robot[cal_n].y + move_y[Robot[cal_n].dir];

			if(Robot[cal_n].x <=0 || Robot[cal_n].y <=0 || Robot[cal_n].x >X || Robot[cal_n].y >Y)
			{
				flag=0;
				cout<<"Robot "<<cal_n<<" crashes into the wall"<<endl;
				break;
			}
			else if(map_f[Robot[cal_n].x][Robot[cal_n].y])
			{
				flag=0;
				cout<<"Robot "<<cal_n<<" crashes into robot "<<map_f[Robot[cal_n].x][Robot[cal_n].y]<<endl;
				break;
			}
		}
		map_f[Robot[cal_n].x][Robot[cal_n].y]=cal_n;
	}
	else if(manu=="L")
	{
		Robot[cal_n].dir = (Robot[cal_n].dir + L*cishu)%4;
	}
	else if(manu=="R")
	{
		Robot[cal_n].dir = (Robot[cal_n].dir + (R*cishu)%4 + 4)%4;
	}
}

int main()
{

	cin>>Test;

	while(Test--)
	{
		flag=1;
		memset(map_f,0,sizeof(map_f));

		cin>>X>>Y;
		cin>>Robot_n>>Q;

		for(i=1;i<=Robot_n;i++)
		{
			cin>>Robot[i].x>>Robot[i].y;
			if(map_f[Robot[i].x][Robot[i].y])
			{
				flag=0;
				cout<<"Robot "<<i<<" crashes into robot "<<map_f[Robot[i].x][Robot[i].y]<<endl;
			}
			else
			{
				map_f[Robot[i].x][Robot[i].y]=i;
			}

			cin>>temp;
			if(temp=="E")
				Robot[i].dir=E;
			else if(temp=="N")
				Robot[i].dir=N;
			else if(temp=="W")
				Robot[i].dir=W;
			else if(temp=="S")
				Robot[i].dir=S;
		}
		for(i=1;i<=Q;i++)
		{
			solve();
		}
		if(flag)
			cout<<"OK"<<endl;
	}
	//system("pause");
	return 0;
}
