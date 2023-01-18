#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int N, L, fruit[MAX], answer, idx = 0;

int main() {
	// 입력
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; ++i)
		scanf("%d", &fruit[i]);

	// 처리
	sort(fruit, fruit + N);
	while (idx < N && fruit[idx] <= L) {
		++L;
		++idx;
	}

	// 출력
	printf("%d\n", L);

	return 0;
}