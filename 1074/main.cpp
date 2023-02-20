#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int N, r, c;
int calc(int N, int r, int c) {
	if (N == 0) return 0;
	return 2 * (r % 2) + (c % 2) + 4 * calc(N - 1, r / 2, c / 2);
}

int main() {
	scanf("%d %d %d", &N, &r, &c);
	printf("%d\n", calc(N, r, c));

	return 0;
}