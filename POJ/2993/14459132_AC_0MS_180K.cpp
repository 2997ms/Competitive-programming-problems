#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const string temp="+---+---+---+---+---+---+---+---+";
string test[20];
string cal[5];

int i,len;
char row,col;

int main()
{

	test[1]="|...|:::|...|:::|...|:::|...|:::|";
	test[2]="|:::|...|:::|...|:::|...|:::|...|";
	test[3]="|...|:::|...|:::|...|:::|...|:::|";
	test[4]="|:::|...|:::|...|:::|...|:::|...|";
	test[5]="|...|:::|...|:::|...|:::|...|:::|";
	test[6]="|:::|...|:::|...|:::|...|:::|...|";
	test[7]="|...|:::|...|:::|...|:::|...|:::|";
	test[8]="|:::|...|:::|...|:::|...|:::|...|";
	
	cin>>cal[0];
	cin>>cal[1];
	cin>>cal[3];
	cin>>cal[2];

	len=cal[1].length();
	for(i=0;i<len;i++)
	{
		if(cal[1][i]==',')continue;
		else if(cal[1][i]=='K')
		{
			row=cal[1][i+1];
			col=cal[1][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='K';
			i=i+2;
		}
		else if(cal[1][i]=='Q')
		{
			row=cal[1][i+1];
			col=cal[1][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='Q';
			i=i+2;
		}
		else if(cal[1][i]=='R')
		{
			row=cal[1][i+1];
			col=cal[1][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='R';
			i=i+2;
		}
		else if(cal[1][i]=='B')
		{
			row=cal[1][i+1];
			col=cal[1][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='B';
			i=i+2;
		}
		else if(cal[1][i]=='N')
		{
			row=cal[1][i+1];
			col=cal[1][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='N';
			i=i+2;
		}
		else if(cal[1][i]>='a'&&cal[1][i]<='h')
		{
			row=cal[1][i];
			col=cal[1][i+1];

			test[9-(col-'0')][(row-'a')*4+2]='P';
			i=i+1;
		}
	}

	len=cal[2].length();
	for(i=0;i<len;i++)
	{
		if(cal[2][i]==',')continue;
		else if(cal[2][i]=='K')
		{
			row=cal[2][i+1];
			col=cal[2][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='k';
			i=i+2;
		}
		else if(cal[2][i]=='Q')
		{
			row=cal[2][i+1];
			col=cal[2][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='q';
			i=i+2;
		}
		else if(cal[2][i]=='R')
		{
			row=cal[2][i+1];
			col=cal[2][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='r';
			i=i+2;
		}
		else if(cal[2][i]=='B')
		{
			row=cal[2][i+1];
			col=cal[2][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='b';
			i=i+2;
		}
		else if(cal[2][i]=='N')
		{
			row=cal[2][i+1];
			col=cal[2][i+2];

			test[9-(col-'0')][(row-'a')*4+2]='n';
			i=i+2;
		}
		else if(cal[2][i]>='a'&&cal[2][i]<='h')
		{
			row=cal[2][i];
			col=cal[2][i+1];

			test[9-(col-'0')][(row-'a')*4+2]='p';
			i=i+1;
		}
	}

	cout<<temp<<endl;
	for(i=1;i<=8;i++)
	{
		cout<<test[i]<<endl;
		cout<<temp<<endl;
	}

	return 0;
}
