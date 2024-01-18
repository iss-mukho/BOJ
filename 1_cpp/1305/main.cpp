#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 1000000;

int L, i, j;
char S[MAX];
int table[MAX];

int main() {
	scanf("%d", &L);
	scanf("%s", &S);

	i = 0;
	for (j = 1; j <= L; ++j) {
		while (i > 0 && S[i] != S[j]) {
			i = table[i - 1];
		}

		if (S[i] == S[j]) {
			table[j] = ++i;
		}
	}

	printf("%d\n", L - table[L - 1]);

	return 0;
}
