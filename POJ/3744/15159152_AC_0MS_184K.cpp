#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>;
#include <set>
#include <map>
using namespace std;

typedef long long ll;

#define INF 0x3fffffff
#define REP(i, n) for (int i=0;i<n;++i)
#define REP1(i, n) for (int i=1;i<=n;++i)

const ll mod = 1e9 + 7;
const int maxn = 2;

int n, num[20];
double p;
struct Matrix
{
	double mat[maxn][maxn];
	Matrix()
	{
		memset(mat, 0, sizeof(mat));
	}
	void clear() { memset(mat, 0, sizeof(mat)); }
	friend Matrix operator *(const Matrix &A, const Matrix &B);
	friend Matrix operator ^(Matrix A, int n);
};

Matrix operator *(const Matrix &A, const Matrix &B)
{
	Matrix ret;
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
		{
			for (int k = 0; k < maxn; k++)
			{
				ret.mat[i][j] = ret.mat[i][j] + (A.mat[i][k] * B.mat[k][j]);
			}
		}
	}
	return ret;
}

Matrix operator ^(Matrix A, int n)
{
	Matrix ret;
	for (int i = 0; i < maxn; i++)
	{
		ret.mat[i][i] = 1;
	}
	for (; n; n >>= 1, A = A*A)
		if (n & 1)
			ret = ret*A;
	return ret;
}
void input()
{
	REP1(i, n)
	{
		scanf("%d", &num[i]);
	}
	sort(num + 1, num + n + 1);
}

void solve()
{
	if (num[1] == 1)
	{
		puts("0.0000000");
		return;
	}

	Matrix res1, res2;
	res2.mat[0][0] = p;
	res2.mat[0][1] = 1 - p;
	res2.mat[1][0] = 1;
	res2.mat[1][1] = 0;

	double ans = 1;
	REP1(i, n)
	{
		if (num[i] == num[i - 1])continue;
		res1 = (res2 ^ (num[i] - num[i - 1] - 1));
		ans = ans*(1 - res1.mat[0][0]);
	}
	printf("%.7f\n", ans);
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	while (scanf("%d%lf", &n, &p) != EOF)
	{
		input();
		solve();
	}
	return 0;
}