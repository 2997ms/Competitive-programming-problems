#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;
//1 up
//4 down

int num[15];
int Test,i,j,flag[15],sum=0;
string left_s[5],right_s[5],bala[5];
char temp_c;


void solve()
{
	if(bala[1]=="up")
	{
		for(j=0;j<left_s[1].length();j++)
		{
			if(left_s[1][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"heavy."<<endl;
				return ;
			}
		}
		for(j=0;j<right_s[1].length();j++)
		{
			if(right_s[1][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"light."<<endl;
				return;
			}
		}
	}
	if(bala[2]=="up")
	{
		for(j=0;j<left_s[2].length();j++)
		{
			if(left_s[2][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"heavy."<<endl;
				return;
			}
		}
		for(j=0;j<right_s[2].length();j++)
		{
			if(right_s[2][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"light."<<endl;
				return;
			}
		}
	}
	if(bala[3]=="up")
	{
		for(j=0;j<left_s[3].length();j++)
		{
			if(left_s[3][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"heavy."<<endl;
				return ;
			}
		}
		for(j=0;j<right_s[3].length();j++)
		{
			if(right_s[3][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"light."<<endl;
				return ;
			}
		}
	}

	if(bala[1]=="down")
	{
		for(j=0;j<left_s[1].length();j++)
		{
			if(left_s[1][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"light."<<endl;
				return;
			}
		}
		for(j=0;j<right_s[1].length();j++)
		{
			if(right_s[1][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"heavy."<<endl;
				return ;
			}
		}
	}
	if(bala[2]=="down")
	{
		for(j=0;j<left_s[2].length();j++)
		{
			if(left_s[2][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"light."<<endl;
				return;
			}
		}
		for(j=0;j<right_s[2].length();j++)
		{
			if(right_s[2][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"heavy."<<endl;
				return ;
			}
		}
	}
	if(bala[3]=="down")
	{
		for(j=0;j<left_s[3].length();j++)
		{
			if(left_s[3][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"light."<<endl;
				return;
			}
		}
		for(j=0;j<right_s[3].length();j++)
		{
			if(right_s[3][j]==temp_c)
			{
				sum=1;
				cout<<temp_c<<" is the counterfeit coin and it is ";
				cout<<"heavy."<<endl;
				return ;
			}
		}
	}
}

bool pend()
{
	int pend_flag=0;
	if(bala[1]=="up")
	{
		for(j=0;j<left_s[1].length();j++)
		{
			if(left_s[1][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		for(j=0;j<right_s[1].length();j++)
		{
			if(right_s[1][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		if(pend_flag==0)
			return false;
	}
	if(bala[2]=="up")
	{
		for(j=0;j<left_s[2].length();j++)
		{
			if(left_s[2][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		for(j=0;j<right_s[2].length();j++)
		{
			if(right_s[2][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		if(pend_flag==0)
			return false;
	}
	if(bala[3]=="up")
	{
		for(j=0;j<left_s[3].length();j++)
		{
			if(left_s[3][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		for(j=0;j<right_s[3].length();j++)
		{
			if(right_s[3][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		if(pend_flag==0)
			return false;
	}

	if(bala[1]=="down")
	{
		for(j=0;j<left_s[1].length();j++)
		{
			if(left_s[1][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		for(j=0;j<right_s[1].length();j++)
		{
			if(right_s[1][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		if(pend_flag==0)
			return false;
	}
	if(bala[2]=="down")
	{
		for(j=0;j<left_s[2].length();j++)
		{
			if(left_s[2][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		for(j=0;j<right_s[2].length();j++)
		{
			if(right_s[2][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		if(pend_flag==0)
			return false;
	}
	if(bala[3]=="down")
	{
		for(j=0;j<left_s[3].length();j++)
		{
			if(left_s[3][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		for(j=0;j<right_s[3].length();j++)
		{
			if(right_s[3][j]==temp_c)
			{
				pend_flag=1;
			}
		}
		if(pend_flag==0)
			return false;
	}
	return true;
}
int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	cin>>Test;

	while(Test--)
	{
		memset(flag,0,sizeof(flag));
		memset(num,0,sizeof(num));
		sum=0;

		for(i=1;i<=3;i++)
		{
			cin>>left_s[i]>>right_s[i]>>bala[i];
		}
		for(temp_c='A';temp_c<='L';temp_c++)
		{
			if(bala[1]=="even")
			{
				for(j=0;j<left_s[1].length();j++)
				{
					if(left_s[1][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
				for(j=0;j<right_s[1].length();j++)
				{
					if(right_s[1][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
			}
			if(bala[2]=="even")
			{
				for(j=0;j<left_s[2].length();j++)
				{
					if(left_s[2][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
				for(j=0;j<right_s[2].length();j++)
				{
					if(right_s[2][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
			}
			if(bala[3]=="even")
			{
				for(j=0;j<left_s[3].length();j++)
				{
					if(left_s[3][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
				for(j=0;j<right_s[3].length();j++)
				{
					if(right_s[3][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
			}

			if(bala[1]=="up")
			{
				for(j=0;j<left_s[1].length();j++)
				{
					if(left_s[1][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] += 4;
					}
				}
				for(j=0;j<right_s[1].length();j++)
				{
					if(right_s[1][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] += 3;
					}
				}
			}
			if(bala[2]=="up")
			{
				for(j=0;j<left_s[2].length();j++)
				{
					if(left_s[2][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] += 4;
					}
				}
				for(j=0;j<right_s[2].length();j++)
				{
					if(right_s[2][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] += 3;
					}
				}
			}
			if(bala[3]=="up")
			{
				for(j=0;j<left_s[3].length();j++)
				{
					if(left_s[3][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] +=4;
					}
				}
				for(j=0;j<right_s[3].length();j++)
				{
					if(right_s[3][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] +=3;
					}
				}
			}

			if(bala[1]=="down")
			{
				for(j=0;j<left_s[1].length();j++)
				{
					if(left_s[1][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] +=3;//chen
					}
				}
				for(j=0;j<right_s[1].length();j++)
				{
					if(right_s[1][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] +=4;//qing
					}
				}
			}
			if(bala[2]=="down")
			{
				for(j=0;j<left_s[2].length();j++)
				{
					if(left_s[2][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] +=3;//chen
					}
				}
				for(j=0;j<right_s[2].length();j++)
				{
					if(right_s[2][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] +=4;//qing
					}
				}
			}
			if(bala[3]=="down")
			{
				for(j=0;j<left_s[3].length();j++)
				{
					if(left_s[3][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] +=3;//chen
					}
				}
				for(j=0;j<right_s[3].length();j++)
				{
					if(right_s[3][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A'] +=4;//qing
					}
				}
			}
		}
		for(temp_c='A';temp_c<='L';temp_c++)
		{
			num[flag[temp_c-'A']]++;
		}
		for(i=0;i<=12;i++)
		{
			if(num[i]==1 && i!=7 && i!=10 && i!=11)
			{
				for(temp_c='A';temp_c<='L';temp_c++)
				{
					if(flag[temp_c-'A']==i)
					{
						if(pend())
						{
							solve();
						}
					}
				}
			}
		}
	}
	return 0;
}
