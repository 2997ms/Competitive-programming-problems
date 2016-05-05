#include <iostream>
using namespace std;
bool map[4][4];
int ans=33;
void init()
{
	char c;
	for (int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{		
			cin>>c;
		}
	    if(c=='b')
			map[i][j]=true;
		else
			map[i][j]=false;
	}
}
void turn(int x,int y)
{
	if (x>=0&&x<=3&&y>=0&&y<=3)
	{
		map[x][y]=!map[x][y];
        return;
	}
}
void flip(int pos)
{
	int i=pos/4;
	int j=pos%4;
	turn(i,j);
	turn(i+1,j);
	turn(i-1,j);
	turn(i,j+1);
	turn(i,j-1);
}
bool finnished()
{
	int sum=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			sum+=map[i][j];
	if(sum%16)
		return false;
	else 
		return true;
}
void dfs(int pos,int step)
{
	if(finnished())
		if(ans>step)
		{
			ans=step;
			return;
		}
	if(pos>=16)
		return;
	dfs(pos+1,step);
	flip(pos);
	dfs(pos+1,step+1);
	flip(pos);
}
int main()
{
	init();
	dfs(0,0);
	if(ans==33)
		cout<<"Impossible"<<endl;
	else
		cout<<ans;
	return 0;
}
