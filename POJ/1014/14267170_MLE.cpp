#include <iostream>
#include <vector>
using namespace std;

int flag[120000];
vector<int> allready;

int main()
{
	int count=0;
	while(1)
	{
		count++;
		memset(flag,0,sizeof(flag));
		allready.clear();

		int a1,a2,a3,a4,a5,a6;
		cin>>a1>>a2>>a3>>a4>>a5>>a6;

		if(a1 ==0&& a2==0 &&a3==0&&a4==0&&a5==0&&a6==0)
		{
			break;
		}

		cout<<"Collection #"<<count<<":"<<endl;

		int i;

		int result = a1+a2*2+a3*3+a4*4+a5*5+a6*6;

		if(result%2)
		{
			cout<<"Can't be divided."<<endl;
		}
		else
		{
			result /= 2;
			for(i=1;i<=a1;i++)
			{
				flag[i]=1;
				allready.push_back(i);
			}
			if(a1>=result)
			{
				cout<<"Can be divided."<<endl;
				continue;
			}
			int j;
			int s = allready.size();
			for(i=1;i<=a2;i++)
			{
				for(j = 0;j<= s;j++)
				{
					flag[allready[j]+i*2]=1;
					allready.push_back(allready[j]+i*2);
				}
			}
			if(a1+a2*2>=result)
			{
				if(flag[result])
				{
					cout<<"Can be divided."<<endl;
					continue;
				}
				else
				{
					cout<<"Can't be divided."<<endl;
					continue;
				}
			}

			s = allready.size();
			for(i=1;i<=a3;i++)
			{
				for(j = 0;j<= s;j++)
				{
					flag[allready[j]+i*3]=1;
					allready.push_back(allready[j]+i*3);
				}
			}
			if(a1+a2*2+a3*3>=result)
			{
				if(flag[result])
				{
					cout<<"Can be divided."<<endl;
					continue;
				}
				else
				{
					cout<<"Can't be divided."<<endl;
					continue;
				}
			}

			s = allready.size();
			for(i=1;i<=a4;i++)
			{
				for(j = 0;j<= s;j++)
				{
					flag[allready[j]+i*4]=1;
					allready.push_back(allready[j]+i*4);
				}
			}
			if(a1+a2*2+a3*3+a4*4>=result)
			{
				if(flag[result])
				{
					cout<<"Can be divided."<<endl;
					continue;
				}
				else
				{
					cout<<"Can't be divided."<<endl;
					continue;
				}
			}

			s = allready.size();
			for(i=1;i<=a5;i++)
			{
				for(j = 0;j<= s;j++)
				{
					flag[allready[j]+i*5]=1;
					allready.push_back(allready[j]+i*5);
				}
			}
			if(a1+a2*2+a3*3+a4*4+a5*5>=result)
			{
				if(flag[result])
				{
					cout<<"Can be divided."<<endl;
					continue;
				}
				else
				{
					cout<<"Can't be divided."<<endl;
					continue;
				}
			}

			s = allready.size();
			for(i=1;i<=a6;i++)
			{
				for(j = 0;j<= s;j++)
				{
					flag[allready[j]+i*6]=1;
					allready.push_back(allready[j]+i*6);
				}
			}

			if(flag[result])
			{
				cout<<"Can be divided."<<endl;
				continue;
			}
			else
			{
				cout<<"Can't be divided."<<endl;
				continue;
			}

		}

	}
	return 0;
}