#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#define MY_MIN 99999999
#define MY_MAX -99999999

struct no
{
	int L, R;//区间起点和终点
	int nMin, nMax;//本区间的最小值和最大值
	no *pLeft, *pRight;
};

int nMax, nMin;
no Tree[1000000];
int ncount = 0;

void BuildTree(no *pRoot, int L, int R)
{
	pRoot->L = L;
	pRoot->R = R;

	pRoot->nMin = MY_MIN;
	pRoot->nMax = MY_MAX;

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

void Insert(no *pRoot, int i, int v)
{
	if (pRoot->L == i&&pRoot->R == i)
	{
		pRoot->nMin = pRoot->nMax = v;
		return;
	}
	pRoot->nMin = min(v, pRoot->nMin);
	pRoot->nMax = max(v, pRoot->nMax);

	if (i <= (pRoot->L + pRoot->R) / 2)
	{
		Insert(pRoot->pLeft, i, v);
	}
	else
	{
		Insert(pRoot->pRight, i, v);
	}
}

void Query(no * pRoot, int s, int e)
{
	if (pRoot->nMin >= nMin&&pRoot->nMax <= nMax)
		return;
	
	if (s == pRoot->L&&e == pRoot->R)
	{
		nMin = min(pRoot->nMin, nMin);
		nMax = max(pRoot->nMax, nMax);
		return;
	}

	if (e <= (pRoot->L + pRoot->R) / 2)
	{
		Query(pRoot->pLeft,s,e);
	}
	else if (s >= (pRoot->L + pRoot->R) / 2 + 1)
	{
		Query(pRoot->pRight,s,e);
	}
	else
	{
		Query(pRoot->pLeft, s, (pRoot->L + pRoot->R) / 2);
		Query(pRoot->pRight, (pRoot->L + pRoot->R) / 2+1, e);
	}
}

int n, q;

int main()
{
	int i, h, s, e;
	
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
		scanf("%d%d", &s, &e);
		
		nMax = MY_MAX;
		nMin = MY_MIN;

		Query(Tree, s, e);
		printf("%d\n", nMax - nMin);
	}
	return 0;
}
