#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>  
#include <map>
#pragma warning(disable:4996)  
using namespace std;

int n,i,j,len;
map<string,int> tele;
map<string,int>::iterator s,e;
string dic;

char change(char x)
{
	if(x>='A'&&x<='C')
	{
		return '2';
	}
	else if(x>='D'&&x<='F')
	{
		return '3';
	}
	else if(x>='G'&&x<='I')
	{
		return '4';
	}
	else if(x>='J'&&x<='L')
	{
		return '5';
	}
	else if(x>='M'&&x<='O')
	{
		return '6';
	}
	else if(x>='P'&&x<='S')
	{
		return '7';
	}
	else if(x>='T'&&x<='V')
	{
		return '8';
	}
	else if(x>='W'&&x<='Y')
	{
		return '9';
	}
	else
	{
		return x;
	}
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	cin>>n;
	
	tele.clear();
	for(i=1;i<=n;i++)
	{
		cin>>dic;
		len=dic.length();
		
		string str="";
		for(j=0;j<len;j++)
		{
			if(((dic[j]>='A' && dic[j]<='Y') || ((dic[j]>='0' && dic[j]<='9'))) && (dic[j]!='Q'))
			{
				str += change(dic[j]);
			}
		}
		tele[str]++;
	}
	bool flag = false;
	for(s=tele.begin();s!=tele.end();s++)
	{
		if(s->second>=2)
		{
			flag=true;
			for(i=0; i < s->first.length();i++)
			{
				cout<<s->first[i];
				if(i==2)
				{
					cout<<'-';
				}
			}
			cout<<" "<<s->second<<endl;
		}
	}
	if(!flag)
		cout<<"No duplicates. "<<endl;
	//system("pause");
	return 0;
}