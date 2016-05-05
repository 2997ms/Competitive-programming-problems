#include <iostream>
using namespace std;

int DP[200][200];
int value[200][200];
int used[200][200];

int R,C;

void dfs(int i,int j)
{
	int max_num=0;

	used[i][j] = 1;

	if(i>1 && value[i][j]> value[i-1][j])
	{
		if(!used[i-1][j])
			dfs(i-1,j);
		max_num = max(DP[i-1][j],max_num);
	}

	if(i<C && value[i][j]> value[i+1][j])
	{
		if(!used[i+1][j])
			dfs(i+1,j);
		max_num = max(DP[i+1][j],max_num);
	}

	if(j>1 && value[i][j]> value[i][j-1])
	{
		if(!used[i][j-1])
			dfs(i,j-1);
		max_num = max(DP[i][j-1],max_num);
	}

	if(j<R && value[i][j]> value[i][j+1])
	{
		if(!used[i][j+1])
			dfs(i,j+1);
		max_num = max(DP[i][j+1],max_num);
	}

	DP[i][j]=max_num+1;

}

int main()
{
	int i,j;
	cin>>R>>C;

	for(i=1;i<=R;i++)
	{
		for(j=1;j<=C;j++)
		{
			cin>>value[i][j];
		}
	}
	memset(used,0,sizeof(used));
	memset(DP,0,sizeof(DP));

	for(i=1;i<=R;i++)
	{
		for(j=1;j<=C;j++)
		{
			if(!used[i][j])
				dfs(i,j);
		}
	}
	int max_num=0;
	for(i=1;i<=R;i++)
	{
		for(j=1;j<=C;j++)
		{
			if(DP[i][j]>max_num)
				max_num = DP[i][j];
		}
	}
	cout<<max_num<<endl;


	return 0;
}