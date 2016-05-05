#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

typedef struct peral{
	int dp1;
	int dp2;
	int value;
}Node;

struct peral P[105];

bool cmp(Node t,Node s)
{
	return t.value<s.value;
}

//前i种珍珠的数量
//搞到第i种珍珠为止，花的钱
//第i中珍珠的单价
int num;

int main()
{
	int Test,i;
	cin>>Test;
	
	while(Test--)
	{
		cin>>num;
		for(i=1;i<=num;i++)
		{
			cin>>P[i].dp1>>P[i].value;
		}
		sort(P+1,P+num+1,cmp);
		for(i=1;i<=num;i++)
		{
			if(i==1)
			{
			  P[i].dp2=(P[i].dp1+10)*P[i].value;	
			}
			else
			{
				if(P[i-1].dp2+(P[i].dp1+10)*P[i].value>
					(P[i-1].dp1+P[i].dp1+10)*P[i].value)
				{
					P[i].dp2=(P[i-1].dp1+P[i].dp1+10)*P[i].value;
					P[i].dp1=P[i].dp1+P[i-1].dp1;

				}
				else
				{
					P[i].dp2=P[i-1].dp2+(P[i].dp1+10)*P[i].value;
					P[i].dp1=P[i].dp1+P[i-1].dp1;
				}
			}
		}
		cout<<P[num].dp2<<endl;
	}
	return 0;
}
