#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	unsigned int r, x, y;

	while(scanf_s("%x,%d,%d", &r, &x, &y) == 3) {
		r = r & (~(1<<x));
		r = r | (1<<y);
		r = r | (1<<(y-1));
		r = r & (~(1<<y-2));
		printf("%x\n", r);
	}

	return 0;
}