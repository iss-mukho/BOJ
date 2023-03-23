#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX = 1000000;
int number[MAX + 1];
int n, A, B;
bool isYes = false;
void getSosu();
bool isSosu(int x);
void input();
void process();
void output();

int main() {
	getSosu();
	while (1) {
		scanf("%d", &n);
		if (!n)
			break;
		process();
		output();
	}

	return 0;
}
void getSosu() {
	for (int i = 2; i <= MAX; ++i) number[i] = i;

	for (int i = 2; i <= MAX; ++i) {
		if (!number[i]) continue;

		for (int j = i * 2; j <= MAX; j += i)
			number[j] = 0;
	}
}
void process() {
	for (int i = 1; i < n / 2; ++i) {
		A = i * 2 + 1;
		B = n - A;

		if (number[A] && number[B]) {
			printf("%d = %d + %d\n", n, A, B);
			isYes = true;
			break;
		}
	}
}
void output() {
	if (!isYes)
		printf("Goldbach's conjecture is wrong.\n");
	isYes = false;
}