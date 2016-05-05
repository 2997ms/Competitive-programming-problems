#pragma warning(disable:4996)
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x333f3f3f
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))

const ll mod = 10007;
const int maxn = 20007;
const double PI = acos(-1.0);

struct big {
	typedef long long ll;
	typedef ll INT;
	static const int S_n = 30, D_n = 9, DM = 100000000;
	static const INT S = INT(1) << S_n, _S = S - 1;
	static const int SIZE = 55;
	INT a[SIZE];
	int len, tag;
	big() { len = 1; memset(a, 0, sizeof a); }
	big(const INT &x) { len = 1; memset(a, 0, sizeof a); *this = x; }
	inline void cln() { memset(a, 0, sizeof(INT)*(len + 1)); len = 1; tag = 0; }
	inline void fix() { for (; len>1 && !a[len]; --len); }
	void M(big &a, big &b, big &c) {
		if (b.tag) { b.tag = 0; P(a, b, c); b.tag = 1; return; }
		if (a.tag) { a.tag = 0; P(a, b, c); a.tag = 1; c.tag = 1; return; }
		c.cln();
		int flag = 0, i = 1;
		big *x = &a, *y = &b;
		if (a<b) flag = 1, swap(x, y);
		for (; i <= x->len; ++i) {
			c.a[i] += x->a[i] - y->a[i];
			if (c.a[i]<0) c.a[i] += S, --c.a[i + 1];
		}
		c.len = i;
		c.fix();
		c.tag = flag;
	}
	void P(big &a, big &b, big &c) {
		if (b.tag) { b.tag = 0; M(a, b, c); b.tag = 1; return; }
		if (a.tag) { a.tag = 0; M(b, a, c); a.tag = 1; return; }
		c.cln();
		int i = 1, l = max(a.len, b.len); INT k = 0;
		for (; i <= l || k; ++i) {
			c.a[i] = a.a[i] + b.a[i] + k;
			if (c.a[i] >= S) k = c.a[i] >> S_n, c.a[i] &= _S;
			else k = 0;
		}
		c.len = i;
		c.fix();
	}
	void T(big &a, big &b, big &c) {
		c.cln();
		for (int i = 1; i <= a.len; ++i) {
			for (int j = 1; j <= b.len; ++j) {
				int pos = i + j - 1;
				c.a[pos] += a.a[i] * b.a[j];
				if (c.a[pos] >= S) c.a[pos + 1] += c.a[pos] >> S_n, c.a[pos] &= _S;
			}
		}
		c.len = a.len + b.len;
		c.fix();
		c.tag = a.tag^b.tag;
		if (c.a[1] == 0 && c.len == 1) c.tag = 0;
	}
	void D(big &a, INT b, big &c) {
		c.cln(); INT t = 0;
		int flag = b<0;
		if (b<0) b = -b;
		for (int i = len; i; --i) {
			c.a[i] = (a.a[i] + t) / b;
			t = ((a.a[i] + t) % b) << S_n;
		}
		c.tag = a.tag^flag;
		c.len = len;
		c.fix();
		if (c.a[1] == 0 && c.len == 1) c.tag = 0;
	}
	void D(big &a, big &b, big &c) {
		c.cln();
		int flag1 = a.tag, flag2 = b.tag;
		a.tag = b.tag = 0;
		big l, r = a, mid, TP, ONE = (INT)1;
		while (l <= r) {
			P(l, r, TP); D(TP, 2, mid);
			T(mid, b, TP);
			if (TP <= a) P(mid, ONE, l);
			else M(mid, ONE, r);
		}
		M(l, ONE, c);
		a.tag = flag1;
		b.tag = flag2;
		c.tag = a.tag^b.tag;
		if (c.a[1] == 0 && c.len == 1) c.tag = 0;
	}
	big sqrt() {
		big l, r = *this, mid, TP, ONE = (INT)1;
		while (l <= r) {
			P(l, r, TP); D(TP, 2, mid);
			T(mid, mid, TP);
			if (TP <= *this) P(mid, ONE, l);
			else M(mid, ONE, r);
		}
		M(l, ONE, TP);
		return TP;
	}
	bool operator< (const big &b) const {
		if (b.tag && !tag) return 0;
		if (!b.tag && tag) return 1;
		if (len != b.len) return (len<b.len) ^ tag;
		for (int i = len; i; --i) {
			if (a[i]<b.a[i]) return 1 ^ tag;
			else if (a[i]>b.a[i]) return 0 ^ tag;
		}
		return 0;
	}
	big& operator= (INT b) {
		cln(); len = 0;
		if (b == 0) { len = 1; return *this; }
		if (b<0) tag = 1, b = -b;
		for (; b; a[++len] = b&_S, b >>= S_n);
		return *this;
	}
	big& operator= (const big &x) {
		cln();
		memcpy(a, x.a, sizeof(INT)*(x.len + 1));
		len = x.len, tag = x.tag;
		return *this;
	}
	big operator+ (const big &x) { static big b, c; b = x; P(*this, b, c); return c; }
	big operator- (const big &x) { static big b, c; b = x; M(*this, b, c); return c; }
	big operator* (const big &x) { static big b, c; b = x; T(*this, b, c); return c; }
	big operator/ (const big &x) { static big b, c; b = x; D(*this, b, c); return c; }
	big operator/ (const INT &x) { static big c; static INT b; b = x; D(*this, b, c); return c; }
	big operator% (const big &x) { return *this - *this / x*x; }
	big operator% (const INT &x) { return *this - *this / x*x; }
	big& operator+= (const big &x) { static big b, c; b = x; P(*this, b, c); return *this = c; }
	big& operator-= (const big &x) { static big b, c; b = x; M(*this, b, c); return *this = c; }
	big& operator*= (const big &x) { static big b, c; b = x; T(*this, b, c); return *this = c; }
	big& operator/= (const big &x) { static big b, c; b = x; D(*this, b, c); return *this = c; }
	big& operator/= (const INT &x) { static big c; static INT b; b = x; D(*this, b, c); return *this = c; }
	big& operator%= (const big &x) { return *this = *this%x; }
	big& operator++ () { return *this += 1; }
	big operator++ (int) { static big c; c = *this; ++*this; return c; }
	big& operator-- () { return *this -= 1; }
	big operator-- (int) { static big c; c = *this; --*this; return c; }
	bool operator> (const big &x) const { return x<*this; }
	bool operator== (const big &x) const { return x <= *this&&x >= *this; }
	bool operator<= (const big &x) const { return !(x<*this); }
	bool operator>= (const big &x) const { return !(x>*this); }
	bool operator!= (const big &x) const { return !(*this == x); }
	void P() {
		static INT p[(D_n + 1)*SIZE];
		if (tag) putchar('-');
		big t = *this;
		int top = 0;
		if (t.len == 1 && t.a[1] == 0) p[++top] = 0;
		for (; !(t.len == 1 && t.a[1] == 0); p[++top] = (t%DM).a[1], t /= DM);
		printf("%d", (int)p[top]);
		char od[8]; od[0] = '%'; od[1] = '0';
		sprintf(od + 2, "%d", D_n - 1);
		int l = strlen(od); od[l] = 'd'; od[l + 1] = '\0';
		for (int i = top - 1; i; --i) printf(od, (int)p[i]);
	}
};
big val[105];
void init()
{
	val[1] = 1;
	int i, j, k;
	for (i = 2; i <= 100; i++)
	{
		val[i] = val[i - 1] * (4 * i - 2) / (i + 1);
	}
}

int t;
void solve()
{
	val[t].P();
	printf("\n");
}

int main()
{
	init();
	while (scanf("%d", &t) != EOF)
	{
		if (t == -1)
			break;
		solve();
	}
	return 0;
}
