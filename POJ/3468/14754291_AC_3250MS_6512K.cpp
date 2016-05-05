#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

struct no
{
	int L, R;
	long long sum;
	long long inc;
	no * pLeft;
	no * pRight;
}Tree[200002];

int n, q;
long long ncount;

void BuildTree(no * pRoot, int L, int R)
{
	pRoot->L = L;
	pRoot->R = R;

	pRoot->sum = 0;
	pRoot->inc = 0;

	if (L != R)
	{
		ncount++;
		pRoot->pLeft = Tree + ncount;

		ncount++;
		pRoot->pRight = Tree + ncount;

		BuildTree(pRoot->pLeft, L, (L + R) / 2);
		BuildTree(pRoot->pRight, (L + R) / 2 + 1, R);
	}
}

void Insert(no *pRoot, int i, long long h)
{
	if (pRoot->L == i&&pRoot->R == i)
	{
		pRoot->sum = h;
		return;
	}
	pRoot->sum += h;

	if (i <= (pRoot->L + pRoot->R) / 2)
	{
		Insert(pRoot->pLeft, i, h);
	}
	else
	{
		Insert(pRoot->pRight, i, h);
	}
}

void Add(no *pRoot, int s, int e, long long val)
{
	if (pRoot->L == s&&pRoot->R == e)
	{
		pRoot->inc += val;
		return;
	}

	pRoot->sum += val*(e - s + 1);

	if (e <= (pRoot->L + pRoot->R) / 2)
	{
		Add(pRoot->pLeft, s, e,val);
	}
	else if (s >= (pRoot->L + pRoot->R) / 2 + 1)
	{
		Add(pRoot->pRight, s, e,val);
	}
	else
	{
		Add(pRoot->pLeft, s, (pRoot->L + pRoot->R) / 2,val);
		Add(pRoot->pRight, (pRoot->L + pRoot->R) / 2 + 1, e,val);
	}
}

long long Query(no *pRoot, int s, int e)
{
	if (pRoot->L == s&&pRoot->R == e)
	{
		return pRoot->sum + (pRoot->R - pRoot->L + 1)*pRoot->inc;
	}
	pRoot->sum = pRoot->sum + (pRoot->R - pRoot->L + 1)*pRoot->inc;

	Add(pRoot->pLeft, pRoot->L, (pRoot->L + pRoot->R) / 2, pRoot->inc);
	Add(pRoot->pRight, (pRoot->L + pRoot->R) / 2 + 1, pRoot->R, pRoot->inc);
	pRoot->inc = 0;
	
	if (e <= (pRoot->L + pRoot->R) / 2)
	{
		return Query(pRoot->pLeft, s, e);
	}
	else if (s >= (pRoot->L + pRoot->R) / 2 + 1)
	{
		return Query(pRoot->pRight, s, e);
	}
	else
	{
		return Query(pRoot->pLeft, s, (pRoot->L + pRoot->R) / 2) + Query(pRoot->pRight, (pRoot->L + pRoot->R) / 2 + 1, e);
	}
}

int main()
{
	int i, h, s, e;
	long long val;
	char oper;

	scanf("%d%d", &n, &q);
	BuildTree(Tree, 1, n);
	ncount = 0;

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &h);
		Insert(Tree, i, h);
	}
	for (i = 1; i <= q; i++)
	{
		cin >> oper;
		if (oper == 'Q')
		{
			cin >> s >> e;
			printf("%lld\n", Query(Tree, s, e));
		}
		else if (oper == 'C')
		{
			cin >> s >> e >> val;
			Add(Tree, s, e, val);
		}
	}
	return 0;
}
