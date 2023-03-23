#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int N, L, fruit[MAX], answer, idx = 0;

int main() {
	// �Է�
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; ++i)
		scanf("%d", &fruit[i]);

	// ó��
	sort(fruit, fruit + N);
	while (idx < N && fruit[idx] <= L) {
		++L;
		++idx;
	}

	// ���
	printf("%d\n", L);

	return 0;
}