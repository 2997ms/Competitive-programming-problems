#include <iostream>  
#include <vector>  
#include <string>  
#include <cstring>  
using namespace std;  

vector <int> node[20005];  
int result,result_num;  
int used[20005];  
int sum[20005];
int max_i[20005];

int dfs(int i)  
{  
	used[i]=1;  

	int k;  
	int flag=0;
	sum[i]=0;

	for(k=0;k<node[i].size();k++)  
	{  
		if(!used[node[i][k]])  
		{  
			int temp = dfs(node[i][k]);
			sum[i]=sum[i]+temp;

			if(temp>max_i[i])
			{
				max_i[i]=temp;
			}
		}  
	}
	used[i]=0;	
	return sum[i]+1;
}  
int main()  
{  
	int count,N;

	cin>>count;

	while(count--)
	{
		cin>>N;
		int i,flag;
		result=20005;

		memset(node,0,sizeof(node));
		memset(used,0,sizeof(used));
		for(i=1;i<=N-1;i++)
		{
			int node1,node2;
			cin>>node1>>node2;

			node[node1].push_back(node2);
			node[node2].push_back(node1);
		}
		
		dfs(1);

		for(i=1;i<=N;i++)
		{
			if(max(max_i[i],sum[1]-sum[i])<result)
			{
				result=i;
				result_num=max(max_i[i],sum[1]-sum[i]);
			}
		}

		cout<<result<<" "<<result_num<<endl;
	}

	return 0;  
}  
