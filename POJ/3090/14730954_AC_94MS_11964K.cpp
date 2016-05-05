#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define Max 1000005  
int euler[Max];
long long a[Max];

void Init() {
	euler[1] = 1;
	for (int i = 2; i<Max; i++)
		euler[i] = i;
	for (int i = 2; i<Max; i++)
		if (euler[i] == i)
			for (int j = i; j<Max; j += i)
				euler[j] = euler[j] / i*(i - 1);//先进行除法是为了防止中间数据的溢出   
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	Init();

	long long i, n, test;
	a[1] = 3;
	a[2] = 5;
	for (i = 3; i <= 1000000; i++)
	{
		a[i] = a[i - 1] + euler[i]*2;
	}

	int num;
	cin >> num;
	while (num--)
	{
		test = 1;
		while (cin >> n)
		{
			cout << test << " " << n << " " << a[n] << endl;
			test++;
		}
	}
	//system("pause");
	return 0;
}
