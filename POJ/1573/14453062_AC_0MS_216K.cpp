#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

enum{ E,N,W,S };   
int map_f[20][20];
char call[20][20];
int move_x[5]={0,-1,0,1};  
int move_y[5]={1,0,-1,0}; 
int X,Y,start,i,cur_x,cur_y,flag;

void solve()
{
	int temp;

	cur_x = 1;
	cur_y = start;
	map_f[cur_x][cur_y]=1;

	while(1)
	{
		if(flag)
			break;
		if(call[cur_x][cur_y]=='E')
		{
			temp=map_f[cur_x][cur_y];
			cur_x = cur_x + move_x[E];
			cur_y = cur_y + move_y[E];

			if(cur_x<=0 || cur_y<=0 || cur_x>X || cur_y>Y)
			{
				flag=1;
				cout<<temp<<" step(s) to exit"<<endl;
			}
			else if(map_f[cur_x][cur_y])
			{
				flag=1;
				cout<<map_f[cur_x][cur_y]-1<<" step(s) before a loop of "<<temp-map_f[cur_x][cur_y]+1<<" step(s)"<<endl;
			}
			else
			{
				map_f[cur_x][cur_y]=temp+1;
			}
		}
		else if(call[cur_x][cur_y]=='N')
		{
			temp=map_f[cur_x][cur_y];
			cur_x = cur_x + move_x[N];
			cur_y = cur_y + move_y[N];

			if(cur_x<=0 || cur_y<=0 || cur_x>X || cur_y>Y)
			{
				flag=1;
				cout<<temp<<" step(s) to exit"<<endl;
			}
			else if(map_f[cur_x][cur_y])
			{
				flag=1;
				cout<<map_f[cur_x][cur_y]-1<<" step(s) before a loop of "<<temp-map_f[cur_x][cur_y]+1<<" step(s)"<<endl;
			}
			else
			{
				map_f[cur_x][cur_y]=temp+1;
			}
		}
		else if(call[cur_x][cur_y]=='W')
		{
			temp=map_f[cur_x][cur_y];
			cur_x = cur_x + move_x[W];
			cur_y = cur_y + move_y[W];

			if(cur_x<=0 || cur_y<=0 || cur_x>X || cur_y>Y)
			{
				flag=1;
				cout<<temp<<" step(s) to exit"<<endl;
			}
			else if(map_f[cur_x][cur_y])
			{
				flag=1;
				cout<<map_f[cur_x][cur_y]-1<<" step(s) before a loop of "<<temp-map_f[cur_x][cur_y]+1<<" step(s)"<<endl;
			}
			else
			{
				map_f[cur_x][cur_y]=temp+1;
			}
		}
		else if(call[cur_x][cur_y]=='S')
		{
			temp=map_f[cur_x][cur_y];
			cur_x = cur_x + move_x[S];
			cur_y = cur_y + move_y[S];

			if(cur_x<=0 || cur_y<=0 || cur_x>X || cur_y>Y)
			{
				flag=1;
				cout<<temp<<" step(s) to exit"<<endl;
			}
			else if(map_f[cur_x][cur_y])
			{
				flag=1;
				cout<<map_f[cur_x][cur_y]-1<<" step(s) before a loop of "<<temp-map_f[cur_x][cur_y]+1<<" step(s)"<<endl;
			}
			else
			{
				map_f[cur_x][cur_y]=temp+1;
			}
		}
	}

}

int main()
{

	while(cin>>X>>Y>>start)
	{
		if(!(X+Y+start))
			break;

		memset(map_f,0,sizeof(map_f));
		flag=0;

		for(i=1;i<=X;i++)
		{
			cin>>call[i]+1;
		}
		solve();
	}


	return 0;
}
