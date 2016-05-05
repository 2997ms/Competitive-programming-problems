#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

stack <int> o_sta;
int p,q,r,s,t;
string test;
int len,i;

void push1(char a)
{
	switch (a)
	{
	case 'p':
		o_sta.push(p);
		break;
	case 'q':
		o_sta.push(q);
		break;
	case 'r':
		o_sta.push(r);
		break;
	case 's':
		o_sta.push(s);
		break;
	case 't':
		o_sta.push(t);
		break;
	default:
		break;
	}
}

void cal(char a)
{
	int temp1,temp2;
	switch (a)
	{
	case 'N':
		temp1=o_sta.top();
		o_sta.pop();
		temp1=!temp1;
		o_sta.push(temp1);
		break;
	case 'K':
		temp1=o_sta.top();
		o_sta.pop();
		temp2=o_sta.top();
		o_sta.pop();
		temp1=temp1&temp2;
		o_sta.push(temp1);
		break;
	case 'A':
		temp1=o_sta.top();
		o_sta.pop();
		temp2=o_sta.top();
		o_sta.pop();
		temp1=temp1|temp2;
		o_sta.push(temp1);
		break;
	case 'C':
		temp1=o_sta.top();
		o_sta.pop();
		temp2=o_sta.top();
		o_sta.pop();
		temp1=temp1-temp2;
		if(temp1==1)
			o_sta.push(0);
		else
			o_sta.push(1);
		break;
	case 'E':
		temp1=o_sta.top();
		o_sta.pop();
		temp2=o_sta.top();
		o_sta.pop();
		temp1=temp1-temp2;
		if(temp1==0)
			o_sta.push(1);
		else
			o_sta.push(0);
		break;
	default:
		break;
	}
}

bool solve()
{
	for(p=0;p<=1;p++)
	{
		for(q=0;q<=1;q++)
		{
			for(r=0;r<=1;r++)
			{
				for(s=0;s<=1;s++)
				{
					for(t=0;t<=1;t++)
					{
						for(i=len-1;i>=0;i--)
						{
							if(test[i]=='p'||test[i]=='q'||test[i]=='r'||test[i]=='s'||test[i]=='t')
								push1(test[i]);
							else
								cal(test[i]);
						}
						if(o_sta.top()==0) 
							return false;
					}
				}
			}
		}
	}
	return true;
}
int main()
{
	while(cin>>test)
	{
		if(test=="0")
			break;
		len=test.length();

		if(solve())
		{
			cout<<"tautology"<<endl;
		}
		else
		{
			cout<<"not"<<endl;
		}
	}
	//system("pause");
	return 0;
}
