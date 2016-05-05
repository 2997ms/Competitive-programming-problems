#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int c[52840];
int s[52840];
int n[52840];
int num;

int length(int x)
{
	int sum=0;
	while (x != 0)
	{
		x /= 10;
		sum++;
	}
	return sum;
}

void init()
{
	int i;
	
	c[0] = 0;
	s[0] = 0;

	for (i = 1; i <= 52835; i++)
	{
		n[i] = length(i);
	}
	for (i = 1; i <= 52835; i++)
	{
		c[i] = c[i - 1] + n[i];
	}
	for (i = 1; i <= 52835; i++)
	{
		s[i] = s[i - 1] + c[i];
	}
}

bool check(int mid)
{

	return true;
}
int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	init();
	
	int Test,left,pos;
	int i;
	scanf("%d", &Test);
	
	while(Test--)
	{
		scanf("%d", &num);

		//string k = "112123123412345123456123456712345678123456789123456789101234567891011";
		//int temp = k.length();

		left = lower_bound(s + 1, s + 52834, num) - (s + 1);
		pos = num - s[left];

		left= lower_bound(c + 1, c + 52834, pos) - (c + 1);
		pos = pos - c[left];

		left++;
		pos = n[left] - pos +1;

		i = 1;
		while (i < pos)
		{
			left /= 10;
			i++;
		}
		cout << left % 10<<endl;
	}
	//2147457664
	//2147483647
	return 0;
}
