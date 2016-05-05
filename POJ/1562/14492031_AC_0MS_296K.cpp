#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int row,col;
char value[110][110];
int met[110][110];

void dfs(int i,int j)
{
	met[i][j]=1;
	if(met[i-1][j-1]==0&&value[i-1][j-1]=='@')
		dfs(i-1,j-1);
	if(met[i-1][j]==0&&value[i-1][j]=='@')
		dfs(i-1,j);
	if(met[i-1][j+1]==0&&value[i-1][j+1]=='@')
		dfs(i-1,j+1);
	if(met[i][j+1]==0&&value[i][j+1]=='@')
		dfs(i,j+1);
	if(met[i+1][j+1]==0&&value[i+1][j+1]=='@')
		dfs(i+1,j+1);
	if(met[i+1][j]==0&&value[i+1][j]=='@')
		dfs(i+1,j);
	if(met[i+1][j-1]==0&&value[i+1][j-1]=='@')
		dfs(i+1,j-1);
	if(met[i][j-1]==0&&value[i][j-1]=='@')
		dfs(i,j-1);
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i,j;
	while(cin>>row>>col)
	{
		if(row+col==0)
			break;

		memset(met,0,sizeof(met));

		for(i=1;i<=row;i++)
		{
			cin>>value[i]+1;
		}
		int result=0;
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if(value[i][j]=='@'&&met[i][j]==0)
				{
					dfs(i,j);
					result++;
				}
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
