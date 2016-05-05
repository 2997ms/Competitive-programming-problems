#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main()
{


	int Test,i,j,flag[15],sum=0;
	string left[5],right[5],bala[5];
	char temp_c;
	cin>>Test;

	while(Test--)
	{
		memset(flag,0,sizeof(flag));
		for(i=1;i<=3;i++)
		{
			cin>>left[i]>>right[i]>>bala[i];
		}
		for(temp_c='A';temp_c<='K';temp_c++)
		{
			if(temp_c=='J')
				sum++;
			if(bala[1]=="even")
			{
				for(j=0;j<left[1].length();j++)
				{
					if(left[1][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
				for(j=0;j<right[1].length();j++)
				{
					if(right[1][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
			}
			if(bala[2]=="even")
			{
				for(j=0;j<left[2].length();j++)
				{
					if(left[2][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
				for(j=0;j<right[2].length();j++)
				{
					if(right[2][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
			}
			if(bala[3]=="even")
			{
				for(j=0;j<left[3].length();j++)
				{
					if(left[3][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
				for(j=0;j<right[3].length();j++)
				{
					if(right[3][j]==temp_c)
					{
						flag[temp_c-'A']=1;
						break;
					}
				}
			}

			if(bala[1]=="up")
			{
				for(j=0;j<left[1].length();j++)
				{
					if(left[1][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=2;//chen
					}
				}
				for(j=0;j<right[1].length();j++)
				{
					if(right[1][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=3;//qing
					}
				}
			}
			if(bala[2]=="up")
			{
				for(j=0;j<left[2].length();j++)
				{
					if(left[2][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=2;//chen
					}
				}
				for(j=0;j<right[2].length();j++)
				{
					if(right[2][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=3;//qing
					}
				}
			}
			if(bala[3]=="up")
			{
				for(j=0;j<left[3].length();j++)
				{
					if(left[3][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=2;//chen
					}
				}
				for(j=0;j<right[3].length();j++)
				{
					if(right[3][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=3;//qing
					}
				}
			}

			if(bala[1]=="down")
			{
				for(j=0;j<left[1].length();j++)
				{
					if(left[1][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=3;//chen
					}
				}
				for(j=0;j<right[1].length();j++)
				{
					if(right[1][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=2;//qing
					}
				}
			}
			if(bala[2]=="down")
			{
				for(j=0;j<left[2].length();j++)
				{
					if(left[2][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=3;//chen
					}
				}
				for(j=0;j<right[2].length();j++)
				{
					if(right[2][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=2;//qing
					}
				}
			}
			if(bala[3]=="down")
			{
				for(j=0;j<left[3].length();j++)
				{
					if(left[3][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=3;//chen
					}
				}
				for(j=0;j<right[3].length();j++)
				{
					if(right[3][j]==temp_c)
					{
						if(flag[temp_c-'A']==1)
							continue;
						else
							flag[temp_c-'A']=2;//qing
					}
				}
			}
		}
		for(temp_c='A';temp_c<='K';temp_c++)
		{
			if(flag[temp_c-'A']==1)continue;
			
			cout<<temp_c<<" is the counterfeit coin and it is ";
			
			if(flag[temp_c-'A']==2)
				cout<<"heavy."<<endl;
			else
			    cout<<"light."<<endl;
		}

	}

	return 0;
}
