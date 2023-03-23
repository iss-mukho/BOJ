#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 40;
int f[MAX + 1];
int n, a = 0, b = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		++a;
		return 1;
	}
	else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
	f[1] = f[2] = 1;

	for (int i = 3; i <= n; ++i) {
		++b;
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

int main() {
	scanf("%d", &n);
	
	fib(n);
	fibonacci(n);

	printf("%d %d\n", a, b);

	return 0;
}