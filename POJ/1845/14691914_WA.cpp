#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
#define M 9901

long long p[50005];
int prime[50005];

void isprime()
{
	int cnt = 0, i, j;
	memset(prime, 0, sizeof(prime));
	
	for (i = 2; i < 50005; i++)
	{
		if (prime[i] == 0)
		{
			p[++cnt] = i;
			for (j = 2 * i; j < 50005;j=j+i)
			{
				prime[j] = 1;
			}
		}
	}
}
long long getresult(long long A,long long n,long long k)
{
	long long b = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			b = (b*A)%k;
		}
		n = n >> 1;
		A = (A*A)%k;
	}
	return b;
}
void solve(long long A, long long B)
{
	int i;
	long long ans = 1;
	for (i = 1; p[i] * p[i] <= A; i++)
	{
		if (A%p[i] == 0)
		{
			int num = 0;
			while (A%p[i] == 0)
			{
				num++;
				A = A / p[i];
			}
			long long m = (p[i] - 1) * 9901;
			ans *= (getresult(p[i], num*B + 1, m) + m - 1) / (p[i] - 1);
			ans %= 9901;
		}
	}
	if (A > 1)
	{
		long long m = 9901 * (A - 1);
		ans *= (getresult(A, B + 1, m) + m - 1) / (A - 1);
		ans %= 9901;
	}
	cout << ans << endl;
}

int main()
{	
	long long A, B;
	
	isprime();
	
	while (cin >> A >> B)
	{
		  solve(A, B);
	}
	return 0;
}
