#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int N = 120005;

bool prime[N];
int p[N], cnt, len;
int number[100];

void isprime()
{
	cnt = 0;
	memset(prime, true, sizeof(prime));
	for (int i = 2; i<N; i++)
	{
		if (prime[i])
		{
			p[cnt++] = i;
			for (int j = i + i; j<N; j += i)
				prime[j] = false;
		}
	}
}
//9592
bool check(int x)
{
	bool flag = 0;
	int i, result = 0;

	for (i = 0; i < len; i++)
	{
		result = (result * 10000 + number[i]) % x;
	}
	return result == 0;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	isprime();

	char num[10000];
	int k, i, j, temp, count, flag;

	while (cin >> num >> k)
	{
		if (k == 0 && num[0] == 0)
			break;
		memset(number, 0, sizeof(number));
		temp = strlen(num);
		len = 0;
		for (i = temp-1; i >=0 ; i = i - 4)
		{
			if (i - 3 >= 0)
			{
				number[len] = (num[i - 3]-'0') * 1000 + (num[i - 2]-'0') * 100 + (num[i - 1]-'0') * 10 + num[i]-'0';
			}
			else if (i - 2 >= 0)
			{
				number[len] =  (num[i - 2]-'0') * 100 + (num[i - 1]-'0') * 10 + num[i] - '0';
			}
			else if(i - 1 >= 0)
			{
				number[len] =  (num[i - 1]-'0') * 10 + num[i] - '0';
			}
			else
			{
				number[len] =  num[i] - '0';
			}
			len++;
		}
		flag = 0;
		for (i = 0; p[i] < k; i++)
		{
			if (check(p[i]))
			{
				cout << "BAD" << " " << p[i] << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "GOOD" << endl;
		}
	}
	//system("pause");
	return 0;
}
