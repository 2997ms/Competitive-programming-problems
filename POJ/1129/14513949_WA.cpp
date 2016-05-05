#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

vector<int>diff[28]; 
int flag[28];
string con[28];
int num;

void solve()
{
	int i,j,k,temp,max_n=0;
	for(i=0;i<num;i++)
	{
		temp=con[i].length();
		if(temp==2)continue;
		
		int flag_k;
		for(k=0;k<num;k++)
		{
			flag_k=0;
			for(j=2;j<temp;j++)
			{
				if(k==con[i][j]-'A')
				{
					flag_k=1;
					break;
				}
			}
			if(!flag_k)break;
		}
		flag[i]=k;
		max_n=max(k,max_n);
	}
	if(max_n==0)
		cout<<"1 channel needed."<<endl;
	else
		cout<<max_n+1<<" channels needed."<<endl;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	int i;
	while(cin>>num)
	{
		if(num==0)
			break;
		for(i=0;i<26;i++)
		{
			diff[i].clear();
			flag[i]=0;
		}

		for(i=0;i<num;i++)
			cin>>con[i];
		solve();
	}
	return 0;
}
